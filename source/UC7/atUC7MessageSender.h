#ifndef atUC7MessageSenderH
#define atUC7MessageSenderH
#include "atExporter.h"
#include <string>
#include "mtkThread.h"
#include "atATObject.h"

//---------------------------------------------------------------------------
class UC7;
using mtk::gEmptyString;

//!The message sender manages the UC7's serial output queue in a thread.
//!When a message is posted onto the queue, the thread is awakened and
//!the message, or messages are sent one by one over the serial port.
//!A delay, ProcessTimeDelay can be used in order to no overflow the serial
//!devices input buffer
class AT_CORE UC7MessageSender : public ABObject, public mtk::Thread
{
    public:
                                                    UC7MessageSender(UC7& uc7);
                                                    ~UC7MessageSender();

                                                    // overridden from Thread
        void                                        run();

        bool                                        start(bool in_thread = true);
        void                                        stop();

	protected:
        double										mProcessTimeDelay;
		UC7&                      					mUC7;
};

#endif
