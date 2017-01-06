//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TDummyForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
using namespace std;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::DBGrid1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
;
}
//---------------------------------------------------------------------------

