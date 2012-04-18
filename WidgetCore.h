#ifndef WidgetCore_h
#define WidgetCore_h

class WidgetCore
{
	public:
		WidgetCore();
		void addWidget(Widget w);
		void removeWidget(Widget w);
		static WidgetCore* Instance();
	private:
		static WidgetCore *p_instance;
		void sendData(char data[],int length);

}

#endif