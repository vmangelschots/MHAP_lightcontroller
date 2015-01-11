#include "light.h"
#include <mthread.h>


class MySwitch : public SwitchInput
{
private:
  Light *_light;
public:
    MySwitch(int pin, Type type, Light *light);
    void on_close();
    void on_open();

};

MySwitch::MySwitch(int pin, Type type, Light *light) :
    SwitchInput(pin, DEFAULT_DEBOUNCE, type)
{
  _light = light;
}

void MySwitch::on_close()
{
  Serial.write("Closed switch\n");
  _light->toggle();
}

void MySwitch::on_open()
{
    
}



void setup() {
  Serial.begin(9600);
  Serial.write("Booting MHAP controller V0.1\n");
  MySwitch *sw[7];
  Light *lights[7];
  Serial.write("start adding light");
  for(int j = 0;j<7;j++)
  {
      Serial.write("adding light");
     lights[j] = new TwoStateLight(j+22);
     int switchpin = j+47;
     if(j == 6){
       switchpin = 2;
     }
       
     sw[j] = new MySwitch(switchpin,SwitchInput::pull_up_internal,lights[j]); 
     main_thread_list->add_thread(sw[j]);
  }
  

}

