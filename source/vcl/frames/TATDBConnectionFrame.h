#ifndef TATDBConnectionFrameH
#define TATDBConnectionFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TArrayBotBtn.h"
#include "TSTDStringLabeledEdit.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "atATDBServerSession.h"
//---------------------------------------------------------------------------

class TATDBConnectionFrame : public TFrame
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TSTDStringLabeledEdit *mServerIPE;
	TSTDStringLabeledEdit *mDBUserE;
	TSTDStringLabeledEdit *mPasswordE;
	TArrayBotButton *mATDBServerBtnConnect;
	TSTDStringLabeledEdit *mDatabaseE;
	void __fastcall mATDBServerBtnConnectClick(TObject *Sender);
private:	// User declarations
		ATDBServerSession*					mATDB;


public:		// User declarations
			__fastcall 		TATDBConnectionFrame(TComponent* Owner);
    void					assignDBSession(ATDBServerSession& db);
};

extern PACKAGE TATDBConnectionFrame *ATDBConnectionFrame;
#endif
