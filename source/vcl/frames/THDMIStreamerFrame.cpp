#include <vcl.h>
#pragma hdrstop
#include "THDMIStreamerFrame.h"
#include "mtkLogger.h"
#include "mtkVCLUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma link "TIntegerLabeledEdit"
#pragma link "TPropertyCheckBox"
#pragma link "TSTDStringLabeledEdit"
#pragma resource "*.dfm"
THDMIStreamerFrame *HDMIStreamerFrame;
using namespace mtk;
using namespace Poco;
//---------------------------------------------------------------------------
__fastcall THDMIStreamerFrame::THDMIStreamerFrame(TComponent* Owner)
	: TFrame(Owner),
    mStreamer("bm.exe")
{
	mStreamer.assignCallBacks(
    boost::bind(&THDMIStreamerFrame::onEnter, 	 this, _1, _1),
	boost::bind(&THDMIStreamerFrame::onProgress, this, _1, _1),
	boost::bind(&THDMIStreamerFrame::onExit, 	 this, _1, _1)
    );
}

__fastcall THDMIStreamerFrame::~THDMIStreamerFrame()
{
	//Make sure bm process is ended
    if(mStreamer.isRunning())
    {
    	mStreamer.exit();
    }
}

void THDMIStreamerFrame::enableSettings()
{
	enableDisableGroupBox(SettingsGB, true);
}

void THDMIStreamerFrame::disableSettings()
{
	enableDisableGroupBox(SettingsGB, false);
}

bool THDMIStreamerFrame::isStreamerAlive()
{
	return mStreamer.isRunning();
}

bool THDMIStreamerFrame::shutDownStreamer()
{
   	mStreamer.exit();
}

//---------------------------------------------------------------------------
void __fastcall THDMIStreamerFrame::StartStreamerBtnClick(TObject *Sender)
{
	TArrayBotButton* b = dynamic_cast<TArrayBotButton*>(Sender);

    if(b == StartRecordingBtn)
    {
        if(b->Caption == "Start Recording")
        {
            mStreamer.startRecording(joinPath(OutputFileFolderE->getValue(), OutputFileNameE->getValue()), BitrateE->getValue());
        }
        else
        {
            mStreamer.stopRecording();
        }
    }
}

void THDMIStreamerFrame::onEnter(int i, int j)
{
	struct lclS
    {
        int i, j;
        THDMIStreamerFrame* f;
        void __fastcall onEnter()
        {
            Log(lInfo) << "HDMI Streamer Thread was entered..";
			f->StartRecordingBtn->Caption = "Stop Recording";
            f->disableSettings();
        }
    };
	lclS lcl;
    lcl.i = i;
    lcl.j = j;
    lcl.f = this;
    TThread::Synchronize(0, &lcl.onEnter);
}

void THDMIStreamerFrame::onProgress(int i, int j)
{
	struct lclS
    {
        int i, j;
        THDMIStreamerFrame* f;
        void __fastcall onProgress()
        {
        	//Check current file size
        	f->StartRecordingBtn->Caption = "Stop Recording\n" + vclstr(getHumanReadableFileSize(i));
        }
    };
	lclS lcl;
    lcl.i = i;
    lcl.j = j;
    lcl.f = this;
    TThread::Synchronize(0, &lcl.onProgress);
}

void THDMIStreamerFrame::onExit(int i, int j)
{
	struct lclS
    {
        int i, j;
        THDMIStreamerFrame* f;
        void __fastcall onEnter()
        {
            Log(lInfo) << "HDMI Streamer Thread exited..";
			f->StartRecordingBtn->Caption = "Start Recording";
            f->enableSettings();
        }
    };
	lclS lcl;
    lcl.i = i;
    lcl.j = j;
    lcl.f = this;
    TThread::Synchronize(0, &lcl.onEnter);
}

void __fastcall THDMIStreamerFrame::CheckStatusTimer(TObject *Sender)
{
	if(mStreamer.isRunning())
    {

    }
}


