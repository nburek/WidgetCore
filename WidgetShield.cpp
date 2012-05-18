/**
 *WidgetShield.cpp
 *Created By: Nick Burek
 *Date of Creation:
 *Date of last edit: 4/25/12
 *
 *	To create a reference to this singleton class use the following:
 *		WidgetShield* wC = WidgetShield::Instance();
 */
#include "WidgetShield.h"

WidgetShield* WidgetShield::p_instance = NULL;

//assigns an address to the pointer p_instance and returns that address
WidgetShield* WidgetShield::Instance()
{
	if (p_instance==NULL) p_instance= new WidgetShield;
	return p_instance;
}

//Initiates communication via UART
WidgetShield::WidgetShield()
{
	Serial.begin(9600);
}


// Sends a command to the physical shield to add a widget to its table
// Sets the ID of the newly added widget
// Calls the initGraphics function for that widget to start the graphical representation of that widget
void WidgetShield::addWidget(Widget* w)
{
	//create an array to send data
	char data[1];
	if (w->getID() == NULL)
	{
		//define data
		data[0] = w->getType();
		//send data
		sendData(ADD_WIDGET_COMMAND,data,1);
		// wait for and recieve new ID
		w->setID(receiveByte());
		// start widget graphics
		w->initGraphics();
	}
}


// Sends command to the physical shield to delete a widget from its table
// Sets the ID of that widget to null on the microcontroller
void WidgetShield::removeWidget(Widget* w)
{
	//create an array to send data
	char data[1];
	if (w->getID() != NULL)
	{
		//define data
		data[0] = w->getID();
		//send data
		sendData(REMOVE_WIDGET_COMMAND,data,1);
		//set ID to NULL
		w->setID(NULL);
	}
}

// Sends command to the physical shield to move a widget to a new (x,y) location
void WidgetShield::moveWidget(Widget* w, uint16_t x, uint16_t y)
{
	// Create array to send data
	char data[5];
	
	//if (w->getID() != NULL)
	//{
		//Define array elements
		data[0] = w->getID();
		// each uint16_t takes two bytes and therefore two array indices
		uint16ToCharArray(x,data+1);
		uint16ToCharArray(y,data+3);
		// send data
		sendData(MOVE_WIDGET_COMMAND,data,5);
	//}
}

// Defines how to send a Widget Command
void WidgetShield::sendWidgetCommand(char data[], char length)
{
	sendData(SEND_WIDGET_COMMAND,data,length);
}

void WidgetShield::resetWidgetShield()
{
	char data[1] = {0};
	sendData(RESET_WIDGET_SHIELD, data, 0);
}

void WidgetShield::sendData(char function, char data[],char length)
{
	unsigned char checksum = START_SEND_COMMAND;
	//need to first send the start command and length
	Serial.write(START_SEND_COMMAND);
	
	//After sending start command make sure function command is not a start command or the escape character.
	//if it is then escape the character
	if ((function == START_SEND_COMMAND) || (function == ESCAPE_CHARACTER)){
		Serial.write(ESCAPE_CHARACTER);
		checksum ^= ESCAPE_CHARACTER;
	}
	//send the function command
	Serial.write(function);
	checksum ^= function;
	
	//Similarly escape out the length
	if (length == START_SEND_COMMAND || length == ESCAPE_CHARACTER){
		Serial.write(ESCAPE_CHARACTER);
		checksum ^= ESCAPE_CHARACTER;
	}
	//send the length
	Serial.write(length);
	checksum ^= length;
	
	for (char i = 0; i<length; ++i)
	{
		//send the rest of the data escaping as needed
		if (data[i] == START_SEND_COMMAND || data[i]==ESCAPE_CHARACTER){
			Serial.write(ESCAPE_CHARACTER);
			checksum ^= ESCAPE_CHARACTER;
		}
		Serial.write(data[i]);
		checksum ^= data[i];
	}
	
	//Serial.write(checksum);

}

// provides code to break a uint16_t into two indicies of a character array
void WidgetShield::uint16ToCharArray(uint16_t i, char* data)
{
	data[0] = (char) (i >> 8);
	data[1] = (char) (i & 0xFF);
}

//When called waits for the UART connection to send data and reads from that data.
char WidgetShield::receiveByte()
{
	while (Serial.available()<=0);
	
	return Serial.read();
}