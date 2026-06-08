# Hardware Documentatie

## Overzicht

De Mercedes-Benz Auto Robot is ontworpen om autonoom een traject te volgen, obstakels te detecteren en gegevens te verzamelen voor monitoring. De hardware bestaat uit een ESP32-microcontroller, verschillende sensoren, een motorbesturing en een voedingssysteem.

---

## Componenten

### ESP32

De ESP32 is de hoofdcontroller van de robot. Deze verwerkt de sensorgegevens, bestuurt de motoren en verzorgt de communicatie met andere systemen.

### TCRT5000 IR Sensor Array

De TCRT5000 IR-sensoren worden gebruikt voor lijnvolging. Door het verschil tussen lichte en donkere oppervlakken te detecteren kan de robot de lijn volgen.

### HC-SR04 Ultrasone Sensoren

De robot beschikt over drie HC-SR04 ultrasone sensoren. Deze meten continu de afstand tot objecten en worden gebruikt voor obstakeldetectie en botsingspreventie.

### L298N Motor Driver

De L298N motor driver stuurt de DC-motoren aan en regelt de snelheid en rijrichting van het voertuig.

### DC-Motoren

De twee DC-motoren zorgen voor de voortbeweging van de robot.

### XL6009 Buck-Boost Converter

De XL6009 converter zorgt voor een stabiele voedingsspanning voor de elektronische componenten.

### TP4056 Li-Ion Charger

De TP4056 laadmodule wordt gebruikt voor het veilig opladen van de batterijen.

### Batterij

De robot wordt gevoed door twee 18650 Li-ion batterijen die energie leveren aan alle componenten.

---

## Voedingssysteem

Het voedingssysteem bestaat uit:

* 2x 18650 Li-ion batterijen
* TP4056 laadmodule
* XL6009 Buck-Boost Converter

Dit systeem voorziet de robot van een stabiele en betrouwbare voedingsspanning.

---

## Communicatie

### GPIO

De GPIO-pinnen van de ESP32 worden gebruikt voor:

* IR-sensoren
* Ultrasone sensoren
* Motor driver
* Drukknop
* LED-indicatoren

---

## Hardware Overzicht

| Component                | Functie           |
| ------------------------ | ----------------- |
| ESP32                    | Hoofdcontroller   |
| TCRT5000 IR Sensor Array | Lijnvolging       |
| 3x HC-SR04               | Obstakeldetectie  |
| L298N Motor Driver       | Motorbesturing    |
| DC-Motoren               | Aandrijving       |
| XL6009                   | Spanningsregeling |
| TP4056                   | Batterijladen     |
| 2x 18650 Batterijen      | Voeding           |
