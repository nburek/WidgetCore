
#include "WidgetCore.h"

WidgetCore* WidgetCore::p_instance = NULL;

WidgetCore* WidgetCore::Instance()
{
	if (p_instance==NULL) p_instance= new WidgetCore;
	return p_instance;
}

WidgetCore::WidgetCore()
{
	
}

void WidgetCore::addWidget(Widget w)
{
	
}
void WidgetCore::removeWidget(Widget w)
{
	
}

void WidgetCore::sendData(char data[],int length)
{
	
}