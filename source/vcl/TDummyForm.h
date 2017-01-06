//---------------------------------------------------------------------------
#ifndef TDummyFormH
#define TDummyFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Datasnap.DBClient.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <vector>
#include <string>
//---------------------------------------------------------------------------


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TClientDataSet *ClientDataSet1;
	void __fastcall DBGrid1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
