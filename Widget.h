 /*
 *Widget.h
 *Created By: Jacob Regan
 *Date of Creation:  4/23/12
 *Date of last edit: 4/25/12
 */

#ifndef Widget_h
#define Widget_h

//defines the codes for different widget types

#define DIAL_WIDGET_TYPE 0x01
#define PROGRESS_BAR_WIDGET_TYPE 0x02
#define LIGHT_WIDGET_TYPE 0x03
#define GRAPH_WIDGET_TYPE 0x05
///////////  ADD NEW WIDGETS BY TYPING A UNIQUE CODE ABOVE THIS LINE ////////////////////


class Widget
{
	//declare base members
protected:
	uint16_t x, y; 
	char type;
	char id;
public:
	Widget(uint16_t x, uint16_t y, char type);
	char getType();
	void setType(char type);
	char getID();
	void setID(char id);
	//set to virtual to allow overrides
	virtual void initGraphics();

};

#endif