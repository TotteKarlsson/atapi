#pragma hdrstop
#include "atLightsArduino.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
using namespace mtk;


LightsArduino::LightsArduino(int portNr, int baudRate)
:
ArduinoDevice(portNr, baudRate),
mLEDLightONLine(3),
mLEDLightOFFLine(4)
{}

bool LightsArduino::turnLEDLightsOn()
{
	Log(lInfo) << "Turning on LEDs";
	return send(mLEDLightONLine);
}

bool LightsArduino::turnLEDLightsOff()
{
	Log(lInfo) << "Turning off LEDs";
	return send(mLEDLightOFFLine);
}

bool LightsArduino::toggleLED()
{
	static bool switcher(false);
    switcher = !switcher;
    return (switcher) ? send(mLEDLightONLine) :	send(mLEDLightOFFLine);
}

bool LightsArduino::setLEDDrive(int drive)
{
	Log(lInfo) << "Setting LEDs Drive to: "<<drive;
    return send("f" + toString(drive));
}

bool LightsArduino::getStatus()
{
	Log(lInfo) << "Requesting sensor arduino status";
	return send("i");
}
