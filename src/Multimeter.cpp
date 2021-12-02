#include <Arduino.h>
#include <Multimeter.h>

void Multimeter::init(int pin) {
  inputPin = pin;
  pinMode(inputPin, INPUT);
}

void Multimeter::loopInit(void) {
  highTime = pulseIn(inputPin, HIGH, 2000000);
  lowTime = pulseIn(inputPin, LOW, 2000000);
  // 理論値はduty50%で2147483647㎲
  totalTime = highTime + lowTime;
}

int Multimeter::kHz(void) {
  kHzTmp = (1 / float(totalTime) ) *1000;
  kHzTmp = round(kHzTmp);
  return int(kHzTmp);
}

int Multimeter::Hz(void) {
  HzTmp = (1 / float(totalTime) ) *1000 *1000;
  HzTmp = round(HzTmp);
  return int(HzTmp);
}

int Multimeter::duty(void) {
  return int((lowTime *100 ) / totalTime);
}

void Multimeter::result(int result[3]) {
  result[0] = Hz();
  result[1] = kHz();
  result[2] = duty();
}