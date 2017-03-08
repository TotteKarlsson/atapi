#include <vcl.h>
#pragma hdrstop
#include <Buttons.hpp>
#include "TSequencerButtonsFrame.h"
#include "mtkVCLUtils.h"
#include "TYesNoForm.h"
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

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
        TSpeedButton* btn = new TSpeedButton(this);
        mButtons.push_back(btn);

        btn->Parent = this;
        btn->Caption = vclstr(ps->getName());
//        btn->Align = alLeft;
        btn->OnClick = runSequenceBtnClick;

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

void __fastcall TSequencerButtonsFrame::runSequenceBtnClick(TObject *Sender)
{
	TSpeedButton* b = dynamic_cast<TSpeedButton*>(Sender);
    if(b)
    {
	    TYesNoForm* f = new TYesNoForm(this);
        f->Caption = "";
        stringstream msg;
        msg <<"Execute sequence: "<< stdstr(b->Caption);

        f->mInfoLabel->Caption = msg.str().c_str();
        int res = f->ShowModal();
        if(res == mrYes)
        {
            ProcessSequencer& psr = mAB.getProcessSequencer();
            if(psr.selectSequence(stdstr(b->Caption)))
            {
                mSequenceStatusTimer->Enabled = true;
                mAB.disableJoyStickAxes();
                psr.start();
            }
        }
    }
}

void __fastcall TSequencerButtonsFrame::FrameEnter(TObject *Sender)
{
	update();
}

void __fastcall TSequencerButtonsFrame::mSequenceStatusTimerTimer(TObject *Sender)
{
    ProcessSequencer& psr = mAB.getProcessSequencer();
	if(!psr.isRunning())
    {
		mSequenceStatusTimer->Enabled = false;
        mAB.enableJoyStickAxes();
    }
}

