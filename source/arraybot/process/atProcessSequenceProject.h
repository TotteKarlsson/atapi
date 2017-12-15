#ifndef atProcessSequenceProjectH
#define atProcessSequenceProjectH
#include "arraybot/atABExporter.h"
#include "mtkProject.h"
#include "mtkConstants.h"
#include "core/atProcess.h"
#include "core/atATObject.h"

//---------------------------------------------------------------------------
AT_AB extern const string gProcessSequenceProjectFileVersion;

namespace tinyxml2
{
	class XMLElement;
}

class ArrayCamClient;
class ProcessSequence;
class AbsoluteMove;
class StopAndResumeProcess;
class ArrayCamRequestProcess;
class TimeDelay;
class ParallelProcess;
class ArduinoServerCommand;
class MoveCoverSlipAtAngleProcess;
class HomeMotor;

//!A ProcessSequenceProject makes it possible to save and load a ProcessSequence to file, using a simple xml format.
class AT_AB ProcessSequenceProject : public mtk::Project, public ATObject
{
	friend ArrayCamRequestProcess;
    public:
                                                ProcessSequenceProject(ProcessSequence& ps, ArrayCamClient& ac, const string& fName = "Sequence 1.abp");
                                                ~ProcessSequenceProject();

        bool                                    save(const string& fName = mtk::gEmptyString);
        bool                                    open();
        string                                  getPresentXMLModelVersion();

    protected:
        ProcessSequence&                        mProcessSequence;
        ArrayCamClient&							mArrayCamClient;
        bool                                    resetXML();
        int                                     loadProcesses();

        Process*				                createProcess(tinyxml2::XMLElement* element);
		ParallelProcess*						createParallelProcess(tinyxml2::XMLElement* element);
		AbsoluteMove* 				  			createAbsoluteMove(tinyxml2::XMLElement* proc);
		TimeDelay*								createTimeDelayProcess(tinyxml2::XMLElement* element);
		StopAndResumeProcess*					createStopAndResumeProcess(tinyxml2::XMLElement* element);
		ArrayCamRequestProcess* 				createArrayCamRequestProcess(tinyxml2::XMLElement* element);
		ArduinoServerCommand* 					createArduinoServerCommand(tinyxml2::XMLElement* proc);
		MoveCoverSlipAtAngleProcess* 			createMoveCoverSlipAtAngleProcess(tinyxml2::XMLElement* proc);
		HomeMotor* 								createHomeMotorProcess(tinyxml2::XMLElement* proc);
};

#endif
