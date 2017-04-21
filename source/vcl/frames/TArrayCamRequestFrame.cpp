#include <vcl.h>
#pragma hdrstop
#include "TArrayCamRequestFrame.h"
#include "mtkVCLUtils.h"
#include "process/atProcess.h"
#include "process/atArrayCamRequest.h"
#include "mtkLogger.h"
#include "arraybot/atArrayBot.h"

#pragma package(smart_init)
#pragma link "TSTDStringLabeledEdit"
#pragma resource "*.dfm"

using namespace mtk;
TArrayCamRequestFrame *ArrayCamRequestFrame;
//---------------------------------------------------------------------------

__fastcall TArrayCamRequestFrame::TArrayCamRequestFrame(TComponent* Owner)
	: TFrame(Owner)
{}

void TArrayCamRequestFrame::populate(ArrayBot& ab, Process* p)
{
	mAB = &ab;
	rePopulate(p);
}

void TArrayCamRequestFrame::rePopulate(Process* p)
{
	//Populate, update frame with data from process
    mArrayCamRequest = dynamic_cast<ArrayCamRequest*>(p);
    if(!p)
    {
    	EnableDisableFrame(this, false);
        return;
    }

    mNameEdit->setValue(mArrayCamRequest->getProcessName());
  	EnableDisableFrame(this, true);
}

//---------------------------------------------------------------------------
void __fastcall TArrayCamRequestFrame::mEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	if(Key == vkReturn)
    {
    	mArrayCamRequest->setProcessName(mNameEdit->getValue());
    }
}



