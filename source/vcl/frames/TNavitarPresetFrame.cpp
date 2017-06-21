#include <vcl.h>
#pragma hdrstop
#include "TNavitarPresetFrame.h"
#include "navitar/atNavitarMotorController.h"
#pragma package(smart_init)
#pragma link "TIntegerLabeledEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

TNavitarPresetFrame *NavitarPresetFrame;

//---------------------------------------------------------------------------
__fastcall TNavitarPresetFrame::TNavitarPresetFrame(TComponent* Owner)
	: TFrame(Owner)
{
}

void TNavitarPresetFrame::populate(NavitarMotorController& c)
{
	mController = &c;
}


//---------------------------------------------------------------------------
void __fastcall TNavitarPresetFrame::GoButtonClick(TObject *Sender)
{
	if(mController)
    {
		mController->setPreset(ZoomPos->getValue(), FocusPos->getValue());
    }
}

