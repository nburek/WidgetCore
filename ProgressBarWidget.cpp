 /*
 *ProgressBarWidget.cpp
 *Created By: Jacob Regan
 *Date of Creation:  4/23/12
 *Date of last edit: 4/25/12
 */

#include "WProgram.h"
#include "ProgressBarWidget.h"
#include "WidgetShield.h"

//Overrides the standard constructor to take an x and y as normal but also a starting progress
ProgressBarWidget::ProgressBarWidget(uint16_t x, uint16_t y, char progress) : Widget(x,y,PROGRESS_BAR_WIDGET_TYPE)
{
	this->x = x;
	this->y = y;
	//since the widget is already determined at this point the type is auto set
	this->progress = progress;
}

// provides the bitcode generation for updating the progress on the bar
void ProgressBarWidget::redrawBar(char progress){
	if(progress != this->progress){
		char command = 0x02;
		this->progress = progress;
		char send[3] = {id, command, progress};
		WidgetShield::Instance()->sendWidgetCommand(send, 2);
	}
}

//Overrides the standard intiGraphics function to auto sets the bar to 0
void ProgressBarWidget::initGraphics(){
	redrawBar(0);
}