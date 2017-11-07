#pragma hdrstop
#include "TPGCoverSlipDataModule.h"
#include "mtkLogger.h"
//#include "TATDBDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
TcsPGDM *csPGDM;
using namespace mtk;

//---------------------------------------------------------------------------
__fastcall TcsPGDM::TcsPGDM(TComponent* Owner)
	: TDataModule(Owner),
    csDustAssayCDSOnDataChanged(NULL)
{
}

void __fastcall TcsPGDM::afterConnect(TSQLConnection *c)
{
	Log(lInfo) << "Initializing coverslip datamodule";

	if(!c)
    {
    	return;
    }
    csDS->SQLConnection = c;
    csStatusDS->SQLConnection = c;
    csTypeDS->SQLConnection = c;
    csDustAssayDS->SQLConnection = c;
    csFreshBatchesDS->SQLConnection = c;

    csCDS->Active 				= true;
    csStatusCDS->Active 		= true;
    csTypeCDS->Active 			= true;
    csDustAssayCDS->Active 		= true;
    csFreshBatchesCDS->Active 	= true;
}

void __fastcall TcsPGDM::afterDisConnect()
{}

//---------------------------------------------------------------------------
void __fastcall TcsPGDM::csDSBeforeOpen(TDataSet *DataSet)
{
//	Log(lInfo) <<"Opening coverslip dataset";
}

//---------------------------------------------------------------------------
void __fastcall TcsPGDM::CDSAfterPost(TDataSet *DataSet)
{
	TClientDataSet* cds = dynamic_cast<TClientDataSet*>(DataSet);

    if(!cds)
    {
    	return;
    }

	cds->ApplyUpdates(0);
    cds->Refresh();
}

void __fastcall TcsPGDM::CDSAfterDelete(TDataSet *DataSet)
{
	TClientDataSet* cds = dynamic_cast<TClientDataSet*>(DataSet);

    if(!cds)
    {
    	return;
    }

	cds->ApplyUpdates(0);
    cds->Refresh();
}

//---------------------------------------------------------------------------
void __fastcall TcsPGDM::CDSAfterScroll(TDataSet *DataSet)
{
 	if(DataSet == csCDS)
    {
    	if(csDustAssayCDS->Active)
        {
        	csDustAssayCDS->Refresh();
        }

//        if(atdbDM->ROnCS_CDS->Active)
//        {
//			atdbDM->ROnCS_CDS->Refresh();
//        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TcsPGDM::csDustAsssayDSourceDataChange(TObject *Sender, TField *Field)
{
	if(csDustAssayCDSOnDataChanged)
    {
    	csDustAssayCDSOnDataChanged(Sender);
    }
}
