#pragma hdrstop
#include "atMoveCoverSlipAtAngleProcess.h"
#include "atArrayBot.h"
#include "mtkMathUtils.h"
#include "atAPTMotor.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
using namespace mtk;

//---------------------------------------------------------------------------
MoveCoverSlipAtAngleProcess::MoveCoverSlipAtAngleProcess(const string& lbl)
:
Process(lbl),
mCSZMtr(NULL),
mCSYMtr(NULL),
mWHZMtr(NULL),
mWHYMtr(NULL),
mLiftVelocity(0),
mLiftAcceleration(0),
mLiftAngle(0),
mLiftHeight(0),
mLateralVelocity(0),
mLateralAcceleration(0),
mMoveWhiskerInParallel(false),
mFetchAngleFromCSAngleMotor(false)
{
	mProcessType = ptMoveCoverSlipAtAngle;
}

const string MoveCoverSlipAtAngleProcess::getTypeName() const
{
	return ::toString(mProcessType);
}

//Init is called by the sequencer BEFORE executing the process
void MoveCoverSlipAtAngleProcess::init(ArrayBot& ab)
{
    if(assignMotors(ab.getCoverSlipUnit().getZMotor(), ab.getCoverSlipUnit().getYMotor(), ab.getWhiskerUnit().getZMotor(), ab.getWhiskerUnit().getYMotor()))
    {
	    calculateLift(ab);
    }
    else
    {
    	Log(lError) << "At least one motor is missing for the MoveCSAtAngle process!";
    }

	Process::init(ab);
}

bool MoveCoverSlipAtAngleProcess::assignMotors(APTMotor* csz, APTMotor* csy, APTMotor* wz, APTMotor* wy)
{
	//We may wanna do some error checking here
    mCSZMtr = csz;
    mCSYMtr = csy;
    mWHZMtr = wz;
    mWHYMtr = wy;

	return (mCSZMtr && mCSYMtr && mWHZMtr && mWHYMtr) == true ? true : false;
}

double MoveCoverSlipAtAngleProcess::getCurrentCoverSlipZ()
{
	if(mCSZMtr)
    {
    	return mCSZMtr->getPosition();
    }

    return -1;
}


//The calculate move function uses move velocity and angle to calculate
//velocities for lateral movement, as well as final positions
bool MoveCoverSlipAtAngleProcess::calculateLift(ArrayBot& ab)
{
    if(mFetchAngleFromCSAngleMotor)
    {
        APTMotor* m = ab.getCoverSlipUnit().getAngleMotor();
        if(m)
        {
            mLiftAngle = m->getPosition();
        }
        else
        {
            Log(lError) << "Failed getting CS Angle motor. Liftangle NOT updated";
        }
    }

	//The knowns are Z velocity and acceleration, and theta
    //Calculate Y velocity and acceleration
    //We get Y velocity as ZVelocity/tan(theta)
    if(mLiftAngle > 0 || mLiftAngle < 90)
    {
    	double tanVal = tan(toRadians(mLiftAngle));
        if(tanVal)
        {
            mLateralVelocity = mLiftVelocity / tanVal;
            mLateralAcceleration = mLiftAcceleration / tanVal;
            mTargetCSZ = mLiftHeight;
            mTargetWHZ = mLiftHeight;
            mTargetCSY = mTargetCSZ / tanVal;
            mTargetWHY = mTargetCSZ / tanVal;
        }
        else
        {
        	return false;
        }
    }
    else
    {
    	return false;
    }

	return true;
}

void MoveCoverSlipAtAngleProcess::setLiftVelocity(double val)
{
    mLiftVelocity = val;
}

double MoveCoverSlipAtAngleProcess::getLiftVelocity()
{
	return mLiftVelocity;
}

void MoveCoverSlipAtAngleProcess::setLiftAcceleration(double val)
{
	mLiftAcceleration = val;
}

double MoveCoverSlipAtAngleProcess::getLiftAcceleration()
{
	return mLiftAcceleration;
}

void MoveCoverSlipAtAngleProcess::setLiftAngle(double val)
{
	mLiftAngle = val;
}

double MoveCoverSlipAtAngleProcess::getLiftAngle()
{
	return mLiftAngle;
}

void MoveCoverSlipAtAngleProcess::setLiftHeight(double val)
{
	mLiftHeight = val;
}

double MoveCoverSlipAtAngleProcess::getLiftHeight()
{
	return mLiftHeight;
}

bool MoveCoverSlipAtAngleProcess::write()
{
	if(mProcessSequence)
    {
    	return mProcessSequence->write();
    }
	return false;
}

