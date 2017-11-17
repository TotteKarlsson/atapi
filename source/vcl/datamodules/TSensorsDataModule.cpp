#pragma hdrstop
#include "TSensorsDataModule.h"
#include "TPGDataModule.h"
#include "mtkLogger.h"
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

using namespace mtk;
TSensorsDataModule *sensorsDM;

//---------------------------------------------------------------------------
__fastcall TSensorsDataModule::TSensorsDataModule(TComponent* Owner)
	: TDataModule(Owner)
{}

//---------------------------------------------------------------------------
bool TSensorsDataModule::insertSensorData(int sensorID, double val1, double val2)
{
    if(!pgDM || pgDM->SQLConnection1->Connected == false)
    {
        Log(lError) << "No DB Session...";
        return false;
    }

    //Create some local variables
    int sensor_id(sensorID);

    //Add image to database
    //Make sure the barcode exists in the database..
    static TSQLQuery* tq = new TSQLQuery(NULL);
    tq->SQLConnection = pgDM->SQLConnection1;
    tq->SQLConnection->AutoClone = false;
    stringstream q;
    q <<"INSERT INTO sensordata (sensor_id, data1, data2) VALUES ('"
                <<sensor_id<<"', '"
                <<val1<<"', '"
                <<val2
                <<"')";

    string s(q.str());
    Log(lDebug) <<"Sensor Data Insertion Query: "<<s;
    tq->SQL->Add(q.str().c_str());
    tq->ExecSQL();
    tq->Close();
    tq->SQL->Clear();
    q.str("");

	return true;
}


