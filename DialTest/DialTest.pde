#include <WidgetShield.h>
#include <Widget.h>
#include <DialWidget.h>

DialWidget dial1(25, 25, 0);

void setup(){
 WidgetShield* wC = WidgetShield::Instance();
 wC->addWidget(&dial1);
}
  
  
void loop(){
  int potVal = analogRead(0);
  map(potVal, 0, 1023, 0, 359);
  dial1.redrawNeedle(potVal);
  
}  
    
    
    
    
    
    
  
