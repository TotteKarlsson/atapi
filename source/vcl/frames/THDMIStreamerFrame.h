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
	TGroupBox *SettingsGB;
        TIntegerLabeledEdit *BitrateE;
	TSTDStringLabeledEdit *OutputFileFolderE;
	TSTDStringLabeledEdit *OutputFileNameE;
	TTimer *CheckStatus;
	TArrayBotButton *StartRecordingBtn;
	void __fastcall StartStreamerBtnClick(TObject *Sender);
	void __fastcall CheckStatusTimer(TObject *Sender);

    private:
		HDMIStreamerProcess			   	mStreamer;
  	    void 				            onEnter(int i, int j);
	    void 				            onProgress(int i, int j);
	    void 				            onExit(int i, int j);

    public:
        		__fastcall 				THDMIStreamerFrame(TComponent* Owner);
        		__fastcall 				~THDMIStreamerFrame();
		bool							isStreamerAlive();
		bool							shutDownStreamer();
        void							enableSettings();
        void							disableSettings();

};

extern PACKAGE THDMIStreamerFrame *HDMIStreamerFrame;
#endif
