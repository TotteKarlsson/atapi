#include <vcl.h>
#pragma hdrstop
#include "TSoundsFrame.h"
#include "mtkVCLUtils.h"
#include "sound/atSounds.h"
using namespace mtk;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSoundsFrame *SoundsFrame;

//---------------------------------------------------------------------------
__fastcall TSoundsFrame::TSoundsFrame(TComponent* Owner)
	: TFrame(Owner),
    mSound("", this->Handle)
{}

void TSoundsFrame::populate()
{
	//Populate listbox with available sound resources
	StringList snds = getSoundResources();

	SoundsLB->Clear();
    for(int i = 0; i < snds.count(); i++)
    {
    	SoundsLB->AddItem(vclstr(snds[i]), NULL);
    }
}

//---------------------------------------------------------------------------
void __fastcall TSoundsFrame::PlayBtnClick(TObject *Sender)
{
	TButton* b = dynamic_cast<TButton*>(Sender);
    if(b == StopBtn)
    {
    	mSound.stop();
    }
    else if (b == PlayBtn)
    {
        if(!mSound.isValid())
        {
	    	mSound.create("BUTTON_CLICK_2", this->Handle);
        }
	    mSound.play(0, RepeatSoundCB->Checked ? 1 : 0);
    }
}

//---------------------------------------------------------------------------
void __fastcall TSoundsFrame::TrackBar1Change(TObject *Sender)
{
	mSound.setVolume(TrackBar1->Position);
}

//---------------------------------------------------------------------------
void __fastcall TSoundsFrame::SoundsLBClick(TObject *Sender)
{
	if(SoundsLB->ItemIndex != -1)
    {
    	mSelectedSound = stdstr(SoundsLB->Items->Strings[SoundsLB->ItemIndex]);
        mSound.create(mSelectedSound, this->Handle);
    }
}


