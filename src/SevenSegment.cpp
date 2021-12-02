#include <Arduino.h>
#include <SevenSegment.h>

void SevenSegment::init(int* pinArgs, int* anodeArgs) {
  
  int pinA = pinArgs[0];
  int pinB = pinArgs[1];
  int pinC = pinArgs[2];
  int pinD = pinArgs[3];
  int pinE = pinArgs[4];
  int pinF = pinArgs[5];
  int pinG = pinArgs[6];
  int pinP = pinArgs[7];
  int pinAllTmp[8] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinP};
  for(int i=0; i<8;i++){
    pinAll[i] = pinAllTmp[i];
  }

  int pinNumTemp[10][8] = {
    {pinA, pinB, pinC, pinD, pinE, pinF},  // 0
    {pinB, pinC},//1
    {pinA, pinB, pinD, pinE, pinG},//2
    {pinA, pinB, pinC, pinD, pinG},//3
    {pinB, pinC, pinF, pinG},//4
    {pinA, pinC, pinD, pinF, pinG},//5
    {pinA, pinC, pinD, pinE, pinF, pinG},//6
    {pinA, pinB, pinC},//7
    {pinA, pinB, pinC, pinD, pinE, pinF, pinG},//8
    {pinA, pinB, pinC, pinD, pinF, pinG},//9
  };

  for(int iNum=0; iNum<10; iNum++){
    for(int iPin=0; iPin<8;iPin++){
      pinNum[iNum][iPin] = pinNumTemp[iNum][iPin];
    }
  }

  for(int i = 0; i < (sizeof(pinAll) / sizeof(int)); i++) {
    pinMode(pinAll[i],OUTPUT);
  }

  anode = anodeArgs;
  //for(int i = 0; i < (sizeof(anode) / sizeof(int)); i++){
  for(int i = 0; i < 8; i++){
    //Serial.println(i);
    pinMode(anode[i],OUTPUT);
    digitalWrite(anode[i],HIGH);
  }

  debugNum = 0;
}

void SevenSegment::allErase(void) {
  for(int i = 0; i< (sizeof(pinAll) / sizeof(int)); i++) {
    digitalWrite(pinAll[i], 1);
  }
  for(int i = 0; i< 7; i++) {
    digitalWrite(anode[i], 0);
  }
}

void SevenSegment::forAllNumber(int num) {
  //Serial.println(num);
  allErase();
  for(int j=0; j<8;j++){
    digitalWrite(pinNum[num][j], 0);
    //Serial.print(pinNum[num][j]);
  }
  //Serial.println();
}

void SevenSegment::debug(void) {
  //Aから順に点灯させる   pinMode(12, INPUT_PULLUP);をすること
  while (!digitalRead(12)) {
  debugNum++;
  if(debugNum == 10) debugNum = 0;
  //Serial.println(debugNum);
  allErase();
  digitalWrite(pinAll[debugNum],0);
  delay(500);
  }
}

void SevenSegment::display(int num){
  for (int i=1; i<5; i++) {
    int x = 1;
    for(int j=1; j<i; j++) {
      x = x * 10;
    }
    int a = (num/x)%10;
    forAllNumber(a);
    digitalWrite(anode[i-1],1);
    //delay(10);

  }
  //Serial.println();
}