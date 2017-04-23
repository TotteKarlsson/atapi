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
{
	mArrayCamRequestCB->Clear();

    //The combox items holds Arraycam requests text and enum values
	mArrayCamRequestCB->Items->AddObject("Start Video", 			reinterpret_cast<TObject*>(acrStartVideo));
	mArrayCamRequestCB->Items->AddObject("Stop Video", 				reinterpret_cast<TObject*>(acrStopVideo));
	mArrayCamRequestCB->Items->AddObject("Take SnapShot", 			reinterpret_cast<TObject*>(acrTakeSnapShot));
	mArrayCamRequestCB->Items->AddObject("Enable Barcode Scanner", 	reinterpret_cast<TObject*>(acrEnableBarcodeScanner));
	mArrayCamRequestCB->Items->AddObject("Disable Barcode Scanner", reinterpret_cast<TObject*>(acrDisableBarcodeScanner));
	mArrayCamRequestCB->Items->AddObject("Validate Barcode", 		reinterpret_cast<TObject*>(acrValidateBarcode));
}

void TArrayCamRequestFrame::populate(Process* p)
{
	//Populate, update frame with data from process
    mArrayCamRequest = dynamic_cast<ArrayCamRequest*>(p);
    if(!p)
    {
    	EnableDisableFrame(this, false);
        return;
    }

    mNameEdit->setValue(mArrayCamRequest->getProcessName());

    //What kind of request do we have?
    for(int i = 0; i < mArrayCamRequestCB->Items->Count; i++)
    {
    	ACRequest ar = (ACRequest) mArrayCamRequestCB->Items->Objects[i];

		if(mArrayCamRequest->getRequest() == ar)
        {
        	mArrayCamRequestCB->ItemIndex = i;
            break;
        }
    }


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

//---------------------------------------------------------------------------
void __fastcall TArrayCamRequestFrame::mArrayCamRequestCBCloseUp(TObject *Sender)
{

    if(mArrayCamRequest)
    {
		ACRequest r = (ACRequest) mArrayCamRequestCB->Items->Objects[mArrayCamRequestCB->ItemIndex];
        mArrayCamRequest->setRequest(r);
    }
}


