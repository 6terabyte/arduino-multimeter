#ifndef SevenSegment_h
#define SevenSegment_h
#include <Arduino.h>

class SevenSegment {
  public:
    void init(int*, int*);
    void forAllNumber(int);
    void allErase(void);
    void debug(void);
    void display(int);
  
  private:
  /*
    int pinA;
    int pinB;
    int pinC;
    int pinD;
    int pinE;
    int pinF;
    int pinG;
    int pinP;
    */
    int* anode;
    int pinAll[8];
    int pinNum[10][8];
    int debugNum;
    int p;
};

#endif