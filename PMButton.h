/*--------------------------------------------------------------------
 Polymorphic Buttons A simple Arduino library to make multifunction buttons.
 Code by JC Wentzel 

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as
  published by the Free Software Foundation, either version 3 of
  the License, or (at your option) any later version.

  this program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public
  License along with this program.  If not, see
  <http://www.gnu.org/licenses/>.
--------------------------------------------------------------------*/

#ifndef PMButton_h
#define PMButton_h

#include "Arduino.h"

//header
class PMButton
{
  public:
  PMButton(int pinNum);//constructor
  //setup
  void begin();
  void debounce(long value), dcGap(long value), holdTime(long value), longHoldTime(long value);
  //status
  bool held(), isHeld(), heldLong(), isHeldLong(), clicked(), doubleClicked(), pressed(), isPressed (), released();
  //update button status
  void checkSwitch();
  
  private:
  //setup
  int _pinNum; // The Button Pin
  long _debounce = 10; // ms debounce period to prevent flickering when pressing or releasing the button
  long _dcGap = 200; // max ms between clicks for a double click event
  long _holdTime = 2000; // ms hold period: how long to wait for press+hold event
  long _longHoldTime = 5000; // ms hold period: how long to wait for the long press+hold event

  //states
  bool _held, _isHeld ,_heldLong, _isHeldLong, _clicked, _doubleClicked, _pressed, _isPressed, _released, _dcWaiting, _dcOnUp, _singleOK, _ignoreUp, _waitForUp, _holdEventPast, _longHoldEventPast, _doubleClickedEventPast, _previousstate, _currentstate;
  
  //Timing variables 
  unsigned long _downTime, _upTime;
};

#endif
