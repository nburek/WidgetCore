 /*
 *DialWidget.h
 *Created By: Jacob Regan
 *Date of Creation:  4/23/12
 *Date of last edit: 4/25/12
 */

#ifndef DialWidget_h
#define DialWidget_h

//includes and inherits from Widget class
#include "Widget.h"
#include "WidgetShield.h"

class DialWidget : public Widget {
	// adds to or modifies the following widget class members
private:
	uint16_t angle;
public:
	DialWidget(uint16_t x, uint16_t y, uint16_t angle);
	void redrawNeedle(uint16_t angle);
	void initGraphics();
};

#endif