#include "Arduino.h"
#include "DialWidget.h"

DialWidget::DialWidget(uint16_t x, uint16_t y, double angle){
	this->x = x;
	this->y = y;
	this->angle = angle;
	type = 0x01;
	id = null;
}

void DialWidget::redrawNeedle(uint16_t angle){
	if(angle != this->angle){
		this->angle = angle;
		u8 send[2] = {id, angle};
		WidgetShield.sendWidgetCommand(send, 2);
	}
}
void DialWidget::intiGraphics(){
	redrawNeedle(0);
}