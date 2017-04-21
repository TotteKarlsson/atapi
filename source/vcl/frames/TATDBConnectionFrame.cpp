#include <vcl.h>
#pragma hdrstop
#include "TATDBConnectionFrame.h"
#include "database/atDBUtils.h"
#include "mtkVCLUtils.h"
#include "mtkLogger.h"
#include "TATDBDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma link "TSTDStringLabeledEdit"
#pragma resource "*.dfm"

TATDBConnectionFrame *ATDBConnectionFrame;
using namespace mtk;
using namespace at;

//---------------------------------------------------------------------------
__fastcall TATDBConnectionFrame::TATDBConnectionFrame(TComponent* Owner)
	: TFrame(Owner),
    mIniFile(NULL)
{
	mATDBServerBtnConnect->Caption = "Connect";
}

bool TATDBConnectionFrame::init(IniFile* inifile)
{
	mIniFile = inifile;
	if(!mIniFile)
    {
    	return false;
    }
    mProperties.setIniFile(mIniFile);

    mProperties.setSection("DB_CONNECTION");
	mProperties.add((BaseProperty*)  &mServerIPE->getProperty()->setup( 	    "MYSQL_SERVER_IP",              	"127.0.0.1"));
	mProperties.add((BaseProperty*)  &mDBUserE->getProperty()->setup( 	    	"ATDB_USER_NAME",                   "none"));
	mProperties.add((BaseProperty*)  &mPasswordE->getProperty()->setup( 	    "ATDB_USER_PASSWORD",               "none"));
	mProperties.add((BaseProperty*)  &mDatabaseE->getProperty()->setup( 	    "ATDB_DB_NAME",    			        "none"));

	//Read from file. Create if file do not exist
	mProperties.read();

	//Update
    mDBUserE->update();
    mPasswordE->update();
    mDatabaseE->update();
	mServerIPE->update();
    return true;
}

bool TATDBConnectionFrame::purge()
{
	return mProperties.write();
}

void __fastcall TATDBConnectionFrame::mATDBServerBtnConnectClick(TObject *Sender)
{
	if(atdbDM->SQLConnection1->Connected)
    {
    	//Remove runtime indices
    	TClientDataSet* cds = atdbDM->specimenCDS;
	    cds->IndexDefs->Update();
        for(int i = 0; i <cds->IndexDefs->Count; i++)
        {
            String idxName = cds->IndexDefs->operator [](i)->Name;
            Log(lDebug) <<"Removing index: "<< stdstr(idxName);
            if(idxName != "DEFAULT_ORDER" && idxName != "CHANGEINDEX")
            {
                cds->DeleteIndex(idxName);
            }
        }

	    atdbDM->SQLConnection1->Connected = false;
	    atdbDM->SQLConnection1->Close();
    }
    else
    {
	    atdbDM->connect(mServerIPE->getValue(), mDBUserE->getValue(), mPasswordE->getValue(), mDatabaseE->getValue());
    }
}

void TATDBConnectionFrame::afterConnect()
{
	mATDBServerBtnConnect->Caption = "Disconnect";
}

void TATDBConnectionFrame::afterDisconnect()
{
	mATDBServerBtnConnect->Caption = "Connect";
}
