#ifndef TNavitarPresetFrameH
#define TNavitarPresetFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TIntegerLabeledEdit.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

class NavitarMotorController;
class PACKAGE TNavitarPresetFrame : public TFrame
{
    __published:	// IDE-managed Components
        TIntegerLabeledEdit *FocusPos;
        TIntegerLabeledEdit *ZoomPos;
        TGroupBox *GroupBox1;
        TButton *GoButton;
	void __fastcall GoButtonClick(TObject *Sender);
    private:
		NavitarMotorController* 		mController;

    public:
        		__fastcall 	TNavitarPresetFrame(TComponent* Owner);
        void		   		populate(NavitarMotorController& c);
};

extern PACKAGE TNavitarPresetFrame *NavitarPresetFrame;
#endif
