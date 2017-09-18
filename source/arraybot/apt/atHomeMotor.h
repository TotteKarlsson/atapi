#ifndef atHomeMotorH
#define atHomeMotorH
#include "arraybot/atABExporter.h"
#include "core/atProcess.h"
#include "atPositionalTrigger.h"
#include "atMove.h"
//---------------------------------------------------------------------------

//!An absolute move have the position and positionResolution attributes
class AT_AB HomeMotor : public at::Move
{
    public:
			        				        HomeMotor( const string& lbl, APTMotor* mtr = NULL);
				        			        ~HomeMotor(){}
		const string 				        getTypeName() const;
		virtual bool 			  	        write();

        virtual bool	  			        isDone();
		bool 						        start();
		bool 						        resume();
		virtual mtk::XMLElement*            addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

    protected:
};

#endif