bool MoveCoverSlipAtAngleProcess::isBeingProcessed()
{
	if(isDone())
    {
		mIsBeingProcessed 	= false;
        mIsProcessed 		= true;
       	Timestamp now;
        mEndTime = now;
    }

    return mIsBeingProcessed;
}

bool MoveCoverSlipAtAngleProcess::isProcessed()
{
    if(mIsProcessed == true)
    {
    	return true;
    }

    if(isDone())
    {
        //Consider this process to be "processed"
        mIsProcessed 		= true;
        mIsBeingProcessed 	= false;
        return true;
    }

	return false;
}

bool MoveCoverSlipAtAngleProcess::start()
{
	//Set motor parameters and move them to their position
    if(!mCSZMtr || !mCSYMtr || !mWHZMtr || !mWHYMtr)
    {
		Log(lError) << "At least one motor in the LiftAtAngle process is NULL. Can't start process";
        return false;
    }

    //Z & Y
    mCSZMtr->setVelocityParameters(mLiftVelocity, mLiftAcceleration);
    mCSYMtr->setVelocityParameters(mLateralVelocity, mLateralAcceleration);

	if(mMoveWhiskerInParallel)
    {
		mWHZMtr->setVelocityParameters(mLiftVelocity, 		mLiftAcceleration);
    	mWHYMtr->setVelocityParameters(mLateralVelocity, 	mLateralAcceleration);
    }

    //Calculate goto positions
    //The stages are configured so that z decreases during lift, while
    //Y increases
    mTargetCSZR = getMotorPosition(mCSZMtr) - mTargetCSZ;
    mTargetCSYR = getMotorPosition(mCSYMtr) + mTargetCSY;

    mTargetWHZR = getMotorPosition(mWHZMtr) - mTargetWHZ;
    mTargetWHYR = getMotorPosition(mWHYMtr) + mTargetWHY;


    Log(lInfo) << "Moving motor: "<< mCSZMtr->getName() <<" to position: "<< mTargetCSZR;
    Log(lInfo) << "Moving motor: "<< mCSYMtr->getName() <<" to position: "<< mTargetCSYR;

    mCSZMtr->moveToPosition(mTargetCSZR);
    mCSYMtr->moveToPosition(mTargetCSYR);

	if(mMoveWhiskerInParallel)
    {
	    Log(lInfo) << "Moving motor: "<< mWHZMtr->getName() <<" to position: "<< mTargetWHZR;
    	Log(lInfo) << "Moving motor: "<< mWHYMtr->getName() <<" to position: "<< mTargetWHYR;

    	mWHZMtr->moveToPosition(mTargetWHZR);
        mWHYMtr->moveToPosition(mTargetWHYR);
    }

	return Process::start();
}

bool MoveCoverSlipAtAngleProcess::stop()
{
	return Process::stop();
}

bool MoveCoverSlipAtAngleProcess::isDone()
{
	//Check motor positions
    if(isEqual(getMotorPosition(mCSZMtr), mTargetCSZR, 1.e-3) || isEqual(getMotorPosition(mCSYMtr), mTargetCSYR, 1.e-3))
    {
    	return true;
    }
    return false;
}

bool MoveCoverSlipAtAngleProcess::resume()
{
    return false;
}

bool MoveCoverSlipAtAngleProcess::undo()
{
	return false;
}

XMLElement* MoveCoverSlipAtAngleProcess::addToXMLDocumentAsChild(tinyxml2::XMLDocument& doc, XMLNode* docRoot)
{
	XMLElement* dataval1 = doc.NewElement("lift_velocity");
    dataval1->SetText(toString(mLiftVelocity).c_str());
	docRoot->InsertEndChild(dataval1);

	dataval1 = doc.NewElement("lift_acceleration");
    dataval1->SetText(toString(mLiftAcceleration).c_str());
	docRoot->InsertEndChild(dataval1);

	dataval1 = doc.NewElement("lift_angle");
    dataval1->SetText(toString(mLiftAngle).c_str());
	docRoot->InsertEndChild(dataval1);

	dataval1 = doc.NewElement("lift_height");
    dataval1->SetText(toString(mLiftHeight).c_str());
	docRoot->InsertEndChild(dataval1);

	dataval1 = doc.NewElement("move_whisker_in_parallel");
    dataval1->SetText(toString(mMoveWhiskerInParallel).c_str());
	docRoot->InsertEndChild(dataval1);

	dataval1 = doc.NewElement("fetch_angle_from_CS_angle_motor");
    dataval1->SetText(toString(mFetchAngleFromCSAngleMotor).c_str());
	docRoot->InsertEndChild(dataval1);

    return dynamic_cast<XMLElement*>(docRoot);
}

