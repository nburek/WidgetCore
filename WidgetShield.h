#ifndef WidgetShield_h
#define WidgetShield_h

#include "WProgram.h"
#include "Widget.h"

#define START_SEND_COMMAND 0x7C
#define ESCAPE_CHARACTER 0x7D
#define ADD_WIDGET_COMMAND 0x01
#define REMOVE_WIDGET_COMMAND 0x02
#define MOVE_WIDGET_COMMAND 0x03
#define SEND_WIDGET_COMMAND 0x04 


class WidgetShield
{
	public:
		WidgetShield();
		static WidgetShield* Instance();
		void addWidget(Widget w);
		void removeWidget(Widget w);
		void moveWidget(Widget w, uint16_t x, uint16_t y);
		void sendWidgetCommand(char data[], char length);
	private:
		static WidgetShield *p_instance;
		void sendData(char function, char data[],char length);
		void uint16ToCharArray(uint16_t i, char* data);
		char receiveByte();
};

#endif