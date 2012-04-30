#ifndef LightWidget_h
#define LightWidget_h

#include "Widget.h"
class LightWidget : public Widget{
private:
	char status;
public:
	LightWidget(uint16_t x, uint16_t y, char status);
	void changeStatus();
};

#endif