#pragma hdrstop
#include "atProcessSequenceProject.h"
#include "mtkXMLUtils.h"
#include "mtkLogger.h"
#include "atProcessSequence.h"
#include "atParallellProcess.h"
#include "atArrayBot.h"
#include "apt/atAbsoluteMove.h"
#include "apt/atMove.h"
#include "atTimedelay.h"
#include "atStopAndResumeProcess.h"
#include "atArrayCamRequestProcess.h"
#include "apt/atAPTMotor.h"
#include "atTriggerFunction.h"
#include "arduino/atArduinoServerCommand.h"

using namespace mtk;
using namespace tinyxml2;

//XML Version history
/*
    0.5 : Original version
*/

const string gProcessSequenceProjectFileVersion    = "0.6";

ProcessSequenceProject::ProcessSequenceProject(ProcessSequence& ps, ArrayCamClient& ac, const string& fName)
:
Project(fName, "abp"),
mProcessSequence(ps),
mArrayCamClient(ac)
{
	resetXML();
}

ProcessSequenceProject::~ProcessSequenceProject()
{}

string ProcessSequenceProject::getPresentModelVersion()
{
    return gProcessSequenceProjectFileVersion;
}

bool ProcessSequenceProject::resetXML()
{
	mTheXML.Clear();
    mProjectRoot = mTheXML.NewElement("sequence_project");
    mRootNode = mTheXML.InsertFirstChild(mProjectRoot);

    //Insert as a minimum project file version
    XMLElement* version = mTheXML.NewElement("version");
    XMLText* 	versionValue = mTheXML.NewText(gProcessSequenceProjectFileVersion.c_str());
    version->InsertEndChild(versionValue);
    mProjectRoot->InsertEndChild(version);

    XMLElement* name 		= mTheXML.NewElement("name");
    XMLText* 	nameValue 	= mTheXML.NewText(mProcessSequence.getName().c_str());
	name->InsertEndChild(nameValue);
    mProjectRoot->InsertEndChild(name);
    return true;
}

bool ProcessSequenceProject::save(const string& fName)
{
    resetXML();

    //For now, do a brute force save of Moleculix Objects
    XMLElement* sequence = newElement("sequence");
	sequence->SetAttribute("category", mProcessSequence.getCategory().c_str());

    //First save Processes
    Process* p = mProcessSequence.getFirst();
    while(p)
    {
        Log(lDebug) << "Saving process: " << p->getProcessName();
        XMLElement* xmlProc = p->addToXMLDocument(mTheXML, sequence);
        if(dynamic_cast<ParallellProcess*>(p))
	    {
        	ParallellProcess* clm = dynamic_cast<ParallellProcess*>(p);

        	//Write subprocesses
			clm->addToXMLDocumentAsChild(mTheXML, xmlProc);
        }

        else if(dynamic_cast<TimeDelay*>(p))
	    {
        	TimeDelay* td = dynamic_cast<TimeDelay*>(p);

        	//Write subprocesses
			td->addToXMLDocumentAsChild(mTheXML, xmlProc);
        }

        else if(dynamic_cast<StopAndResumeProcess*>(p))
	    {
        	StopAndResumeProcess* td = dynamic_cast<StopAndResumeProcess*>(p);

        	//Write subprocesses
			td->addToXMLDocumentAsChild(mTheXML, xmlProc);
        }

        else if(dynamic_cast<ArrayCamRequestProcess*>(p))
	    {
        	ArrayCamRequestProcess* td = dynamic_cast<ArrayCamRequestProcess*>(p);

        	//Write subprocesses
			td->addToXMLDocumentAsChild(mTheXML, xmlProc);
        }

        p = mProcessSequence.getNext();
    }

    this->addNode(sequence);

    //Convoluted code
    if(fName.size() != 0)
    {
    	return saveToFile(fName);
    }
    else
    {
    	return saveToFile(joinPath(mFileFolder, getFileNameNoPath(mFileName)));
    }
}

