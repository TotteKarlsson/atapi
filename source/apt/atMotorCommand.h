#ifndef abMotorCommandH
#define abMotorCommandH
#include "atExporter.h"
#include "atABObject.h"
#include <string>
#include <ostream>

using std::ostream;
using std::string;

//---------------------------------------------------------------------------
enum MotorCommandEnum
{
	mcNone = -1,
	mcStopHard = 0,
    mcStopProfiled,
    mcForward,
    mcReverse,
    mcJogForward,
    mcJogReverse,
    mcSetVelocity,
    mcSetVelocityParameters,
	mcSetVelocityForward,
	mcSetVelocityReverse,
    mcSetAcceleration,
    mcSwitchDirection,
    mcMoveDistance,
    mcMoveToPosition
};

string toString(MotorCommandEnum e);

class AT_CORE MotorCommand : public ABObject
{
	public:
							MotorCommand(MotorCommandEnum mce, double var1 = 0, double var2 = 0);
                        	~MotorCommand();

		string				asString() const;
        MotorCommandEnum	getCore();
        double				getFirstVariable() const;
        double				getSecondVariable() const;

		AT_CORE
 		friend ostream&         operator<<(ostream& stream, const MotorCommand& cmd);

    protected:
		MotorCommandEnum	mCommand;
    	double				mVariable1;
    	double				mVariable2;


};
#endif
