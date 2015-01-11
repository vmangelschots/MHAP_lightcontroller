#include "Arduino.h"
#include "light.h"

Light::Light(int pin)
{
  _pin = pin;
  pinMode(_pin,OUTPUT);
  digitalWrite(_pin,LOW);
}

void Light::update_light(){}
void Light::turn_on(){}
void Light::turn_off(){}
void Light::toggle(){}

TwoStateLight::TwoStateLight(int pin) : Light(pin)
{
  
}

void TwoStateLight::update_light()
{
  if(_state){
    digitalWrite(_pin,HIGH);
  }
  else{
    digitalWrite(_pin,LOW);
  }
}

void TwoStateLight::turn_on()
{
  _state = true;
  update_light();
}
void TwoStateLight::turn_off()
{
  _state = false;
  update_light();
}

void TwoStateLight::toggle()
{
  _state = !_state;
  update_light();
}
