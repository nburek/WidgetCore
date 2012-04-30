#include "WProgram.h"
#include "DialWidget.h"
#include "WidgetShield.h"

DialWidget::DialWidget(uint16_t x, uint16_t y, uint16_t angle) : Widget(x,y,DIAL_WIDGET_TYPE)
{
	
	this->x = x;
	this->y = y;
	this->angle = angle;
}

void DialWidget::redrawNeedle(uint16_t angle){
	if(angle != this->angle){
		this->angle = angle;
		char send[3];
		send[0] = id;
		WidgetShield::Instance()->uint16ToCharArray(angle,send+1);
		WidgetShield::Instance()->sendWidgetCommand(send, 3);
	}
}
void DialWidget::initGraphics(){
	redrawNeedle(0);
}