#include "pitches.h"

/*
c major starting from middle c (piano)
 
 #define NOTE_C4  262
 #define NOTE_D4  294
 #define NOTE_E4  330
 #define NOTE_F4  349
 #define NOTE_G4  392
 #define NOTE_A4  440
 #define NOTE_B4  494
 #define NOTE_C5  523
 
 */

// scales from http://en.wikipedia.org/wiki/File:MajorScales.svg
// and http://en.wikipedia.org/wiki/File:MinorScale.svg
/*
Major Key of C / Minor Key of A
 C, D, E, F, G, A, B, C
 Major Key of G / Minor Key of E
 G, A, B, C, D, E, F#, G
 Major Key of D / Minor Key of B
 D, E, F#, G, A, B, C#
 Major Key of A / Minor Key of F#
 A, B, C#, D, E, F#, G#
 Major Key of E / Minor Key of C#
 E, F#, G#, A, B, C#, D#
 Major Key of B / Minor Key of G#
 B, C#, D#, E, F#, G#, A#
 Major Key of F# / Minor Key of D#
 F#, G#, A#, B, C#, D#, F
 Major Key of Db / Minor Key of Bb
 C#, D#, F, F#, G#, A#, C
 Major Key of Ab / Minor Key of F
 G#, A#, C, C#, D#, F, G
 Major Key of Eb / Minor Key of C
 D#, F, G, G#, A#, C, D
 Major Key of Bb / Minor Key of G
 A#, C, D, D#, F, G, A
 Major Key of F / Minor Key of D
 F, G, A, A#, C, D, E
 */

const int LEDPIN = 13;
const int knockSensor = A0;
const int threshold = 1;
const int piezoPIN = 3;
const int debug = 1;

int sensorReading = 0;
int knockCounter = 0;
int noteCount = 0;
int playNote = 0;

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  pinMode(piezoPIN, OUTPUT);
  Serial.begin(9600);
  if (1 == debug) {
    Serial.print("sensorReading = ");
    Serial.println(sensorReading);
    Serial.print("Knock #");
    Serial.println(knockCounter);
    Serial.print("noteCount = ");
    Serial.println(noteCount);
    Serial.print("playNote = ");
    Serial.println(playNote);
  }
}

void loop()
{
  sensorReading = analogRead(knockSensor);

  if (sensorReading >= threshold) {
    //      int noteDuration = 125;

    playNote = 7 * sensorReading;  
    // hopefully no lag / race issues
    // the biggest bounces would in theory, give proc more time to cycle
    // shortest bounces would need quickest response time, so we should check those first
    if (NOTE_C4 > playNote) {
      tone(piezoPIN, NOTE_C4, 250);
      Serial.print("NOTE_C4 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_D4 > playNote) {
      tone(piezoPIN, NOTE_D4, 250);
      Serial.print("NOTE_D4 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_E4 > playNote) {
      tone(piezoPIN, NOTE_E4, 250);
      Serial.print("NOTE_E4 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_F4 > playNote) {
      tone(piezoPIN, NOTE_F4, 250);
      Serial.print("NOTE_F4 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_G4 > playNote) {
      tone(piezoPIN, NOTE_G4, 250);
      Serial.print("NOTE_G4 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_A4 > playNote) {
      tone(piezoPIN, NOTE_A4, 250);
      Serial.print("NOTE_A4 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_B4 > playNote) {
      tone(piezoPIN, NOTE_B4, 250);
      Serial.print("NOTE_B4 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_C5 > playNote) {
      tone(piezoPIN, NOTE_C5, 250);
      Serial.print("NOTE_C5 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_D5 > playNote) {
      tone(piezoPIN, NOTE_D5, 250);
      Serial.print("NOTE_D5 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_E5 > playNote) {
      tone(piezoPIN, NOTE_E5, 250);
      Serial.print("NOTE_E5 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_F5 > playNote) {
      tone(piezoPIN, NOTE_F5, 250);
      Serial.print("NOTE_F5 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_G5 > playNote) {
      tone(piezoPIN, NOTE_G5, 250);
      Serial.print("NOTE_G5 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_A5 > playNote) {
      tone(piezoPIN, NOTE_A5, 250);
      Serial.print("NOTE_A5 = ");
      Serial.println(playNote);
    } 
    else if (NOTE_B5 > playNote) {
      tone(piezoPIN, NOTE_B5, 250);
      Serial.print("NOTE_B5 = ");
      Serial.println(playNote);
    } 
    else {
      tone(piezoPIN, NOTE_C6, 250);
      Serial.print("NOTE_C6 = ");
      Serial.println(playNote);
    } 

    /*
    if (NOTE_C5 < playNote) {
     tone(piezoPIN, NOTE_C5, 250);
     } else if (NOTE_B4 < playNote) {
     tone(piezoPIN, NOTE_B4, 250);
     } else if (NOTE_A4 < playNote) {
     tone(piezoPIN, NOTE_A4, 250);
     } else if (NOTE_G4 < playNote) {
     tone(piezoPIN, NOTE_G4, 250);
     } else if (NOTE_F4 < playNote) {
     tone(piezoPIN, NOTE_F4, 250);
     } else if (NOTE_E4 < playNote) {
     tone(piezoPIN, NOTE_E4, 250);
     } else if (NOTE_D4 < playNote) {
     tone(piezoPIN, NOTE_D4, 250);
     } else {
     tone(piezoPIN, NOTE_C4, 250);
     }
     */
    //    tone(piezoPIN, 5 * sensorReading, 250);

    digitalWrite(LEDPIN, HIGH);
    //      int pauseBetweenNotes = noteDuration * 1.30;
    delay(250);
    noTone(3);
    digitalWrite(LEDPIN, LOW);
    delay(30);
    noteCount++;
    knockCounter++;
    //    } else {
    //      noteCount = 0;
    //    }
    if (1 == debug) {
      Serial.print("sensorReading = ");
      Serial.println(sensorReading);
      Serial.print("Knock #");
      Serial.println(knockCounter);
      Serial.print("noteCount = ");
      Serial.println(noteCount);
      Serial.print("playNote = ");
      Serial.println(playNote);
    }
  }

  delay(10);
}



