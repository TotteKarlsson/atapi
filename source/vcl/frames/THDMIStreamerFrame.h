#ifndef THDMIStreamerFrameH
#define THDMIStreamerFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TArrayBotBtn.h"
#include "TIntegerLabeledEdit.h"
#include "TPropertyCheckBox.h"
#include "TSTDStringLabeledEdit.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "atHDMIStreamerProcess.h"
//---------------------------------------------------------------------------

class PACKAGE THDMIStreamerFrame : public TFrame
{
    __published:
        TGroupBox *GroupBox1;
        TIntegerLabeledEdit *BitrateE;
        TPropertyCheckBox *AppendTimeStampCB;
        TArrayBotButton *StartStreamerBtn;
	TSTDStringLabeledEdit *FileOutputFolderE;
	TSTDStringLabeledEdit *OutputFileNameE;
	void __fastcall StartStreamerBtnClick(TObject *Sender);

    private:
		HDMIStreamerProcess					mStreamer;

    public:
        		__fastcall 				THDMIStreamerFrame(TComponent* Owner);
};

extern PACKAGE THDMIStreamerFrame *HDMIStreamerFrame;
#endif
