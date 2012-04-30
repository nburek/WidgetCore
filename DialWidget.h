#ifndef DialWidget_h
#define DialWidget_h

#include "Widget.h"
#include "WidgetShield.h"

class DialWidget : public Widget {
private:
	uint16_t angle;
public:
	DialWidget(uint16_t x, uint16_t y, uint16_t angle);
	void redrawNeedle(uint16_t angle);
	void initGraphics();
};

#endif