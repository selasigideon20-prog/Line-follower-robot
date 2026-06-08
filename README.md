# 🚗 Line Follower Robot

## 🧠 ESP32 Autonomous Robot
Robot die lijn volgt en obstakels vermijdt.

---

## Hardware

- ESP32 (controller)
- TCRT5000 IR sensoren (lijnvolging)
- 3x HC-SR04 ultrasone sensoren (afstand)
- L298N motor driver
- 2 DC motoren
- 2x 18650 batterijen
- TP4056 (opladen)
- XL6009 (spanningsregeling)

---

## Werking
De robot werkt als volgt:

- IR sensoren detecteren de lijn
- Ultrasone sensoren meten afstand tot obstakels
- ESP32 verwerkt alle data
- L298N stuurt de motoren aan
- Robot kiest automatisch: rijden, stoppen of vermijden

---

## Software
- Arduino IDE (ESP32)
- Leest sensoren in
- Beslist beweging
- Stuurt motoren aan via L298N

---

## Aansluitingen

- IR sensoren → ESP32 GPIO pins  
- HC-SR04 → ESP32 GPIO pins  
- L298N → ESP32 + motoren  
- Batterij → TP4056 → XL6009 → systeem  

---

## Gebruik

1. Sluit alle hardware aan  
2. Upload code naar ESP32  
3. Zet robot aan  
4. Plaats op een lijn  

---

## Problemen
- Fout in PCB ontwerp (connector vervangen)
- Sensoren moesten opnieuw gekalibreerd worden
