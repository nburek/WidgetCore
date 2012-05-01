#include <WidgetShield.h>
#include <Widget.h>
#include <LightWidget.h>

 LightWidget light1(25, 25, 0x00); 
 
void setup(){
 WidgetShield* wC = WidgetShield::Instance();
 wC->addWidget(&light1);
 pinMode(35, INPUT);
}

void loop(){
  
  if(digitalRead(35) && light1.getStatus())
  {}else if(digitalRead(35)){
    light1.changeStatus();
  }
  if(!digitalRead(35) && light1.getStatus()){
    light1.changeStatus();
  }
}  
    
  
