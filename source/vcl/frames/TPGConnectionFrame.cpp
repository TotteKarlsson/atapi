#include <vcl.h>
#pragma hdrstop
#include "TPGConnectionFrame.h"
//#include "database/atDBUtils.h"
#include "mtkVCLUtils.h"
#include "mtkLogger.h"
#include "TPGDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TSTDStringLabeledEdit"
#pragma link "TArrayBotBtn"
#pragma resource "*.dfm"

TPGConnectionFrame *PGConnectionFrame;
using namespace mtk;
//using namespace at;

//---------------------------------------------------------------------------
__fastcall TPGConnectionFrame::TPGConnectionFrame(TComponent* Owner)
	: TFrame(Owner),
    mIniFile(NULL)
{
	ConnectA->Caption = "Connect";
}

bool TPGConnectionFrame::init(IniFile* inifile, const string& iniFileSection)
{
	mIniFile = inifile;
	if(!mIniFile)
    {
    	return false;
    }
    mProperties.setIniFile(mIniFile);

    mProperties.setSection(iniFileSection);
	mProperties.add((BaseProperty*)  &mServerIPE->getProperty()->setup( 	    "SERVER_IP",        		      	"127.0.0.1"));
	mProperties.add((BaseProperty*)  &mDBUserE->getProperty()->setup( 	    	"DB_USER_NAME",                   "none"));
	mProperties.add((BaseProperty*)  &mPasswordE->getProperty()->setup( 	    "DB_USER_PASSWORD",               "none"));
	mProperties.add((BaseProperty*)  &mDatabaseE->getProperty()->setup( 	    "DB_DB_NAME",    			        "none"));

	//Read from file. Create if file do not exist
	mProperties.read();

	//Update
    mDBUserE->update();
    mPasswordE->update();
    mDatabaseE->update();
	mServerIPE->update();
    return true;
}

bool TPGConnectionFrame::writeParameters()
{
	return mProperties.write();
}

void TPGConnectionFrame::afterConnect()
{
	ConnectA->Caption = "Disconnect";
}

void TPGConnectionFrame::afterDisconnect()
{
	ConnectA->Caption = "Connect";
}

//---------------------------------------------------------------------------
void __fastcall TPGConnectionFrame::ConnectAExecute(TObject *Sender)
{
	if(!pgDM)
    {
    	Log(lWarning) << "Datamodule not allocated";
        return;
    }

	if(pgDM->SQLConnection1 && pgDM->SQLConnection1->Connected)
    {
    	//Remove runtime indices
//    	TClientDataSet* cds = pgDM->specimenCDS;
//        if(cds && cds->IndexDefs)
//        {
//            cds->IndexDefs->Update();
////            for(int i = 0; i < cds->IndexDefs->Count; i++)
//			int count = 2;
//            for(int i = 0; i < count; i++)
//            {
//                String idxName = cds->IndexDefs->operator [](i)->Name;
//                Log(lDebug) <<"Removing index: "<< stdstr(idxName);
//                if(idxName != "DEFAULT_ORDER" && idxName != "CHANGEINDEX")
//                {
//                    try
//                    {
//                        Log(lDebug) <<"Removing index: "<< stdstr(idxName);
//                        //Something bizare is happening here on startup.
//                        cds->DeleteIndex(idxName);
//                    }
//                    catch(...)
//                    {
//                    }
//                }
//            }
//        }
	    pgDM->SQLConnection1->Connected = false;
	    pgDM->SQLConnection1->Close();
    }
    else
    {
	    pgDM->connect(mServerIPE->getValue(), mDBUserE->getValue(), mPasswordE->getValue(), mDatabaseE->getValue());
    }
}


