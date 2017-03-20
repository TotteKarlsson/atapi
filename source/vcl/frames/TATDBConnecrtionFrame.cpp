#include <vcl.h>
#pragma hdrstop
#include "TATDBConnecrtionFrame.h"
#include "atDBUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma link "TSTDStringLabeledEdit"
#pragma resource "*.dfm"
TATDBConnectionFrame *ATDBConnectionFrame;

using namespace at;
//---------------------------------------------------------------------------
__fastcall TATDBConnectionFrame::TATDBConnectionFrame(TComponent* Owner)
	: TFrame(Owner),
    mATDB(NULL)

{
}

void TATDBConnectionFrame::assignDBSession(ATDBServerSession& db)
{
	mATDB = &db;
}

void __fastcall TATDBConnectionFrame::mATDBServerBtnConnectClick(TObject *Sender)
{
	if(!mATDB)
    {
    	Log(lError) << "No session object in ATDBServer Frame";
    }

    if(mATDBServerBtnConnect->Caption != "Disconnect")
    {
        try
        {
            if(!mATDB->isConnected())
            {
                //const string& ip, const string& user, const string& pwd, const string& db)
                mATDB->connect(mServerIPE->getValue(), mDBUserE->getValue(), mPasswordE->getValue(),mDatabaseE->getValue());
            }

            if(mATDB->isConnected())
            {
                Log(lInfo) << "Connected to database: "<<mDatabaseE->getValue()<<" on host with IP: "<<mServerIPE->getValue();
    //            populateUsersCB(mUsersCB, mClientDBSession);
                mATDBServerBtnConnect->Caption = "Disconnect";
            }
            else
            {
                Log(lError) << "Failed to connect to database server...";
                mATDBServerBtnConnect->Caption = "Connect";
            }
        }
        catch(...)
        {
            handleMySQLException();
        }
    }
    else
    {
	    if(mATDB->disConnect())
        {
                //const string& ip, const string& user, const string& pwd, const string& db)
        	mATDBServerBtnConnect->Caption = "Connect";
        }
    }
}

