#ifndef atHDMIStreamerProcessH
#define atHDMIStreamerProcessH
#include "mtkConstants.h"
#include "Poco/Process.h"
#include "Poco/PipeStream.h"
#include <functional>
#include <fstream>
#include "mtkThread.h"
#include "Poco/PipeStream.h"
#include "core/atATObject.h"
//---------------------------------------------------------------------------
using namespace mtk;
using Poco::Process;
using Poco::ProcessHandle;
using Poco::PipeInputStream;
using Poco::PipeOutputStream;
using Poco::Pipe;
using mtk::Thread;

typedef boost::function<void(int, int)> Callback;


//!The HDMIStreamer process manages a BlackMagic HDMI streamer process, BMStreamer.
//!The BMStreamer streams HDMI content to an anonomous pipe and, optionally to a file.
class AT_CORE HDMIStreamerProcess : public mtk::Thread
{
	public:
						                HDMIStreamerProcess(const string& bmExecutable = gEmptyString, const string& pipeName = gEmptyString);
						                ~HDMIStreamerProcess();
		bool							startStreaming();
		bool							stopStreaming();

		bool			                startRecording(const string& fName, int bitRate);
		bool			                stopRecording();

        bool			                setOutputFileFolder(const string& folder);
        bool			                setOutputFileName(const string& fName);
		void							assignCallBacks(Callback one, Callback two, Callback three);
		void							assignCallBacks2(Callback one, Callback two, Callback three);
        virtual void            		run();
        void							exit();

    private:
		string			                mBMStreamerExecutable;
        int								mBitRate;
        string			                mOutputFileName;
        bool							mStartStreamingRequest;
        bool							mStopStreamingRequest;
        bool							mIsStreaming;

	    Callback 						onEnter;
	    Callback 						onProgress;
	    Callback 						onExit;
	    Callback 						onEnter2;
	    Callback 						onProgress2;
	    Callback 						onExit2;
	    int								parseOutput(const string& str);
		PipeOutputStream* 				mOutStream;
};

#endif