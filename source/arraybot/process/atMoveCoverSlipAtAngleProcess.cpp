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
mLateralAcceleration(0){
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
bool MoveCoverSlipAtAngleProcess::calculateLift()
{
	//The knowns are Z velocity and acceleration, and theta
    //Calculate Y velocity and acceleration
    //We get Y velocity as ZVelocity/tan(theta)
    if(mLiftAngle > 0 || mLiftAngle < 90)
    {
    	double tanVal = tan(toRadians(mLiftAngle));
    	mLateralVelocity = mLiftVelocity / tanVal;
	    mLateralAcceleration = mLiftAcceleration / tanVal;
//        mFinalCSZ = mOriginalCSZ - mLiftHeight;
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
//        	m->setVelocityParameters(mMaxVelocity, mAcceleration);

    if(!mCSZMtr || !mCSYMtr || !mWHZMtr || !mWHYMtr)
    {
		Log(lError) << "At least one motor in the LiftAtAngle process is NULL. Can't start process";
        return false;
    }

    //Z
    mCSZMtr->setVelocityParameters(mLiftVelocity, mLiftAcceleration);
	mWHZMtr->setVelocityParameters(mLiftVelocity, mLiftAcceleration);

    //Y
    mCSYMtr->setVelocityParameters(mLateralVelocity, mLateralAcceleration);
    mWHYMtr->setVelocityParameters(mLateralVelocity, mLateralAcceleration);
    
    //Calculate goto positions
    double targetCSZ = getCurrentCoverSlipZ() - mLiftHeight;
    
    mCSZMtr->moveToPosition(targetCSZ);

    mCSYMtr->moveToPosition(targetCSZ);    
	return Process::start();
}

bool MoveCoverSlipAtAngleProcess::stop()
{
	return Process::stop();
}

bool MoveCoverSlipAtAngleProcess::isDone()
{
	//Check motor positions
//    if(mOriginalCSZ - getCurrentCoverSlipZ() >= mLiftHeight)
//    {
//    	return true;
//    }
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

    return dynamic_cast<XMLElement*>(docRoot);
}

