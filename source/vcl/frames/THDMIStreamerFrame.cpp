#include <vcl.h>
#pragma hdrstop
#include "THDMIStreamerFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma link "TIntegerLabeledEdit"
#pragma link "TPropertyCheckBox"
#pragma link "TSTDStringLabeledEdit"
#pragma resource "*.dfm"
THDMIStreamerFrame *HDMIStreamerFrame;


//---------------------------------------------------------------------------
__fastcall THDMIStreamerFrame::THDMIStreamerFrame(TComponent* Owner)
	: TFrame(Owner),
    mStreamer()
{

}

void __fastcall THDMIStreamerFrame::StartStreamerBtnClick(TObject *Sender)
{
	mStreamer.startStreaming();
}
//---------------------------------------------------------------------------

