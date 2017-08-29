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
        bool										calculateLift(ArrayBot& ab);
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
        bool										getMoveWhiskerInParallel(){return mMoveWhiskerInParallel;}
        bool										setMoveWhiskerInParallel(bool doIt){mMoveWhiskerInParallel = doIt; return true;}

		bool        								setFetchAngleFromCSAngleMotor(bool doIt){mFetchAngleFromCSAngleMotor = doIt; return true;}
		bool        								getFetchAngleFromCSAngleMotor(){return mFetchAngleFromCSAngleMotor;}

        bool										assignMotors(APTMotor* csz, APTMotor* csy, APTMotor* wz, APTMotor* wy);

    protected:
    	APTMotor* 									mCSZMtr;
    	APTMotor* 									mCSYMtr;
    	APTMotor* 									mWHZMtr;
    	APTMotor* 									mWHYMtr;
		bool										mMoveWhiskerInParallel;
		bool										mFetchAngleFromCSAngleMotor;

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
        double										mTargetCSZR;
        double										mTargetCSYR;

        double										mTargetWHZ;
        double										mTargetWHY;
        double										mTargetWHZR;
        double										mTargetWHYR;
        double										getCurrentCoverSlipZ();
};


#endif
