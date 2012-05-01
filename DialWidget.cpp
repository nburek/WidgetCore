 /*
 *DialWidget.cpp
 *Created By: Jacob Regan
 *Date of Creation:  4/23/12
 *Date of last edit: 4/25/12
 */

#include "WProgram.h"
#include "DialWidget.h"
#include "WidgetShield.h"


//Sets x, y, and inital angle
DialWidget::DialWidget(uint16_t x, uint16_t y, uint16_t angle) : Widget(x,y,DIAL_WIDGET_TYPE)
{
	this->x = x;
	this->y = y;
	this->angle = angle;
}

//sets new angle and sends command to redraw the needle
void DialWidget::redrawNeedle(uint16_t angle){
	// only sets new angle and sends command if the angle has indeed changed
	// this saves on draw time
	if(angle != this->angle){
		//set new angle
		this->angle = angle;
		//define stat array
		char send[4];
		//set id to first index
		send[0] = id;
		send[1] = 0x02;
		//next two indices are reserved for the new angle
		WidgetShield::Instance()->uint16ToCharArray(angle,send+2);
		// send the widget command.
		WidgetShield::Instance()->sendWidgetCommand(send, 3);
	}
}

// set needle to position 0 for the inital draw
void DialWidget::initGraphics(){
	redrawNeedle(0);
}