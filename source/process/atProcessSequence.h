#ifndef abProcessSequenceH
#define abProcessSequenceH
#include "atExporter.h"
#include "atATObject.h"
#include <list>
#include <deque>
#include <string>
#include "mtkINISection.h"
#include "mtkProperty.h"
#include "atProcessSequenceProject.h"
#include "mtkConstants.h"
//---------------------------------------------------------------------------

using std::list;
using std::deque;
using std::string;
using mtk::IniSection;
using mtk::Property;
class Process;
class ArrayBot;

//!A ProcessSequence maintains a list of processes
//!The processsequencer takes a ProcessSequences as input and executes inidividual processes
//!from the sequence

class AT_CORE ProcessSequence : public ATObject
{
    public:
										    ProcessSequence(ArrayBot& ab, ArrayCamClient& ac, const string& name = "", const string& fileExt = "proc");
				        		            ~ProcessSequence();
					        		        ProcessSequence(const ProcessSequence& s);

                                            //!Init the sequence brings all processes into their
                                            //!initial state. Required if a sequence is to be rerun
                                            //!init and reset are synonomous
		void								init();

		void					            clear();
        string								getName(){return mProject.getProjectName();}

        virtual bool	 		            read(const string& fName);
        virtual bool			            write(const string& folder = mtk::gEmptyString);

		virtual bool	   		            assignSubject(ATObject* o);

		virtual bool 			            add(Process* p);

        Process*							peekNext();
		bool 					            remove(Process* p);
		bool 					            remove(const string& lbl);

		bool								isFirst(Process* p);
        Process*                 	        getFirst() const;
        Process*                          	getNext() const;
        Process*                          	getPrevious() const;
        Process*                          	getCurrent() const;
        bool								selectProcess(Process* p);

        void								setProjectName(const string& name);
        void								setFileFolder(const string& f);
		void								setFileName(const string& f);
        void								setFileExtension(const string& e);
		string								getFileName();
        string 								getFileFolder();
        int									getNumberOfProcesses(){return mProcesses.size();}
        ArrayBot*							getArrayBot(){return &mAB;}

        bool								moveForward(Process* ps);
        bool								moveBack(Process* ps);

    protected:
    	ArrayBot&							mAB;
	    ProcessSequenceProject	 			mProject;

        									//!List of abstract Processes
		mutable list<Process*>  			mProcesses;
        mutable list<Process*>::iterator 	mProcessIter;
};
#endif
