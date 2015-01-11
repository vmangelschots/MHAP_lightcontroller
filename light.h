#include "Arduino.h"

#ifndef Light_H
#define Light_H
class Light
{
 protected:
   int _pin;
 public:
   Light(int pin);
   virtual void update_light();
   virtual void turn_on();
   virtual void turn_off();
   virtual void toggle();
};

class TwoStateLight : public Light
{
  private:
    boolean _state = false;
  public:
    TwoStateLight(int pin);
    void update_light();
    void turn_on();
    void turn_off();
    void toggle();
};

class DimmableLight: public Light
{
 public:
 
   void dim(); 
};

#endif
