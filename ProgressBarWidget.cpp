#include "Arduino.h"
#include "ProgressBarWidget.h"

ProgressBarWidget::ProgressBarWidget(uint16_t x, uint16_t y, int progress){
	this->x = x;
	this->y = y;
	this->progress = progress;
	type = 0x02;
	id = null;
}

void ProgressBarWidget::redrawBar(int progress){
	if(progress != this->progress){
		this->progress = progress;
		u8 send[2] = {id, progress};
		WidgetShield.sendWidgetCommand(send, 2);
	}
}
void ProgressBarWidget::intiGraphics(){
	redrawBar(0);
}