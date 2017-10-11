# PolymorphicButtons
An easy to use library which allows for simple setup of debouncing multifunction buttons. PMButtons is setup using the internal pullup resistors for simple wiring, see the example below.

Detectable types of button presses:
* Clicked
* Double Clicked
* Short Hold
* Long Hold
* pressed
* released

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
	
Wiring Diagram for the example scketch, no external resistors needed.
![Wiring with internal pullup resistor](https://github.com/JCWentzel/PolymorphicButtons/raw/Images/Images/PMButtons_bb.png)

## Additional Settings
Each button can be fine-tuned by using the following settings: 

	void setup()
	{ 
	  //setup buttons
	  button1.begin();
	  //You can set button timing values for each button to fine tune interaction.
	  button1.debounce(20);//Default is 10 milliseconds
	  button1.dcGap(300);//Time between clicks for Double click. Default is 200 milliseconds
	  button1.holdTime(3000);//Default is 2 seconds
	  button1.longHoldTime(8000);//Default is 5 seconds
	}

These are not global and must be set for each button you want affected. If you do not set them, the defaults are used.
