#ifndef abProcessSequenceProjectH
#define abProcessSequenceProjectH
#include "atExporter.h"
#include "mtkProject.h"
#include "mtkConstants.h"
#include "atProcess.h"
#include "atATObject.h"

//---------------------------------------------------------------------------
AT_CORE extern const string gProcessSequenceProjectFileVersion;

namespace tinyxml2
{
	class XMLElement;
}

class ProcessSequence;
class AbsoluteMove;
class ArduinoServerCommand;


class AT_CORE ProcessSequenceProject : public mtk::Project, public ATObject
{
    public:
                                                ProcessSequenceProject(ProcessSequence& ps, const string& fName = "Sequence 1.abp");
                                                ~ProcessSequenceProject();

        bool                                    save(const string& fName = mtk::gEmptyString);
        bool                                    open();
        string                                  getPresentModelVersion();

    protected:
        ProcessSequence&                        mProcessSequence;
        bool                                    resetXML();
        int                                     loadProcesses();

        Process*				                createProcess(tinyxml2::XMLElement* element);
		Process*								createParallellProcess(tinyxml2::XMLElement* element);
		Process*								createTimeDelayProcess(tinyxml2::XMLElement* element);
		Process*								createStopAndResumeProcess(tinyxml2::XMLElement* element);

		AbsoluteMove* 				  			createAbsoluteMoveFromXML(const string& name,  tinyxml2::XMLElement* proc);
		ArduinoServerCommand* 					createArduinoServerCommandFromXML(const string& name,  tinyxml2::XMLElement* proc);
};

#endif
