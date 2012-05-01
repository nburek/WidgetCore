 /*
 *LightWidget.cpp
 *Created By: Jacob Regan
 *Date of Creation:  4/23/12
 *Date of last edit: 4/25/12
 */

#include "WProgram.h"
#include "LightWidget.h"
#include "WidgetShield.h"

// sets x, y, and status of the widget
LightWidget::LightWidget(uint16_t x, uint16_t y, char status) : Widget(x,y,LIGHT_WIDGET_TYPE)
{
	this->x = x;
	this->y = y;
	this->status = status;
}


//toggles the status of the widget to be 'on' or 'off'
void LightWidget::changeStatus(){
	
	//checks if the status is off
	if(status == 0x00){
		char command = 0x02;
		//if it is then turn it on and send on command to shield
		status = 0x01;
		char send[3] = {id, command, status};
		WidgetShield::Instance()->sendWidgetCommand(send, 2);
	}else{
		char command = 0x02;
		//else it must be on so turn it off and send off command to shield
		status = 0x00;
		char send[3] = {id, command, status};
		WidgetShield::Instance()->sendWidgetCommand(send, 2);
	}
}
char LightWidget::getStatus(){
	return (this->status);
}