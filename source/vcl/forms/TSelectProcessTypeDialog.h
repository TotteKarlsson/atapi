#ifndef TSelectProcessTypeDialogH
#define TSelectProcessTypeDialogH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

//---------------------------------------------------------------------------
class PACKAGE TSelectProcessTypeDialog : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TButton *mOkBtn;
	TRadioGroup *mProcTypeRG;
private:	// User declarations
public:		// User declarations
				__fastcall TSelectProcessTypeDialog(TComponent* Owner);
};


//---------------------------------------------------------------------------
extern PACKAGE TSelectProcessTypeDialog *SelectProcessTypeDialog;
//---------------------------------------------------------------------------
#endif
