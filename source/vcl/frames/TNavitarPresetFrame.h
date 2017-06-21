#ifndef TNavitarPresetFrameH
#define TNavitarPresetFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TIntegerLabeledEdit.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class NavitarPreset;

class PACKAGE TNavitarPresetFrame : public TFrame
{
    __published:
        TIntegerLabeledEdit *FocusPos;
        TIntegerLabeledEdit *ZoomPos;
	TGroupBox *MainGB;
        TButton *GoButton;
		void __fastcall GoButtonClick(TObject *Sender);
	void __fastcall onKey(TObject *Sender, WORD &Key, TShiftState Shift);

    private:
        NavitarPreset&					mPreset;

    public:
        		__fastcall 	TNavitarPresetFrame(NavitarPreset& p, TComponent* Owner);

};

extern PACKAGE TNavitarPresetFrame *NavitarPresetFrame;
#endif
