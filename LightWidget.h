#ifndef LightWidget
#define LightWidget

#include "Widget.h"
class LightWidget : public Widget{
private:
	u8 status;
public:
	void changeStatus();
}

#endif