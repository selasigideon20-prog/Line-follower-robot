
# Testen Documentatie

## Overzicht

In deze fase van het project werden verschillende onderdelen van de robot getest. Door het ontbreken van de PCB konden niet alle systemen volledig geïntegreerd getest worden.

---

## Week 3 – Basis testen

* Lijnsensoren getest en werkend bevonden
* Motoren getest (vooruit, achteruit, draaien)
* Basis lijnvolging geïmplementeerd en getest

---

## Week 6 – Deeltesten

Door het ontbreken van de PCB konden de volgende onderdelen niet volledig getest worden op de eindhardware:

* MQTT-communicatie (niet getest op eindopstelling)
* Obstakeldetectie in volledige integratie
* I2C-communicatie tussen modules
* Grafana dashboard koppeling

Wel uitgevoerd:

* Softwarelogica getest in losse modules
* Sensorwaarden individueel getest

---

## PCB Probleem

Tijdens het ontwerpen van de PCB werd een fout vastgesteld in het bestand dat naar JLCPCB werd gestuurd.

Een connector werd per ongeluk vervangen door een condensator, wat leidde tot een fout in het PCB-ontwerp.

### Gevolgen

* Onjuiste PCB-layout bij productie
* Vertraging in het productieproces
* Niet kunnen testen van volledige hardware-integratie

### Oplossing

* Fout in het schema gecorrigeerd
* PCB opnieuw gecontroleerd en aangepast
* Verbeterde versie voorbereid voor productie

---

## Week 8 – Eindtesten (gepland)

* Volledige systeemtest op PCB
* Integratie van alle modules
* Testen van MQTT + dashboard
* Testen van obstakelvermijding in realistische omgeving

---

## Conclusie

De basisfunctionaliteiten (lijnvolging en motorbesturing) zijn succesvol getest. De volledige integratie wordt uitgevoerd zodra de PCB beschikbaar is.

