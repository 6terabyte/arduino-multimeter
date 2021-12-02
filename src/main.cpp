#include <Arduino.h>
#include <Servo.h>
#include <SevenSegment.h>

Servo myservo;
SevenSegment sevenSegment = SevenSegment();

const int INPUT_PIN = A7;

void setup() {
  Serial.begin(9600);
  myservo.attach(13);
  
  int pinAllTmp[8] = {2, 3, 4, 5, 6, 7, 8, 9};
  int anode[4] = {10, 11, 12};
  sevenSegment.init(pinAllTmp, anode);
}

int i = 0;
void loop() {

  
  int volume = analogRead(INPUT_PIN);
  Serial.println(volume);
  int angle = int(float(volume)/1023*180);
  myservo.write(angle);
  sevenSegment.display(angle);
  Serial.println(angle);
}