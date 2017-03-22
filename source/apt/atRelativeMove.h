#ifndef abRelativeMoveH
#define abRelativeMoveH
#include "atExporter.h"
#include "atATObject.h"
#include "atMove.h"
//---------------------------------------------------------------------------
class APTMotor;

class AT_CORE RelativeMove : public ab::Move
{
    public:
    								RelativeMove( const string& lbl, APTMotor* mtr = NULL, double pos = 0, double maxVel = 1, double acc = 1);
									~RelativeMove(){}
		const string 				getTypeName() const;


    protected:

    private:

};
#endif
