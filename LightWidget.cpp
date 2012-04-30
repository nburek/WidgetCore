#include "WProgram.h"
#include "LightWidget.h"
#include "WidgetShield.h"

LightWidget::LightWidget(uint16_t x, uint16_t y, char status) : Widget(x,y,LIGHT_WIDGET_TYPE)
{
	this->x = x;
	this->y = y;
	this->status = status;
}

void LightWidget::changeStatus(){
	if(status == 0x00){
		status = 0x01;
		char send[2] = {id, status};
		WidgetShield::Instance()->sendWidgetCommand(send, 2);
	}else{
		status = 0x00;
		char send[2] = {id, status};
		WidgetShield::Instance()->sendWidgetCommand(send, 2);
	}
}