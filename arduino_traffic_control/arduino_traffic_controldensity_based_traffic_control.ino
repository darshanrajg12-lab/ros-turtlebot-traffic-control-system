#include "SevSeg.h"

SevSeg S;

byte CommonPins[] = {};
byte SegPins[] = {2,3,4,5,6,7,8};

int ultrasonicTriggerPin = 12;
int ultrasonicEchoPin = 13;

int redPin = 9;
int yellowPin = 10;
int greenPin = 11;

int carCount = 0;

void setup() {

  S.begin(COMMON_CATHODE, 1, CommonPins, SegPins, 1);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  pinMode(ultrasonicTriggerPin, OUTPUT);
  pinMode(ultrasonicEchoPin, INPUT);

  digitalWrite(redPin, HIGH);

  displayNumber(carCount);
}

void loop() {

  int distance = getDistance();

  if (distance < 10) {
    carCount++;
    displayNumber(carCount);
    delay(1000);
  }

  if (carCount >= 2) {
    greenLight(10000);
  }
  else {
    greenLight(5000);
  }
}

void greenLight(int duration) {

  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);

  delay(duration);

  digitalWrite(greenPin, LOW);
}

void displayNumber(int num) {

  S.setNumber(num);
  S.refreshDisplay();
  delay(20);
}

int getDistance() {

  digitalWrite(ultrasonicTriggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonicTriggerPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(ultrasonicTriggerPin, LOW);

  long duration = pulseIn(ultrasonicEchoPin, HIGH);

  int distance = duration * 0.034 / 2;

  return distance;
}