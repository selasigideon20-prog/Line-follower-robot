#include <Servo.h>

// ---------------- MOTOR PINS (L298N) ----------------
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6

// ---------------- IR SENSORS ----------------
#define IR_LEFT 2
#define IR_MID 3
#define IR_RIGHT 4

// ---------------- ULTRASONIC ----------------
#define TRIG A0
#define ECHO A1

// ---------------- SERVO ----------------
Servo scanner;
#define SERVO_PIN 7

// ---------------- SETTINGS ----------------
int distanceThreshold = 15; // cm

// ---------------- SETUP ----------------
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_MID, INPUT);
  pinMode(IR_RIGHT, INPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  scanner.attach(SERVO_PIN);
  scanner.write(90);

  Serial.begin(9600);
}

// ---------------- MOTOR FUNCTIONS ----------------
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ---------------- DISTANCE FUNCTION ----------------
long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

// ---------------- OBSTACLE AVOIDANCE ----------------
void avoidObstacle() {
  stopMotors();
  delay(200);

  long leftDist, rightDist;

  // look left
  scanner.write(150);
  delay(400);
  leftDist = getDistance();

  // look right
  scanner.write(30);
  delay(400);
  rightDist = getDistance();

  scanner.write(90);
  delay(200);

  if (leftDist > rightDist) {
    left();
    delay(500);
  } else {
    right();
    delay(500);
  }
}

// ---------------- LINE FOLLOWING ----------------
void lineFollow() {
  int L = digitalRead(IR_LEFT);
  int M = digitalRead(IR_MID);
  int R = digitalRead(IR_RIGHT);

  // Adjust depending on your sensor (0 = black or 1 = black)
  // This assumes BLACK = LOW

  if (M == LOW && L == HIGH && R == HIGH) {
    forward();
  }
  else if (L == LOW) {
    left();
  }
  else if (R == LOW) {
    right();
  }
  else {
    stopMotors();
  }
}

// ---------------- LOOP ----------------
void loop() {
  long dist = getDistance();
  Serial.println(dist);

  if (dist > 0 && dist < distanceThreshold) {
    avoidObstacle();
  } else {
    lineFollow();
  }

  delay(50);
}
