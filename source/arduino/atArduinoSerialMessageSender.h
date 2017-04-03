#ifndef atArduinoSerialMessageSenderH
#define atArduinoSerialMessageSenderH
#include "atExporter.h"
#include <string>
#include "mtkThread.h"
#include "atATObject.h"

//---------------------------------------------------------------------------
class ArduinoDevice;
using mtk::gEmptyString;

//!The message sender manages the Arduino's serial output queue in a thread.
//!When a message is posted onto the queue, the thread is awakened and
//!the message, or messages are sent one by one over the serial port.
//!A delay, ProcessTimeDelay can be used in order to no overflow the serial
//!devices input buffer
class AT_CORE ArduinoSerialMessageSender : public mtk::Thread, public ATObject
{
    public:
                                                    ArduinoSerialMessageSender(ArduinoDevice& d);
                                                    ~ArduinoSerialMessageSender();

                                                    // overridden from Thread
        void                                        run();

        bool                                        start(bool in_thread = true);
        void                                        stop();

	protected:
        double										mProcessTimeDelay;
		ArduinoDevice&             					mTheArduino;
};

#endif
