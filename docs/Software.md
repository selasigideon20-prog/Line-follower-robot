# Software Documentatie

## Overzicht

De software van de Mercedes-Benz Auto Robot werd ontwikkeld in C++ met behulp van het Arduino Framework. De software verwerkt sensorgegevens, bestuurt de motoren en verzorgt de communicatie tussen de verschillende onderdelen van het systeem.

---

## Functionaliteiten

### Lijnvolging

De robot volgt een vooraf bepaalde lijn met behulp van de TCRT5000 IR-sensoren. Op basis van de sensorwaarden worden de motoren aangestuurd zodat de robot op het traject blijft.

### Obstakeldetectie

De HC-SR04 ultrasone sensoren meten continu de afstand tot objecten. Wanneer een obstakel wordt gedetecteerd, kan de robot stoppen of een alternatieve route zoeken.

### Stop- en Hervatfunctie

Via een drukknop kan de gebruiker de robot tijdelijk stoppen. Na een tweede druk op de knop of na een bepaalde tijd kan de robot opnieuw verder rijden.

### Batterijmonitoring

De batterijspanning wordt gecontroleerd zodat de gebruiker tijdig gewaarschuwd kan worden wanneer de batterij bijna leeg is.

### MQTT-communicatie

De robot kan sensorgegevens en statusinformatie versturen naar een centraal monitoringsysteem via MQTT.

---

## Programmastructuur

De software bestaat uit verschillende modules:

* Lijnvolging
* Obstakeldetectie
* Motorbesturing
* Batterijmonitoring
* MQTT-communicatie

Deze modules werken samen om de robot autonoom te laten functioneren.

---

## Ontwikkelomgeving

* Arduino IDE
* C++
* ESP32 Board Package
