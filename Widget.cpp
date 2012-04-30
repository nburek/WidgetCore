#include "WProgram.h"
#include "Widget.h"


Widget::Widget(uint16_t x, uint16_t y, int type){
	this->x = x;
	this->y = y;
	this->type = type;
	id = NULL;
}

void Widget::initGraphics(){

}
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