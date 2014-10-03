#include "pitches.h"

// notes in the melody:
int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3,
                   NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
//int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4 };
int noteDurations[] = { 4, 4, 4, 4, 4, 4, 4 };

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
//    if (7 > thisNote) {
      int noteDuration = 500 / noteDurations[thisNote];
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

