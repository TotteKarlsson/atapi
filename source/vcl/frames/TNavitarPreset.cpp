#include <vcl.h>
#pragma hdrstop
#include "TNavitarPreset.h"
#include "atNavitarMotorController.h"
#pragma package(smart_init)
#pragma link "TIntegerLabeledEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

TNavitarPreset *NavitarPreset;

//---------------------------------------------------------------------------
__fastcall TNavitarPreset::TNavitarPreset(TComponent* Owner)
	: TFrame(Owner)
{
}

void TNavitarPreset::populate(NavitarMotorController& c)
{
	mController = &c;
}


//---------------------------------------------------------------------------
void __fastcall TNavitarPreset::GoButtonClick(TObject *Sender)
{
	if(mController)
    {
		mController->setPreset(ZoomPos->getValue(), FocusPos->getValue());
    }
}

