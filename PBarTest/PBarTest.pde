#include <WidgetShield.h>
#include <Widget.h>
#include <ProgressBarWidget.h>

ProgressBarWidget pb1(25, 25, 0);

void setup(){
 WidgetShield* wC = WidgetShield::Instance();
 wC->addWidget(&pb1);
}
  
void loop(){
  int potVal = analogRead(0);
  map(potVal, 0, 1023, 0, 100);
  pb1.redrawBar(potVal);
  
}  
