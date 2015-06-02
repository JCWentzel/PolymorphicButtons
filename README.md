# PolymorphicButtons
A simple Arduino library to make multi-function buttons.
There are many button libraries out there, all with their virtues, this one is meant to be very simple and easy to use. Each button has 4 states:

* Clicked
* Double Clicked
* Short Hold
* Long Hold

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

## Additional Settings
Each button can be fine-tuned by using the following settings: 

	void setup()
	{ 
	  //setup buttons
	  button1.begin();
	  //You can set button timing values for each button to fine tune interaction.
	  button1.debounce(20);//Defualt is 10 milliseconds
	  button1.dcGap(300);//Time between clicks for Double click. Defualt is 200 milliseconds
	  button1.holdTime(3000);//Defualt is 2 seconds
	  button1.longHoldTime(8000);//Defualt is 5 seconds
	}

These are not global and must be set for each button you want affected. If you do not set them, the defaults are used.
