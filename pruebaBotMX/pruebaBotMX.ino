#include <Adafruit_NeoPixel.h>

#define LED_PIN 7
#define LED_COUNT 3

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int r,g,b;

#include "pitches.h"

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  strip.begin();
  strip.show();
  inicio();
  p_motores();
  //
  p_bocina();
  //
  p_NeoPixel();
  
}

void loop() {
  //Nacha
}

void inicio(){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);   
 }

void p_motores(){
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);

  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  analogWrite(6,255);
  analogWrite(8,0);
  analogWrite(10,0);
  analogWrite(11,255);
  delay(1000);
  //
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  analogWrite(6,0);
  analogWrite(8,255);
  analogWrite(10,255);
  analogWrite(11,0);
  delay(1000);
  //
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  analogWrite(6,0);
  analogWrite(8,255);
  analogWrite(10,0);
  analogWrite(11,255);
  delay(2000);
  //
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  analogWrite(6,255);
  analogWrite(8,0);
  analogWrite(10,255);
  analogWrite(11,0);
  delay(2000);
  //
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
}

void p_NeoPixel(){
  for(int i=0;i<10;i++){
    r = random(0,255);
    g = random(0,255);
    b = random(0,255);
    strip.setPixelColor(0,r,g,b);
    r = random(0,255);
    g = random(0,255);
    b = random(0,255);
    strip.setPixelColor(1,r,g,b);
    r = random(0,255);
    g = random(0,255);
    b = random(0,255);
    strip.setPixelColor(2,r,g,b);
    strip.show();
    delay(300);
  }
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,0,255,0);
  strip.show();
  delay(300);
  strip.setPixelColor(0,0,0,255);
  strip.setPixelColor(1,0,0,255);
  strip.setPixelColor(2,0,0,255);
  strip.show();
  delay(300);
  strip.setPixelColor(0,255,0,0);
  strip.setPixelColor(1,255,0,0);
  strip.setPixelColor(2,255,0,0);
  strip.show();
  delay(300);
}

void p_bocina(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(9, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(9);
  }
}