bool ProcessSequenceProject::open()
{
    try
    {
        Log(lInfo) << "Attempting to load model: "<<this->getFileName();

        //Read the name node
        int nrOfObjs = loadProcesses();
        Log(lDebug) << "Loaded " << nrOfObjs << " process objects";
        return true;
    }
    catch(...)
    {
        throw("Bad model file!");
    }
}

int ProcessSequenceProject::loadProcesses()
{
    //This function creates proceses XML
    XMLElement* sequence = this->getXML("sequence");

    if(sequence == NULL)
    {
        return 0;
    }

	string category = sequence->Attribute("category");
    mProcessSequence.setCategory(category);

    int nrOfObjects = 0;

     //Load process by process
    XMLElement* p = sequence->FirstChildElement();
    while(p)
    {
        //Find out what kind of element p is
        Process* aProc = createProcess(p);

        if(aProc)
        {
            mProcessSequence.add(aProc);
            Log(lDebug) <<"Imported process: "<<aProc->getProcessName()<<" of type: "<<aProc->getTypeName();
            nrOfObjects++;
        }
        else
        {
            Log(lError) << "Failed importing a "<<p->Name()<<" process";
        }

        p = p->NextSiblingElement();
    }

    return nrOfObjects;
}

Process* ProcessSequenceProject::createProcess(tinyxml2::XMLElement* element)
{
    if(!element && !compareStrings(element->Name(), "process", csCaseInsensitive))
    {
    	Log(lError) <<"Bad 'createProcess' xml!";
    	return NULL;
    }

  	//What processtype?
	ProcessType pt = toProcessType(element->Attribute("type"));
    switch(pt)
    {
    	case ptParallell: 				        return createParallellProcess(element);
        case ptTimeDelay:       		        return createTimeDelayProcess(element);
        case ptStopAndResumeProcess:	        return createStopAndResumeProcess(element);
        case ptArrayCamRequestProcess:			return createArrayCamRequestProcess(element);
    }

    return NULL;
}

ParallellProcess* ProcessSequenceProject::createParallellProcess(XMLElement* element)
{
    ParallellProcess* p = new ParallellProcess(element->Attribute("name"));
    p->assignProcessSequence(&mProcessSequence);

    //Read data
    XMLElement* proc = element->FirstChildElement("process");
    if(proc)
    {
        //Loop over childs
        while(proc)
        {
            const char* type = proc->Attribute("type");
            const char* name = proc->Attribute("name");

            if(name)
            {
                Log(lDebug) << "Loading process with name: "<<name<<" and type: "<<type;

                if(toProcessType(type) == ptAbsoluteMove)
                {
                	AbsoluteMove* absMove = createAbsoluteMove(proc);
    				absMove->assignProcessSequence(&mProcessSequence);

                    //We need to associate the motor with 'name' with a
                    //real motor object provided for by ArrayBot
                    absMove->assignUnit(mProcessSequence.getArrayBot());
                    p->addProcess(absMove);
                }

                else if(toProcessType(type) == ptArrayCamRequestProcess)
                {
                	ArrayCamRequestProcess* c = createArrayCamRequestProcess(proc);
    				c->assignProcessSequence(&mProcessSequence);
                    p->addProcess(c);
                }

                else if(toProcessType(type) == ptArduinoServerCommand)
                {
                	ArduinoServerCommand* c = createArduinoServerCommand(proc);
    				c->assignProcessSequence(&mProcessSequence);
                    p->addProcess(c);
                }

            }
            proc = proc->NextSiblingElement();
        }
    }
    return p;
}

