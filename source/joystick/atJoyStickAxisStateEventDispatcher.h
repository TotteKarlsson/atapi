#ifndef abJoyStickAxisStateEventDispatcherH
#define abJoyStickAxisStateEventDispatcherH
#include "atATObject.h"
//---------------------------------------------------------------------------

typedef void (__closure *JoyStickAxisEvent)(int pos);

class JoyStickAxisStateEventDispatcher  : public ATObject
{
	public:
				    		JoyStickAxisStateEventDispatcher() : mPosition(0){};
		int					mPosition;
    	JoyStickAxisEvent 	mEvent;
};


#endif
