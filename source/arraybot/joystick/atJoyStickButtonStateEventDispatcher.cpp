#pragma hdrstop
#include "atJoyStickButtonStateEventDispatcher.h"
//---------------------------------------------------------------------------

JoyStickButtonStateEventDispatcher::JoyStickButtonStateEventDispatcher(JoyStickButton& btn)
:
//mButtonState(bsUp),
mClickEventOnly(true),
mButton(btn)
{}

void JoyStickButtonStateEventDispatcher::setButtonState(JoyStickButtonState s)
{
//	mButtonState = s;
   	mButton.setState(s);
}

JoyStickButtonState JoyStickButtonStateEventDispatcher::getButtonState()
{
	return mButton.getState();
}