AbsoluteMove* ProcessSequenceProject::createAbsoluteMove(XMLElement* element)
{
   	string name = element->Attribute("name");
	AbsoluteMove* absMove = new AbsoluteMove(name);
    XMLElement* data = element->FirstChildElement("info");
    if(data && data->GetText())
    {
        absMove->setInfoText(data->GetText());
    }

    data = element->FirstChildElement("motor_name");
    if(data && data->GetText())
    {
        absMove->setSubjectName(data->GetText());
    }

    data = element->FirstChildElement("final_position");
    if(data && data->GetText())
    {
        absMove->setPosition(toDouble(data->GetText()));
    }

    data = element->FirstChildElement("max_velocity");
    if(data && data->GetText())
    {
        absMove->setMaxVelocity(toDouble(data->GetText()));
    }

    data = element->FirstChildElement("acc");
    if(data && data->GetText())
    {
        absMove->setAcceleration(toDouble(data->GetText()));
    }

    data = element->FirstChildElement("pre_dwell_time");
    if(data && data->GetText())
    {
        absMove->setPreDwellTime(toDouble(data->GetText()));
    }

    data = element->FirstChildElement("post_dwell_time");
    if(data && data->GetText())
    {
        absMove->setPostDwellTime(toDouble(data->GetText()));
    }

    //Load the trigger
    data = element->FirstChildElement("trigger");

    if(data)
    {
        const char* ttype = data->Attribute("type");
        if(ttype && compareNoCase(ttype, "positionalTrigger"))
        {
            PositionalTrigger* pt = new PositionalTrigger(NULL);
            absMove->addTrigger(pt);

            XMLElement* e = data->FirstChildElement("position");
            if(e)
            {
                pt->setPosition(toDouble(e->GetText()));
            }

            e = data->FirstChildElement("operator");
            if(e)
            {
                pt->setTestOperator(toLogicOperator(e->GetText()));
            }

            //Load trigger function(s)
            //Load the trigger
            XMLElement* tfData = data->FirstChildElement("trigger_function");
            if(tfData)
            {
                const char* type = tfData->Attribute("type");
                if(type && compareNoCase(type, "absoluteMove"))
                {
                    MoveAbsolute* tf = new MoveAbsolute(NULL, 0,0,0);

                    const char* mtrName = tfData->Attribute("motor_name");
                    tf->setMotorName(mtrName);
                    pt->assignTriggerFunction(tf);

                    XMLElement* e = tfData->FirstChildElement("final_position");
                    if(e && e->GetText())
                    {
                        tf->setPosition(toDouble(e->GetText()));
                    }

                    e = tfData->FirstChildElement("max_velocity");
                    if(e && e->GetText())
                    {
                        tf->setVelocity(toDouble(e->GetText()));
                    }

                    e = tfData->FirstChildElement("acceleration");
                    if(e && e->GetText())
                    {
                        tf->setAcceleration(toDouble(e->GetText()));
                    }
                }
            }
        }
    }
    return absMove;
}

TimeDelay* ProcessSequenceProject::createTimeDelayProcess(XMLElement* element)
{
    TimeDelay* p = new TimeDelay("");

   	p->setProcessName(element->Attribute("name"));
    XMLElement* delay = element->FirstChildElement("delay");
    if(delay)
    {
    	p->setTimeDelay(toInt(delay->GetText()));
    }
   	else
    {
    	p->setTimeDelay(-1);
    }

    return p;
}

StopAndResumeProcess* ProcessSequenceProject::createStopAndResumeProcess(XMLElement* element)
{
    StopAndResumeProcess* p = new StopAndResumeProcess("");
   	p->setProcessName(element->Attribute("name"));
    return p;
}

ArrayCamRequestProcess* ProcessSequenceProject::createArrayCamRequestProcess(XMLElement* element)
{
   	string name = element->Attribute("name");
    XMLElement* request = element->FirstChildElement("request");
    ArrayCamRequestProcess* p = new ArrayCamRequestProcess(mArrayCamClient, name, request->GetText());
    return p;
}

ArduinoServerCommand* ProcessSequenceProject::createArduinoServerCommand(XMLElement* element)
{
   	string name = element->Attribute("name");
	ArduinoServerCommand* c = new ArduinoServerCommand(name);

    XMLElement* data = element->FirstChildElement("command");
    if(data && data->GetText())
    {
        c->setCommand(data->GetText());
    }
	return c;
}

