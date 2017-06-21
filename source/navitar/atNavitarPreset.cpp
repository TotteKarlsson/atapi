#pragma hdrstop
#include "atNavitarPreset.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
using namespace mtk;


NavitarPreset::NavitarPreset(NavitarMotorController& mc, const string& name, const int& z, const int& f)
:
mZoom(mc, "Zoom", z),
mFocus(mc, "Zoom", z),
mController(mc)
{}

NavitarPreset::~NavitarPreset()
{}

bool NavitarPreset::set()
{
	mZoom.set();
    mFocus.set();
    return true;
}

bool NavitarPreset::update(const int& z, const int& f)
{
	mZoom.update(z);
    mFocus.update(f);

    return true;
}

