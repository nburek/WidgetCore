#include "Arduino.h"
#include "Widget.h"

Widget::Widget(int x, int y, char type){
	this->x = x;
	this->y = y;
	this->type = type;
	id = null;

}

void Widget::intiGraphics(){

}
char Widget::getType(){
	return (type);
}
void Widget::setType(char type){
	this->type = type;
}
int Widget::getID(){
	return(id);
}
void Widget::setID(int id){
	this->id = id;
}