 /*
 *ProgressBarWidget.h
 *Created By: Jacob Regan
 *Date of Creation:  4/23/12
 *Date of last edit: 4/25/12
 */

#ifndef ProgressBarWidget_h
#define ProgressBarWidget_h

#include "Widget.h"

//includes and inherits from Widget class
class ProgressBarWidget : public Widget{
	// adds to or modifies the following widget class members
private:
	char progress;
public:
	ProgressBarWidget(uint16_t x, uint16_t y, char progress);
	void redrawBar(char progress);
	void initGraphics();
};

#endif