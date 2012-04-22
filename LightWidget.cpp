#include "Arduino.h"
#include "LightWidget.h"

LightWidget::LightWidget(uint16_t x, uint16_t y, bool status){
	this->x = x;
	this->y = y;
	this->status = status;
	type = 0x03;
	id = null;
}

void LightWidget::changeStatus(){
	if(status == 0x00){
		status = 0x01;
		u8 send[2] = {id, status};
		WidgetShield.sendWidgetCommand(send, 2);
	}else{
		status = 0x00;
		u8 send[2] = {id, status};
		WidgetShield.sendWidgetCommand(send, 2);
	}
}