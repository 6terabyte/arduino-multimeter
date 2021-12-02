#ifndef Multimeter_h
#define Multimeter_h
#include <Arduino.h>

class Multimeter {
  public:
    void init(int);
    void loopInit(void);
    int kHz(void);
    int Hz(void);
    int duty(void);
    void result(int[3]);
  
  private:
    int inputPin; 
    unsigned long lowTime;
    unsigned long highTime;
    unsigned long totalTime;
    
    float HzTmp;
    float kHzTmp;
};

#endif