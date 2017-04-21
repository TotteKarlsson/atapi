#include <vcl.h>
#pragma hdrstop
#include "TSequenceInfoFrame.h"
#include "process/atProcess.h"
#include "process/atParallellProcess.h"
#include "process/atProcessSequence.h"
#include "mtkVCLUtils.h"
#include "TStringInputDialog.h"
#include "process/atTimeDelay.h"
#include "process/atArrayCamRequest.h"
#include "process/atStopAndResumeProcess.h"
#include "frames/TMotorMoveProcessFrame.h"
#include "frames/TParallellProcessesFrame.h"
#include "frames/TTimeDelayFrame.h"
#include "frames/TArrayCamRequestFrame.h"
#include "atVCLUtils.h"
#include "mtkLogger.h"
#include "TSelectProcessTypeDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TSTDStringLabeledEdit"
#pragma link "TArrayBotBtn"
#pragma resource "*.dfm"
TSequenceInfoFrame *SequenceInfoFrame;

using namespace mtk;
//---------------------------------------------------------------------------
__fastcall TSequenceInfoFrame::TSequenceInfoFrame(ProcessSequencer& ps, TComponent* Owner)
	: TFrame(Owner),
    mSequence(NULL),
    mProcessSequencer(ps),
    mArrayBot(mProcessSequencer.getArrayBot()),
    mProcessPanel(NULL)
{
    //Create frames
	mParallellProcessesFrame = new TParallellProcessesFrame(mProcessSequencer, Owner);
    mParallellProcessesFrame->Visible = false;

    mTimeDelayFrame = new TTimeDelayFrame(Owner);
    mTimeDelayFrame->Visible = false;

    mArrayCamRequestFrame = new TArrayCamRequestFrame(Owner);
    mArrayCamRequestFrame->Visible = false;


	mUpdatePositionsBtn->Action = mParallellProcessesFrame->mUpdateFinalPositionsA;
}

//---------------------------------------------------------------------------
bool TSequenceInfoFrame::populate(ProcessSequence* seq, TScrollBox* processPanel)
{
	if(!seq)
    {
		empty();
        return false;
    }

    if(processPanel)
    {
    	mProcessPanel 						= processPanel;
		mParallellProcessesFrame->Parent 	= mProcessPanel;
        mTimeDelayFrame->Parent 			= mProcessPanel;
        mArrayCamRequestFrame->Parent 		= mProcessPanel;
    }

    mProcessesLB->Clear();
	mSequence = seq;

    Process* p = seq->getFirst();
    while(p)
    {
        mProcessesLB->Items->AddObject(p->getProcessName().c_str(), (TObject*) p);
        p = seq->getNext();
    }

    //Select the first move in the sequence
    if(mProcessesLB->Count)
    {
        mProcessesLB->ItemIndex = 0;
    }

    EnableDisableFrame(this, true);
    mProcessesLBClick(NULL);
	updateSequenceArrows();
    return true;
}

//---------------------------------------------------------------------------
void __fastcall TSequenceInfoFrame::mMoveSequenceUpBtnClick(TObject *Sender)
{
	//Get selected sequence
    int i = mProcessesLB->ItemIndex;
    Process* p = (Process*) mProcessesLB->Items->Objects[i];
    if(p && mSequence)
    {
		mSequence->moveBack(p);
		mSequence->write();
        //Rebuild the Listbox
		populate(mSequence);

        //Select process
        selectAndClickListBoxItem(mProcessesLB, (TObject*) p);
    }
}

//---------------------------------------------------------------------------
void __fastcall TSequenceInfoFrame::mMoveSequenceDownBtnClick(TObject *Sender)
{
	//Get selected sequence
    int i = mProcessesLB->ItemIndex;
    Process* p = (Process*) mProcessesLB->Items->Objects[i];
    if(p && mSequence)
    {
    	mSequence->moveForward(p);
		mSequence->write();

        //Rebuild the Listbox
		populate(mSequence);

        //Select process
        selectAndClickListBoxItem(mProcessesLB, (TObject*) p);
    }
}

//---------------------------------------------------------------------------
void __fastcall TSequenceInfoFrame::RemoveProcessAExecute(TObject *Sender)
{
	if(!mSequence)
    {
    	Log(lError) << "Tried to remove process from NULL sequence";
    	return;
    }

    int i = mProcessesLB->ItemIndex;
    Process* p = (Process*) mProcessesLB->Items->Objects[i];

    mSequence->remove(p);
    mProcessesLB->DeleteSelected();

    if(mProcessesLB->Count > -1)
    {
		mProcessesLB->ItemIndex = 0;
		mProcessesLBClick(NULL);
    }

    mSequence->write();
}

Process* TSequenceInfoFrame::getCurrentlySelectedProcess()
{
	if(mProcessesLB->Count > 0)
    {
	    Process* p = (Process*) mProcessesLB->Items->Objects[mProcessesLB->ItemIndex];
        return p;
    }
    return NULL;
}

