#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// distance sensor
int trigger =13, echo = 12;
int cm = 0;
char num[10];

//leds
int red = 11, yllw = 10, grn = 9; 

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yllw, OUTPUT);
  pinMode(grn, OUTPUT);
}

void loop()
{
  // measure the ping time in cm
  cm = 0.0175 * readUltrasonicDistance(trigger, echo);
  itoa(cm,num,10);
  if(cm < 100){
    Serial.write("Regiao1:");
    Serial.write(num);
    Serial.write(" ");
    digitalWrite(red, HIGH);
    
  } else if(100 <= cm && cm < 200){
    Serial.write("Regiao2:");
    Serial.write(num);
    digitalWrite(yllw, HIGH);
    
  } else{
    Serial.write("Regiao3:");
    Serial.write(num);
    digitalWrite(grn, HIGH);
  }
  Serial.write('\n');
  delay(300);
  digitalWrite(red, LOW);
  digitalWrite(yllw, LOW);
  digitalWrite(grn, LOW);
}