#ifndef atLiftAtAngleProcessH
#define atLiftAtAngleProcessH
#include "atParallelProcess.h"
//---------------------------------------------------------------------------

//!A LiftAtAngle process is a process combining 4 motors to move
//!coverslip and whisker at a predefined angle.

class AT_AB LiftAtAngleProcess : public ParallelProcess
{
    public:
        	   			                            LiftAtAngleProcess(const string& lbl);
    	virtual			                            ~LiftAtAngleProcess(){}
		virtual void		   		                init(ArrayBot& ab);
		const string 				                getTypeName() const;
	    virtual mtk::XMLElement*                    addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);


    protected:
};


#endif