void __fastcall TSequenceInfoFrame::mProcessesLBClick(TObject *Sender)
{
	if(mProcessesLB->Count == 0)
    {
    	disableEnableButtons(false);
    }

	if(mProcessesLB->Count == 1)
    {
	   	disableEnableButtons(false);
		mDeleteMoveBtn->Enabled = true;
    }

	updateSequenceArrows();

	mParallellProcessesFrame->Visible 	= false;
	mUpdatePositionsBtn->Visible 		= false;
    mTimeDelayFrame->Visible 			= false;
    mArrayCamRequestFrame->Visible     	= false;

    //Check what kind of process we have, Pause, or CombinedMove
    Process* p = getCurrentlySelectedProcess();
    if(dynamic_cast<ParallellProcess*>(p) != NULL)
    {
    	ParallellProcess* pp = dynamic_cast<ParallellProcess*>(p);
        mParallellProcessesFrame->populate(pp);
        mParallellProcessesFrame->mSubProcessesLB->ItemIndex = 0;
        mParallellProcessesFrame->mSubProcessesLB->OnClick(NULL);


        mParallellProcessesFrame->Visible 	= true;
		mUpdatePositionsBtn->Visible 		= true;
        mUpdatePositionsBtn->Enabled 		= true;
        mParallellProcessesFrame->Align = alClient;
    }
    else if(dynamic_cast<TimeDelay*>(p) != NULL)
    {
		TimeDelay* tdp = dynamic_cast<TimeDelay*>(p);
        mTimeDelayFrame->populate(tdp);
        mTimeDelayFrame->Visible = true;
        mTimeDelayFrame->Align = alClient;

    }
    else if(dynamic_cast<ArrayCamRequest*>(p) != NULL)
    {
		ArrayCamRequest* tdp = dynamic_cast<ArrayCamRequest*>(p);
        mArrayCamRequestFrame->populate(tdp);
        mArrayCamRequestFrame->Visible = true;
        mArrayCamRequestFrame->Align = alClient;
    }
    else
    {
		mParallellProcessesFrame->Visible 	= false;
		mUpdatePositionsBtn->Enabled 		= false;
		mUpdatePositionsBtn->Visible 		= false;
    }
}

void TSequenceInfoFrame::disableEnableButtons(bool enabled)
{
	mMoveSequenceUpBtn->Enabled = enabled;
	mMoveSequenceDownBtn->Enabled = enabled;
	mDeleteMoveBtn->Enabled = enabled;
}
//---------------------------------------------------------------------------
void __fastcall TSequenceInfoFrame::empty()
{
	//mMainGB->Caption = "<none>";
	mProcessesLB->Clear();
    EnableDisableFrame(this, false);
}

void __fastcall TSequenceInfoFrame::AddCombinedMoveAExecute(TObject *Sender)
{
	if(!mSequence)
    {
    	Log(lError) << "Tried to add process to NULL sequence";
    	return;
    }

    //Ask the user for type of process/event to create
   	TSelectProcessTypeDialog* pTypeForm = new TSelectProcessTypeDialog(this);

   	int mr = pTypeForm->ShowModal();

   	if(mr == mrOk)
	{
	    Process *p = NULL;
     	int nr  = mSequence->getNumberOfProcesses() + 1;

    	//get process type
        int pType = pTypeForm->mProcTypeRG->ItemIndex;
        if(pType == 0) //Parallell process
        {
			//Create and add a process to the sequence
	        p = new ParallellProcess("Process " + mtk::toString(nr));
        }
        else if(pType == 1) //Time delay
        {
        	p = new TimeDelay("Process " + mtk::toString(nr));
        }
        else if(pType == 2) //Stop/Start Dialog
        {
        	p = new StopAndResumeProcess("Process " + mtk::toString(nr));
        }
        else if(pType == 3) //Stop/Start Dialog
        {
//        	p = new ArrayCamRequest("Process " + mtk::toString(nr));
        }

        else
        {
        	Log(lError) << "Process Type Selection is not Suported!";
            return;
        }

        mSequence->add(p);
        mSequence->write();

        //Update LB
        mProcessesLB->Items->AddObject(p->getProcessName().c_str(), (TObject*) p);
        selectAndClickListBoxItem(mProcessesLB, (TObject*) p);
   }
}

void TSequenceInfoFrame::updateSequenceArrows()
{
	if(mProcessesLB->Count <= 1)
    {
		mMoveSequenceUpBtn->Enabled = false;
		mMoveSequenceDownBtn->Enabled = false;
    	return;
    }

	//Depending which item is selected, enable/disable items

	//Last item
    if(mProcessesLB->ItemIndex > 0 && (mProcessesLB->ItemIndex + 1) == mProcessesLB->Count)
    {
		mMoveSequenceUpBtn->Enabled 	= true;
		mMoveSequenceDownBtn->Enabled 	= false;
    }
    //First item
    else if(mProcessesLB->ItemIndex == 0)
    {
		mMoveSequenceUpBtn->Enabled 	= false;
		mMoveSequenceDownBtn->Enabled 	= true;
    }
    else
    {
		mMoveSequenceUpBtn->Enabled 	= true;
		mMoveSequenceDownBtn->Enabled 	= true;
    }
}

//---------------------------------------------------------------------------
void __fastcall TSequenceInfoFrame::mUpdatePositionsBtnClick(TObject *Sender)
{
	mParallellProcessesFrame->mUpdateFinalPositionsAExecute(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TSequenceInfoFrame::mRenameBtnClick(TObject *Sender)
{
	//Open string input form
	TStringInputDialog* t = new TStringInputDialog(this);
    t->Caption = "Rename Process";

    Process* p = getCurrentlySelectedProcess();
    if(!p)
    {
    	return;
    }

    t->setText(p->getProcessName());

    if(t->ShowModal() == mrOk)
    {
		//Rename the currently selected sequence
    	string newName(t->getText());

		p->setProcessName(newName);
        mSequence->write();

    	//Change name of sequence in ListBox
        int indx = mProcessesLB->ItemIndex;
        if(updateListBoxItemCaption(mProcessesLB, indx, newName) == false)
        {

        }

        if(selectAndClickListBoxItem(mProcessesLB, newName) == false)
        {
        	//bad..
        }

    }
    delete t;
}


