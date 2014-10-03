#include "pitches.h"

const int LEDPIN = 13;
const int knockSensor = A0;
const int threshold = 1;
const int piezoPIN = 3;

int sensorReading = 0;
int knockCounter = 0;
int thisNote = 0;

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  pinMode(piezoPIN, OUTPUT);
  Serial.begin(9600);
  Serial.print("sensorReading = ");
  Serial.println(sensorReading);
  Serial.print("Knock #");
  Serial.println(knockCounter);
  Serial.print("thisNote =");
  Serial.println(thisNote);
}

void loop()
{
  sensorReading = analogRead(knockSensor);
  
  if (sensorReading >= threshold) {
      int noteDuration = 125;
      tone(3, 5*sensorReading, 250);
      digitalWrite(LEDPIN, HIGH);
//      int pauseBetweenNotes = noteDuration * 1.30;
      delay(250);
      noTone(3);
      digitalWrite(LEDPIN, LOW);
      delay(30);
      thisNote++;
      knockCounter++;
//    } else {
//      thisNote = 0;
//    }
    Serial.print("sensorReading = ");
    Serial.println(sensorReading);
    Serial.print("Knock #");
    Serial.println(knockCounter);
    Serial.print("thisNote =");
    Serial.println(thisNote);
 }

 delay(10);
}

