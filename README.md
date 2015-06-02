# PolymorphicButtons
A simple Arduino library to make multi-function buttons.
There are many button libraries out there, all with their virtues, this one is meant to be very simple and easy to use. Each button has 4 states.
•	Clicked
•	Double Clicked
•	Short Hold
•	Long Hold

## Simple example
Here is a basic example of how to use the library:

	#include "PMButton.h"
	//define a pin for a button
	PMButton button1(14);

	void setup() { button1.begin(); }
	void loop() { 
		button1.checkSwitch();
		if(button1.clicked()){Serial.println("button1 Just clicked.");}
	}