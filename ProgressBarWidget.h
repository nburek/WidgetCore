#ifndef ProgressBarWidget_h
#define ProgressBarWidget_h

#include "Widget.h"

class ProgressBarWidget : public Widget{
private:
	char progress;
public:
	ProgressBarWidget(uint16_t x, uint16_t y, char progress);
	void redrawBar(char progress);
	void initGraphics();
};

#endif