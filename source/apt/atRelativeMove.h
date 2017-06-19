#ifndef abRelativeMoveH
#define abRelativeMoveH
#include "atAPTExporter.h"
#include "atATObject.h"
#include "atMove.h"
//---------------------------------------------------------------------------
class APTMotor;

class AT_APT RelativeMove : public at::Move
{
    public:
    								RelativeMove( const string& lbl, APTMotor* mtr = NULL, double pos = 0, double maxVel = 1, double acc = 1);
									~RelativeMove(){}
		const string 				getTypeName() const;


    protected:

    private:

};
#endif
