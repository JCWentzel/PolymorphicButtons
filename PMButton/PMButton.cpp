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

#include "PMButton.h"

PMButton::PMButton(int pinNum)
{
  _pinNum = pinNum;
}

void PMButton::begin()
{
  pinMode(_pinNum, INPUT);
  digitalWrite(_pinNum, HIGH);
  
  _downTime = -1;
  _upTime = -1;
}

//Set Button Values
void PMButton::debounce(long value){_debounce = value;}
void PMButton::dcGap(long value){_dcGap = value;}
void PMButton::holdTime(long value){_holdTime = value;}
void PMButton::longHoldTime(long value){_longHoldTime = value;}

//Return Button State
bool PMButton::held(){return _held;}
bool PMButton::heldLong(){return _heldLong;}
bool PMButton::clicked(){return _clicked;}
bool PMButton::doubleClicked(){return _doubleClicked;}
bool PMButton::pressed(){return _pressed;}
bool PMButton::released(){return _released;}

void PMButton::checkSwitch()
{ 
  // when we start, reset the button function indicators.
  _held = false;
  _heldLong = false;
  _clicked = false;
  _doubleClicked = false;
  _pressed = false;
  _released = false;
   
  _currentstate = digitalRead(_pinNum);// read the button
  
  // Button pressed down
  if ((_currentstate == LOW) && (_previousstate == HIGH) && ((millis() - _upTime) > _debounce))
  {
    _downTime = millis();
    _ignoreUp = false;
    _waitForUp = false;
    _singleOK = true;
    _holdEventPast = false;
    _longHoldEventPast = false;
    _pressed = true;
    _released = false;
    
    if ((millis()- _upTime) > (_dcGap*2))
    {
      _doubleClickedEventPast = false;
    }
    
    if ((millis()- _upTime) < _dcGap && !_dcOnUp && _dcWaiting && !_doubleClickedEventPast)
    {
      _dcOnUp = true;
      _pressed = false;
    }
    else
    {
      _dcOnUp = false;
    }
    _dcWaiting = false;
  }
  
  // Button released
  else if ((_currentstate == HIGH) && (_previousstate == LOW) && (millis() - _downTime) > _debounce && !_doubleClickedEventPast)
  {
    _released = true;

    if (not _ignoreUp)
    {
      _upTime = millis();
      if (!_dcOnUp)
      {
        _dcWaiting = true;
      }
      else
      {
      _doubleClicked = true;
      _doubleClickedEventPast = true;// set  flag to keep from stacking
      _dcOnUp = false;
      _dcWaiting = false;
      _singleOK = false;
      }
    }
  }
  
  // Test for normal click event: _dcGap expired
  if ( _currentstate == HIGH && (millis() - _upTime) >= _dcGap && _dcWaiting && !_dcOnUp && _singleOK )
  {
    _clicked = true;
    _dcWaiting = false;
  }
  
  // Test for hold
  if (_currentstate == LOW && (millis() - _downTime) >= _holdTime)
  {
    // Trigger "normal" hold
    if (not _holdEventPast)
    {
      _held = true;
      _waitForUp = true;
      _ignoreUp = true;
      _dcOnUp = false;
      _dcWaiting = false;
      _holdEventPast = true;
    }
    
    // Trigger "long" hold
    if ((millis() - _downTime) >= _longHoldTime)
    {
      if (not _longHoldEventPast)
      {
        _heldLong = true;
        _longHoldEventPast = true;
      }
    }
  }
  
  _previousstate = _currentstate;
}