#ifndef abJoyStickButtonStateEventDispatcherH
#define abJoyStickButtonStateEventDispatcherH
#include "atATObject.h"
#include "atEnums.h"
#include <utility>

using std::pair;

//---------------------------------------------------------------------------
typedef void (__closure *JoyStickEvent)();
typedef pair<JoyStickEvent, JoyStickEvent> ButtonEvents;

//Helper class
class AT_AB JoyStickButtonStateEventDispatcher  : public ATObject
{
	public:
				    			JoyStickButtonStateEventDispatcher();

                                //!The buttons state is checked against
                                //!status value retrieved in a polling loop. If
                                //!the value changed, the state is updated
                                //!and the associated Event is fired
		JoyStickButtonState 	mButtonState;
    	ButtonEvents 			mEvents;
};


#endif