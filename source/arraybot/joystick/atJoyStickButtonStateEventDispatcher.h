#ifndef abJoyStickButtonStateEventDispatcherH
#define abJoyStickButtonStateEventDispatcherH
#include "core/atATObject.h"
#include "atEnums.h"
#include <utility>
#include "arraybot/atABExporter.h"
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

        						//!Stting clickEventOnly means that the state
                                //is only checked for a state change, i.e. going from
                                //pressed to 'unpressed'.
                                //If Click eventOnly is false, state is checked continously
                                //in the event loop
        bool					mClickEventOnly;
};


#endif
