#ifndef abMoveSequenceH
#define abMoveSequenceH
#include "arraybot/atABExporter.h"
#include "atATObject.h"
#include <list>
#include <vector>
#include <string>
#include "atMove.h"
#include "atProcessSequence.h"
//---------------------------------------------------------------------------

using std::list;
using std::string;

class AT_AB MoveSequence : public ProcessSequence
{
    public:
								 	        MoveSequence();
				        	                ~MoveSequence(){}
};

#endif
