#ifndef ProgressBarWidget
#define ProgressBarWidget

#include "Widget.h"
class ProgressBarWidget : public Widget{
private:
	unsigned int progress;
public:
	void redrawBar(int progress);
}

#endif