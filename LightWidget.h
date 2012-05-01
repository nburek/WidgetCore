 /*
 *LightWidget.h
 *Created By: Jacob Regan
 *Date of Creation:  4/23/12
 *Date of last edit: 4/25/12
 */

#ifndef LightWidget_h
#define LightWidget_h

#define LIGHT_OFF 0x00
#define LIGHT_ON  0x01

//includes and inherits from Widget class
#include "Widget.h"
class LightWidget : public Widget{
	// adds to or modifies the following widget class members
private:
	char status;
public:
	LightWidget(uint16_t x, uint16_t y, char status);
	void changeStatus();
	char getStatus();
};

#endif