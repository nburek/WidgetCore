#include <WidgetShield.h>
#include <Widget.h>
#include <DialWidget.h>
#include <ProgressBarWidget.h>
#include <LightWidget.h>

#define TIME_TO_WAIT 100
long lastSendTime = 0;

DialWidget dial1(85, 65, 0);
ProgressBarWidget pbar(150, 150, 0);
LightWidget led1(190, 40, 0);
LightWidget led2(210, 40, 0);
LightWidget led3(230, 40, 0);
LightWidget led4(250, 40, 0);
LightWidget led5(270, 40, 0);
LightWidget led6(290, 40, 0);
LightWidget led7(310, 40, 0);
LightWidget led8(330, 40, 0);

void setup(){
  pinMode(35, INPUT);
  pinMode(37, INPUT);
  while(digitalRead(37));
  Serial.begin(9600);
 WidgetShield* wC = WidgetShield::Instance();
 wC->addWidget(&dial1);
 wC->addWidget(&led1);
 wC->addWidget(&led2);
 wC->addWidget(&led3);
 wC->addWidget(&led4);
 wC->addWidget(&led5);
 wC->addWidget(&led6);
 wC->addWidget(&led7);
 wC->addWidget(&led8);

 wC->addWidget(&pbar);
 
 //wC->removeWidget(&led);
}
  
  
void loop()
{
  if ((millis()-lastSendTime) > TIME_TO_WAIT)
  {
    lastSendTime = millis();
    int potVal = analogRead(0);
    int potVal2 = potVal;
    
    potVal = map(potVal, 0, 1023, 0, 359);
    dial1.redrawNeedle(potVal);
    
    potVal2 = map(potVal2, 0, 1023, 0, 100);
    pbar.redrawBar(potVal2);

    led1.changeStatus();
    led2.changeStatus();
    led3.changeStatus();
    led4.changeStatus();
    led5.changeStatus();
    led6.changeStatus();
    led7.changeStatus();
    led8.changeStatus();
    
    
  }
}  
    
    
    
    
    
    
  
