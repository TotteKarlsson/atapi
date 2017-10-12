#ifndef TATDBConnectionFrameH
#define TATDBConnectionFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "components/TArrayBotBtn.h"
#include "TSTDStringLabeledEdit.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "mtkIniFile.h"
#include "mtkIniFileProperties.h"
#include "TArrayBotBtn.h"
//---------------------------------------------------------------------------

using mtk::IniFile;
using mtk::IniFileProperties;
class PACKAGE TATDBConnectionFrame : public TFrame
{
    __published:	// IDE-managed Components
	TGroupBox *GBox1;
        TSTDStringLabeledEdit *mServerIPE;
        TSTDStringLabeledEdit *mDBUserE;
        TSTDStringLabeledEdit *mPasswordE;
        TArrayBotButton *mATDBServerBtnConnect;
        TSTDStringLabeledEdit *mDatabaseE;
        void __fastcall mATDBServerBtnConnectClick(TObject *Sender);

    private:
		IniFile*				mIniFile;
		IniFileProperties       mProperties;

    public:
                __fastcall 		TATDBConnectionFrame(TComponent* Owner);
    	bool					init(IniFile* inifile);
    	bool					purge();
        void					afterConnect();
        void					afterDisconnect();
};

extern PACKAGE TATDBConnectionFrame *ATDBConnectionFrame;
#endif
