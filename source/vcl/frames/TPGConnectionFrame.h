#ifndef TPGConnectionFrameH
#define TPGConnectionFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TSTDStringLabeledEdit.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "mtkIniFile.h"
#include "mtkIniFileProperties.h"
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include "TArrayBotBtn.h"
#include "TPGDataModule.h"
//---------------------------------------------------------------------------

using mtk::IniFile;
using mtk::IniFileProperties;

class PACKAGE TPGConnectionFrame : public TFrame
{
    __published:	// IDE-managed Components
		TGroupBox *GBox1;
        TSTDStringLabeledEdit *mServerIPE;
        TSTDStringLabeledEdit *mDBUserE;
        TSTDStringLabeledEdit *mPasswordE;
        TSTDStringLabeledEdit *mDatabaseE;
	TActionList *PGConnectionsActions;
		TAction *ConnectA;
		TArrayBotButton *ArrayBotButton1;
		void __fastcall ConnectAExecute(TObject *Sender);
	void __fastcall GBox1Click(TObject *Sender);

    private:
		IniFile*				mIniFile;
		IniFileProperties       mProperties;
        void					updateUI();

    public:
                __fastcall 		TPGConnectionFrame(TComponent* Owner);
    	bool					init(IniFile* inifile, const string& iniFileSection);
        DBCredentials			getCredentials();
    	bool					writeParameters();
        void					afterConnect();
        void					afterDisconnect();
};

extern PACKAGE TPGConnectionFrame *PGConnectionFrame;
#endif
