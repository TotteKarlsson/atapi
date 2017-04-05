#ifndef abProcessSequencerH
#define abProcessSequencerH
#include <list>
#include "atExporter.h"
#include "atATObject.h"
#include "atProcessSequence.h"
#include "mtkTimer.h"
#include "atProcessSequenceProject.h"
#include "atProcessSequences.h"

using mtk::Timer;
namespace at
{
	class Move;
}

class ArrayBot;
//!The Process sequencer executes and maintain a process sequence.
//!A sequence individual processes can be executed step by step, or executed
//!continously.
//!The sequencer do currently load all available sequences into a sequence container.
//Todo: Break out the sequence container to simplify the complexity of the sequencer
//---------------------------------------------------------------------------
class AT_CORE ProcessSequencer : public ATObject
{
	public:
			      	                        ProcessSequencer(ArrayBot& ab, const string& fileFolder);
                  	                        ~ProcessSequencer();

		bool						        selectSequence(const string& sName);

		bool				                load(const string& sName);
		bool				                loadAll(const string& fileFolder);
        bool								initCurrentSequence();

        bool						        deleteSequence(const string& seq);
		bool				                saveCurrent();
		void				                clear();

											//!Five main controlling actions..
		void		                        start(bool continous = true);
        void		                        stop();
		void		                        pause();
		bool 		                        resume();
		bool		                        forward();
//        bool		                        reverse();

		bool		                        reset();
		bool								continueExecution();

        bool								canContinue();
		string								getNextProcessName();

        bool				                isRunning();
        bool				                isPaused();
        bool				                isCurrentProcessActive();

        									//!After all processes are executed, the processsequence is done
        bool								isDone();

        ProcessSequence*   	                getCurrentSequence();
        string				                getCurrentSequenceName();
        string				                getCurrentProcessName();

        bool						        addSequence(ProcessSequence* seq);
        ProcessSequences&			        getSequences();

	private:
    								        //!The sequencer is executing each sequence using
                                            //an arrayBot object
    	ArrayBot&					        mAB;
    	ProcessSequences	                mSequences;

        							        //!ExecuteAutomatic executes individual processes
                                            //!in sequence. If set false, each sequence need to be
                                            //!manually executed using the forward() function
        bool				                mExecuteAutomatic;

        									//!The sequence time checks the state of the sequence
                                            //!and individual processes every 50 ms
        Timer				                mSequenceTimer;
		void			                    onTimerFunc();
};

#endif
