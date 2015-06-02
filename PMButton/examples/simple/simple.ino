//JC Wentzel's Polymorphic Buttons

#include "PMButton.h"

// here is where we define the buttons that we'll use.
// The analog 0-5 pins are also known as 14-19
PMButton button1(14);
PMButton button2(15);

void setup()
{ 
  // set up serial port
  Serial.begin(9600);
  Serial.println("Button checker with 2 buttons");
  
  //setup buttons
  button1.begin();
  button2.begin();
  
  //You can set button timing values for each button to fine tune interaction.
  button1.debounce(20);//Default is 10 milliseconds
  button1.dcGap(300);//Time between clicks for Double click. Default is 200 milliseconds
  button1.holdTime(3000);//Default is 2 seconds
  button1.longHoldTime(8000);//Default is 5 seconds
}

//Serial Feedback
void useButonCheck()
{
  if(button1.held()){Serial.println("button1 was held.");}
  
  if(button1.heldLong()){Serial.println("button1 held for a long time!");}
  
  if(button1.clicked()){Serial.println("button1 Just clicked.");}
  
  if(button1.doubleClicked()){Serial.println("button1 Just double clicked!");}
  
  //Button2
  if(button2.held()){Serial.println("button2 was held.");}
  
  if(button2.heldLong()){Serial.println("button2 held for a long time!");}
  
  if(button2.clicked()){Serial.println("button2 Just clicked.");}
  
  if(button2.doubleClicked()){Serial.println("button2 Just double clicked!");}
}
 

void loop() {
  //check_switches to get the current state
  button1.checkSwitch();
  button2.checkSwitch();
  
  //used to see the state change
  useButonCheck();
}
