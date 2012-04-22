#ifndef Widget
#define Widget

abstract class Widget{
private:
	uint16_t x, y; 
	int id;
	char type;
	intiGraphics();
public:
	Widget(uint16_t x, uint16_t y, int type);
	char getType();
	void setType(char type);
	int getID();
	void setID(int id);

}

#endif