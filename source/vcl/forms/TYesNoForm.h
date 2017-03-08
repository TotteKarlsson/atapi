#ifndef TYesNoFormH
#define TYesNoFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TArrayBotBtn.h"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TYesNoForm : public TForm
{
__published:	// IDE-managed Components
	TArrayBotButton *mYesBtn;
	TArrayBotButton *mNoBtn;
	TLabel *mInfoLabel;
private:	// User declarations

public:		// User declarations
	__fastcall TYesNoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TYesNoForm *YesNoForm;
//---------------------------------------------------------------------------
#endif
