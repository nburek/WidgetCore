#ifndef Widget_h
#define Widget_h

#define DIAL_WIDGET_TYPE 0x01
#define PROGRESS_BAR_WIDGET_TYPE 0x02
#define LIGHT_WIDGET_TYPE 0x03


class Widget
{
protected:
	uint16_t x, y; 
	char type;
	char id;
public:
	Widget(uint16_t x, uint16_t y, int type);
	char getType();
	void setType(char type);
	char getID();
	void setID(char id);
	virtual void initGraphics();

};

#endif