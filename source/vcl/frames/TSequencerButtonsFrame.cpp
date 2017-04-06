#include <vcl.h>
#pragma hdrstop
#include <Buttons.hpp>
#include "TSequencerButtonsFrame.h"
#include "mtkVCLUtils.h"
#include "TYesNoForm.h"
#include <sstream>
#include "mtkLogger.h"
#include "forms/TProcessSequenceControlForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma resource "*.dfm"

using namespace mtk;
using std::stringstream;
TSequencerButtonsFrame *SequencerButtonsFrame;
//---------------------------------------------------------------------------
__fastcall TSequencerButtonsFrame::TSequencerButtonsFrame(ArrayBot& bot, TComponent* Owner)
	: TFrame(Owner),
    mAB(bot)
{
}
//--------------------------------------------------------------------------
void TSequencerButtonsFrame::update()
{
    for(int i = 0; i < mButtons.size(); i++)
    {
    	delete mButtons[i];
    }

	mButtons.clear();

    ProcessSequencer& psr = mAB.getProcessSequencer();
    ProcessSequences& pss = psr.getSequences();

	ProcessSequence*  current = pss.getCurrent();
    ProcessSequence*  ps = pss.getFirst();

    int nrOfButtons = pss.count();

    int pWidth = this->Width;
    int pHeight = this->Height;


    int btnNr(0);
    while(ps)
    {
        TArrayBotButton* btn = new TArrayBotButton(this->Parent);
        mButtons.push_back(btn);

        btn->Parent = this;
        btn->Caption = vclstr(ps->getName());
        btn->OnClick = click;
        btn->SoundID = "button_click_5";

        btn->Font->Size = 12;
        ps = pss.getNext();
        btn->Width = 150;
        btn->Height = 150;

        if(btnNr == 0)
        {
	        btn->Left = 3;
        }
        else
        {
			btn->Left = 3 + btnNr * (btn->Width + btn->Width / 4);
        }

        btn->Top = 0;
        btnNr +=1 ;
    }

    //Restore back to the sequence wich was selected
    pss.select(current);
}

//---------------------------------------------------------------------------
void __fastcall TSequencerButtonsFrame::mSequenceStatusTimerTimer(TObject *Sender)
{
    ProcessSequencer& psr = mAB.getProcessSequencer();
	if(!psr.isRunning())
    {
		mSequenceStatusTimer->Enabled = false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TSequencerButtonsFrame::click(TObject *Sender)
{
	TArrayBotButton* b = dynamic_cast<TArrayBotButton*>(Sender);
    if(!b)
    {
    	Log(lError) << "Bad button on the frame";
    	return;
    }

    ProcessSequencer& psr = mAB.getProcessSequencer();
    if(psr.selectSequence(stdstr(b->Caption)))
    {
        mSequenceStatusTimer->Enabled = true;
        mAB.disableJoyStickAxes();
        TProcessSequenceControlForm* f = new TProcessSequenceControlForm(mAB.getProcessSequencer(), this);
        f->ShowModal();
        delete f;
        mAB.enableJoyStickAxes();
    }
}


