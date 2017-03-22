#ifndef abProcessSequencesH
#define abProcessSequencesH
#include "atExporter.h"
#include "atATObject.h"
#include <deque>
#include "atProcessSequence.h"
#include "mtkConstants.h"

//---------------------------------------------------------------------------
using std::deque;
using namespace mtk;

class ProcessSequencer;

class AT_CORE ProcessSequences : public ATObject
{
	public:
								                    ProcessSequences(const string& fileFolder, const string& fileExtension, ArrayBot& ab);
								                    ~ProcessSequences();
		bool										setFileFolder(const string& fileFolder);
        string										getFileFolder();
        int											loadAll(const string& fileFolder = gEmptyString);

		bool					                    add(ProcessSequence* s);
        bool					                    remove(const string& lbl);

	   	ProcessSequence*							select(ProcessSequence* s);
	   	ProcessSequence*							select(const string& sName);

        ProcessSequence*                            getFirst() const;
        ProcessSequence*                            getNext() const;
        ProcessSequence*                            getPrevious() const;
        ProcessSequence*                            getCurrent() const;
		string										getCurrentSequenceName();

        											//!Loads a process sequence from file.
                                                    //Files have the same name as the
                                                    //sequence itself
        bool										load(const string& fName);

        int											count(){return mProcessSequences.size();}
        bool										clear();
		bool										saveCurrent();

	protected:
    												//!ArrayBot provide "unit"s that are used by the processes
    	ArrayBot&									mAB;
    	mutable deque<ProcessSequence*> 			mProcessSequences;
    	mutable deque<ProcessSequence*>::iterator 	mProcessSequencesIter;
        string										mFileFolder;
        string										mFileExtension;
};
#endif
