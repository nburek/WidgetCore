#ifndef DialWidget
#define DialWidget

#include "Widget.h"
#include "WidgetShield.h"

class DialWidget : public Widget {
private:
	double angle;
public:
	void redrawNeedle(uint16_t angle);
}

#endif