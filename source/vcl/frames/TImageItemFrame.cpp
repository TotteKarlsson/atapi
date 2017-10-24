#include <vcl.h>
#pragma hdrstop
#include "TImageItemFrame.h"
#include "mtkLogger.h"
#include <JPEG.hpp>
#include "mtkVCLUtils.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma resource "*.dfm"
TImageItemFrame *ImageItemFrame;

using namespace mtk;
static int frameNr = 0;

//---------------------------------------------------------------------------
__fastcall TImageItemFrame::TImageItemFrame(const File& file, TComponent* Owner)
	:
    TFrame(Owner),
    mItemFile(file),
    mThumbNail("")
{
    this->Name = this->Name + "_" + IntToStr(frameNr++);
   	WarningImage->Visible 	= !mItemFile.exists();

    //Create thumbnail if not exist
    Path tnp(mItemFile.path());

    tnp.setExtension("_tn.jpg");
    mThumbNail = tnp;
    if(mThumbNail.exists())
    {
    	//load thumbnail to image
        Log(lDebug5) << "Item thumbnail exists";
        string imgP = mThumbNail.path();
        WarningImage->Picture->LoadFromFile(imgP.c_str());
		WarningImage->Visible = true;
    }
    else
    {
    	if(mItemFile.exists())
        {
            //create thumbnail
            Log(lDebug5) << "Creating Item thumbnail";
            mTNThread.assignCallBacks(NULL, NULL, populateTNImage);
            mTNThread.setInputFile(mItemFile.path());
            mTNThread.run();
        }
    }
}

void TImageItemFrame::setItemName(const string& name)
{
	mItemName = name;
}

//---------------------------------------------------------------------------
void __fastcall TImageItemFrame::PlayBtnClick(TObject *Sender)
{
	if(mItemFile.exists())
    {
		Log(lInfo) << "Playing file: "<<mItemFile.path();
		ShellExecuteA(NULL,NULL, "open", mItemFile.path().c_str(), NULL, SW_SHOWNORMAL);
    }
    else
    {
		Log(lWarning) << "The file: "<<mItemFile.path()<<" don't exist!";
    }
}

//---------------------------------------------------------------------------
void __fastcall TImageItemFrame::WarningImageClick(TObject *Sender)
{
	Log(lWarning) << "The file: "<<mItemFile.path()<<" don't exist!";
}

void TImageItemFrame::populateTNImage(int, int)
{
	try
    {
        Log(lDebug) << "Loading thumbnail: " << mThumbNail.path();
        string imgP = mThumbNail.path();
        WarningImage->Picture->LoadFromFile(imgP.c_str());
	    WarningImage->Visible = true;
    }
    catch(const EFOpenError& e)
    {
    	Log(lError) << stdstr(e.Message);
    }
    catch(const EInvalidGraphic& e)
    {
    	Log(lError) << stdstr(e.Message);
    }


}
