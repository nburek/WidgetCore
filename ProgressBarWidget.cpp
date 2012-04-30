#include "WProgram.h"
#include "ProgressBarWidget.h"
#include "WidgetShield.h"

ProgressBarWidget::ProgressBarWidget(uint16_t x, uint16_t y, char progress) : Widget(x,y,PROGRESS_BAR_WIDGET_TYPE)
{
	this->x = x;
	this->y = y;
	this->progress = progress;
}

void ProgressBarWidget::redrawBar(char progress){
	if(progress != this->progress){
		this->progress = progress;
		char send[2] = {id, progress};
		WidgetShield::Instance()->sendWidgetCommand(send, 2);
	}
}
void ProgressBarWidget::initGraphics(){
	redrawBar(0);
}