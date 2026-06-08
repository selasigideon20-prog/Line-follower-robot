// Pinnen definiëren
const int drukknopPin = 4; // De GPIO-pin waar je fysieke knop op zit
const int ledPin = 2;      // Ingebouwde LED van de ESP32 om te testen

// Variabelen voor de timer (non-blocking met millis)
volatile bool robotMoetStoppen = false;
unsigned long stopStartTijd = 0;
const unsigned long stopDuur = 30000; // 30 seconden in milliseconden

// Variabelen voor ontbounden (debouncing) van de knop
volatile unsigned long laatsteKnopDruk = 0;
const unsigned long debounceTijd = 250; 

// Deze functie voert de ESP32 ALTIJD uit als de knop wordt ingedrukt
void IRAM_ATTR knopGedrukt() {
  unsigned long nu = millis();
  
  // Checken of het geen valse klik (noise) is
  if (nu - laatsteKnopDruk > debounceTijd) {
    if (robotMoetStoppen) {
      // Als de robot al stilstond, zorgt een nieuwe klik ervoor dat hij weer gaat rijden
      robotMoetStoppen = false;
    } else {
      // Als de robot reed, zetten we de stop-status aan en starten we de timer
      robotMoetStoppen = true;
      stopStartTijd = nu;
    }
    laatsteKnopDruk = nu;
  }
}

void setup() {
  Serial.begin(115200);
  
  // Instellen van de drukknop met ingebouwde pull-up resistor
  pinMode(drukknopPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  // De interrupt koppelen aan de knop: reageert als de knop wordt ingedrukt (FALLING)
  attachInterrupt(digitalPinToInterrupt(drukknopPin), knopGedrukt, FALLING);
  
  Serial.println("Systeem gestart. Robot is klaar om te rijden!");
}

void loop() {
  unsigned long huidigeTijd = millis();

  if (robotMoetStoppen) {
    // Checken of de 30 seconden al voorbij zijn
    if (huidigeTijd - stopStartTijd >= stopDuur) {
      Serial.println("30 seconden zijn om! Robot vertrekt weer.");
      robotMoetStoppen = false;
    } else {
      // CODE ALS DE ROBOT STILSTAAT
      digitalWrite(ledPin, HIGH); // Zet een LED aan als indicatie dat hij stopt
      Serial.print("Robot staat tijdelijk stil... Resterende seconden: ");
      Serial.println((stopDuur - (huidigeTijd - stopStartTijd)) / 1000);
      
      // HIER DE MOTOREN STOPPEN (bijv: analogWrite(motorPin, 0); )
    }
  } else {
    // CODE ALS DE ROBOT GEWOON RIJDT
    digitalWrite(ledPin, LOW);
    Serial.println("Robot volgt de lijn... (Rijden)");
    
    // HIER JE STANDAARD LIJNVOLG CODE DIE DE MOTOREN AANSTUURT
  }

  delay(500); // Dit is puur voor de Serial Monitor rustig te houden, mag straks weg
}
