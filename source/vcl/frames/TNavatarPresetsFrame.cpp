#include <vcl.h>
#pragma hdrstop
#include "TNavatarPresetsFrame.h"
#pragma package(smart_init)
#pragma link "TNavitarPreset"
#pragma resource "*.dfm"
TPresetsFrame *PresetsFrame;

//---------------------------------------------------------------------------
__fastcall TPresetsFrame::TPresetsFrame(TComponent* Owner)
	: TFrame(Owner)
{
}

void TPresetsFrame::populate(NavitarMotorController& c)
{
	mController = &c;
	TNavitarPreset1->populate(c);
	NavitarPreset1->populate(c);
	NavitarPreset2->populate(c);
}
