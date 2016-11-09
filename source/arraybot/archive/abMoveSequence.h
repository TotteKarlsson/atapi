#ifndef abMoveSequenceH
#define abMoveSequenceH
#include "abExporter.h"
#include "abABObject.h"
#include <list>
#include <vector>
#include <string>
#include "abMove.h"
#include "abProcessSequence.h"
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
