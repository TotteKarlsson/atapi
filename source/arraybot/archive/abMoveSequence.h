#ifndef abMoveSequenceH
#define abMoveSequenceH
#include "atExporter.h"
#include "atABObject.h"
#include <list>
#include <vector>
#include <string>
#include "atMove.h"
#include "atProcessSequence.h"
//---------------------------------------------------------------------------

using std::list;
using std::string;

class AT_CORE MoveSequence : public ProcessSequence
{
    public:
								 	        MoveSequence();
				        	                ~MoveSequence(){}
};

#endif
