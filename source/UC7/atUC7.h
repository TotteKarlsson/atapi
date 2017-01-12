#ifndef atUC7H
#define atUC7H
#include "atABObject.h"
#include "mtkProperty.h"
#include "serial/atSerial.h"
//---------------------------------------------------------------------------

namespace mtk
{
	class IniFile;
}

using mtk::Property;
class AT_CORE UC7 : public ABObject
{
	public:
										UC7();
										~UC7();

		bool							connect(int comPort);
        bool							disConnect();
        bool							isConnected();

        string							getVersion();

    protected:
        string							mINIFileSection;
        int								mCOMPort;
    	Serial							mSerial;
};

#endif
