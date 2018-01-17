#ifndef atHDMIStreamerProcessH
#define atHDMIStreamerProcessH
#include "mtkConstants.h"
#include "Poco/Process.h"
#include "Poco/PipeStream.h"
#include <fstream>
//---------------------------------------------------------------------------
using namespace mtk;
using Poco::Process;
using Poco::ProcessHandle;
using Poco::PipeInputStream;
using Poco::Pipe;

//!The HDMIStreamer process manages a BlackMagic HDMI streamer process, BMStreamer.
//!The BMStreamer streams HDMI content to an anonomous pipe and, optionally to a file.
class HDMIStreamerProcess
{
	public:
						                HDMIStreamerProcess(const string& bmExecutable = gEmptyString, const string& pipeName = gEmptyString);
		bool							startStreaming();
		bool							stopStreaming();

		bool			                startRecording(const string& fName);
		bool			                stopRecording(const string& fName);

        bool			                setOutputFileFolder(const string& folder);
        bool			                setOutputFileName(const string& fName);


    private:
		string			                mBMStreamerExecutable;
        string			                mStreamPipeName;
        string			                mOutputFileFolder;
        string			                mOutputFileName;
        ProcessHandle*	                mStreamProcHandle;
        Pipe							mOutPipe;
        PipeInputStream 				mProcessMessages;



};

#endif
