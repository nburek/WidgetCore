 /*
 *Widget.cpp
 *Created By: Jacob Regan
 *Date of Creation:  4/23/12
 *Date of last edit: 4/25/12
 */

#include "WProgram.h"
#include "Widget.h"
#include "WidgetShield.h"


// declares a basic constructor which sets x, y, and type to starting values.  Automatically sets id to null
Widget::Widget(uint16_t x, uint16_t y, char type){
	this->x = x;
	this->y = y;
	this->type = type;
	id = NULL;
}

//Blank initialization of graphics allows the widgetShield class to call it with no consequence.
//Overridden in specific widget class as needed
void Widget::initGraphics(){
}

//Standard get and set functions for type and ID
char Widget::getType(){
	return (type);
}
void Widget::setType(char type){
	this->type = type;
}
char Widget::getID(){
	return(id);
}
void Widget::setID(char id){
	this->id = id;
}