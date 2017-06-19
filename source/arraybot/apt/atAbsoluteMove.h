#ifndef abAbsoluteMoveH
#define abAbsoluteMoveH
#include "atMove.h"
//---------------------------------------------------------------------------

//!An absolute move have the position and positionResolution attributes
class AT_AB AbsoluteMove : public at::Move
{
    public:
			        				        AbsoluteMove( const string& lbl, APTMotor* mtr = NULL, double pos = 0, double maxVel = 1, double acc = 1);
				        			        ~AbsoluteMove(){}
		const string 				        getTypeName() const;
        virtual void				        addTrigger(Trigger* t);
		virtual bool 			  	        write();
        bool 			                    setPosition(double pos){mPosition = pos; return true;}
        double			                    getPosition(){return mPosition;}

        virtual bool	  			        isDone();
		bool 						        start();
		virtual mtk::XMLElement*            addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

    protected:
           				                    //!The position is the location which to achieve by the move
        double		                        mPosition;
        double						        mPositionResolution;

    private:

};
#endif
