#ifndef abPositionalTriggerH
#define abPositionalTriggerH
//---------------------------------------------------------------------------
#include "abExporter.h"
#include "abABObject.h"
#include "process/abTrigger.h"
//---------------------------------------------------------------------------

class APTMotor;

//!A motor trigger typically triggers when a motors position passes over a set threshold value.
//!To properly fire a trigger, a trigger TestFunction need to be given, e.g. mtr->getPosition() that
//!is used to check for the trigger condition.

//!Functions to be executed when the trigger fires are assigned and stored to the TriggerFunctions array from
//!the base class (no array yet)
//!Triggers are members of the Process classes and are enabled, disabled in a process's start/stop functions

class AT_CORE PositionalTrigger : public Trigger
{
    public:
                                			PositionalTrigger(APTMotor* m = NULL, double position = 0, LogicOperator lt = loLargerThan);
                                			~PositionalTrigger(){}

		virtual void	 					execute();
        virtual const string 				getTypeName() const{return "positionalTrigger";}

        double								getPosition(){return mPosition;}
        void								setPosition(double p){mPosition = p;}

		virtual mtk::XMLElement*            addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

    protected:
        double					            mPosition;
        APTMotor*							mMotor;
        virtual void  			            triggerTest();
        virtual bool  			            test(double position);
        virtual bool  			            test(int){return false;}
};
#endif
