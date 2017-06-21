#pragma hdrstop
#include "atNavitarFocusPreset.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
using namespace mtk;


NavitarFocusPreset::NavitarFocusPreset(NavitarMotorController& mc, const string& name, const int& z)
:
Preset<int>(name, z),
mController(mc)
{}

NavitarFocusPreset::~NavitarFocusPreset()
{}

bool NavitarFocusPreset::set()
{
	Log(lInfo) << "Setting preset: " << mKey << " value = " << getValue();
	return mController.getFocus().setPosition(getValue());
}


