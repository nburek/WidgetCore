/**
 *	To create a reference to this singleton class use the following:
 *		WidgetShield* wC = WidgetShield::Instance();
 */
#include "WidgetShield.h"

WidgetShield* WidgetShield::p_instance = NULL;

WidgetShield* WidgetShield::Instance()
{
	if (p_instance==NULL) p_instance= new WidgetShield;
	return p_instance;
}

WidgetShield::WidgetShield()
{
	Serial.begin(9600);
}

void WidgetShield::addWidget(Widget w)
{
	char data[1];
	if (w.getID() == NULL)
	{
		data[0] = w.getType();
		sendData(ADD_WIDGET_COMMAND,data,1);
		w.setID(receiveByte());
		w.initGraphics();
	}
}

void WidgetShield::removeWidget(Widget w)
{
	char data[1];
	if (w.getID() != NULL)
	{
		data[0] = w.getID();
		sendData(REMOVE_WIDGET_COMMAND,data,1);
		w.setID(NULL);
	}
}

void WidgetShield::moveWidget(Widget w, uint16_t x, uint16_t y)
{
	char data[5];
	
	if (w.getID() != NULL)
	{
		data[0] = w.getID();
		uint16ToCharArray(x,data+1);
		uint16ToCharArray(y,data+3);
		
		sendData(MOVE_WIDGET_COMMAND,data,5);
	}
}

void WidgetShield::sendWidgetCommand(char data[], char length)
{
	sendData(SEND_WIDGET_COMMAND,data,length);
}

void WidgetShield::sendData(char function, char data[],char length)
{
	//need to first send the start command and length
	Serial.print(START_SEND_COMMAND);
	if (function == START_SEND_COMMAND || function == ESCAPE_CHARACTER)
		Serial.print(ESCAPE_CHARACTER);
	Serial.print(function);
	if (length == START_SEND_COMMAND || length == ESCAPE_CHARACTER)
		Serial.print(ESCAPE_CHARACTER);
	Serial.print(length);
	
	for (char i = 0; i<length; ++i)
	{
		if (data[i] == START_SEND_COMMAND || data[i]==ESCAPE_CHARACTER)
			Serial.print(ESCAPE_CHARACTER);
		Serial.print(data[i]);
	}
}


void WidgetShield::uint16ToCharArray(uint16_t i, char* data)
{
	data[0] = (char) (i >> 8);
	data[1] = (char) (i & 0x0F);
}

char WidgetShield::receiveByte()
{
	while (Serial.available()<=0);
	
	return Serial.read();
}