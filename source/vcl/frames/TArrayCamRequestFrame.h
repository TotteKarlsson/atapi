#ifndef TArrayCamRequestFrameH
#define TArrayCamRequestFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include "arraybot/atArrayBot.h"
#include <Vcl.ExtCtrls.hpp>
#include "TSTDStringLabeledEdit.h"

class Process;
class ArrayCamRequest;
//---------------------------------------------------------------------------
class PACKAGE TArrayCamRequestFrame : public TFrame
{
	__published:
        TGroupBox *GroupBox1;
        TSTDStringLabeledEdit *mNameEdit;
		TComboBox *mArrayCamRequestCB;
        void __fastcall mEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

    private:
		ArrayCamRequest*				mArrayCamRequest;

	public:
							__fastcall  TArrayCamRequestFrame(TComponent* Owner);

    	void							populate(Process* p);
    	void							rePopulate(Process* p);
};

extern PACKAGE TArrayCamRequestFrame *ArrayCamRequestFrame;
#endif