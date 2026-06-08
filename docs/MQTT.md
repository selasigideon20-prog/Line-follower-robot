# MQTT Documentatie

## Overzicht

De robot maakt gebruik van MQTT om real-time gegevens te versturen naar een centraal monitoringsysteem. Hierdoor kan de status van de robot op afstand worden gevolgd.

---

## MQTT Broker

De communicatie verloopt via een centrale MQTT-broker.

---

## Topics

### Telemetrie (robot → server)

* robot/battery → batterijpercentage
* robot/distance → afstand tot obstakels
* robot/status → huidige status van de robot (rijden, stoppen, fout)

### Commando’s (server → robot)

* robot/control → START, STOP, RESUME

---

## Data formaat

De gegevens worden verstuurd in JSON-formaat:

```json id="m1q8ab"
{
  "battery": 85,
  "distance": 32,
  "status": "driving"
}
```

---

## Opmerking

MQTT-communicatie kon nog niet volledig getest worden omdat de definitieve PCB nog niet beschikbaar was.

---

## Toepassing

MQTT wordt gebruikt voor:

* Realtime monitoring
* Foutdetectie
* Remote control van de robot
