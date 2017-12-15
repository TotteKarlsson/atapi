#pragma hdrstop
#include "atArrayBotProtocol.h"
//---------------------------------------------------------------------------

map<ABMessageID, string> ArrayBotProtocol::mIPCMessage;

ArrayBotProtocol::ArrayBotProtocol()
{
    mIPCMessage[abrSetJoyStickSpeed] 			= "Set Joystick Speed";
    mIPCMessage[abrUnknown]						= "Unknown";
}

ABMessageID ArrayBotProtocol::idFromString(const string& r)
{
    map<ABMessageID, string>::const_iterator it;
    ABMessageID key = abrUnknown;

    for (it = mIPCMessage.begin(); it != mIPCMessage.end(); ++it)
    {
	    if (it->second == r)
    	{
		    key = it->first;
			return key;
	    }
    }

   	return abrUnknown;
}

string ArrayBotProtocol::operator[](ABMessageID r)
{
	return mIPCMessage[r];
}
