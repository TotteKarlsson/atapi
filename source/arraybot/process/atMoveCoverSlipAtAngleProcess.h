#ifndef atMoveCoverSlipAtAngleProcessH
#define atMoveCoverSlipAtAngleProcessH
#include "../core/atProcess.h"
#include "arraybot/atABExporter.h"
//---------------------------------------------------------------------------

//!A LiftAtAngle process is a process combining up to 4 motors to move
//!the coverslip and the whisker at a predefined angle.

class APTMotor;

class AT_AB MoveCoverSlipAtAngleProcess : public Process
{
    public:
        	   			                            MoveCoverSlipAtAngleProcess(const string& lbl);
    	virtual			                            ~MoveCoverSlipAtAngleProcess(){}
        bool										calculateLift();
        											//Virtuals
		virtual void		   		                init(ArrayBot& ab);

        virtual bool	       		                start();
        virtual bool	                        	stop();
        virtual bool	                        	isBeingProcessed();
        bool 						            	isProcessed();
        bool						            	resume();
        virtual	bool	                            undo();
        bool 						            	isDone();
		virtual bool 			  					write();

		const string 				                getTypeName() const;
	    virtual mtk::XMLElement*                    addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

        void										setLiftVelocity(double l);
        double										getLiftVelocity();

        void										setLiftAcceleration(double l);
        double										getLiftAcceleration();

        void										setLiftAngle(double l);
        double										getLiftAngle();

        void										setLiftHeight(double l);
        double										getLiftHeight();

        double										getLateralVelocity(){return mLateralVelocity;}
        double										getLateralAcceleration(){return mLateralAcceleration;}


        bool										assignMotors(APTMotor* csz, APTMotor* csy, APTMotor* wz, APTMotor* wy);

    protected:
    	APTMotor* 									mCSZMtr;
    	APTMotor* 									mCSYMtr;
    	APTMotor* 									mWHZMtr;
    	APTMotor* 									mWHYMtr;

        double										mLiftVelocity;
        double										mLiftAcceleration;
        double										mLiftAngle;
        double										mLiftHeight;
        double										mLateralVelocity;
        double										mLateralAcceleration;


        											//!This is the initial z value
                                                    //!Process is done when current Z =< ZStart - mLiftHeight

        double										mTargetCSZ;
        double										mTargetCSY;

        double										mTargetWHZ;
        double										mTargetWHY;

        double										getCurrentCoverSlipZ();
};


#endif
