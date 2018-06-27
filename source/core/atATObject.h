#ifndef atATObjectH
#define atATObjectH
#include <string>
#include "atCoreExporter.h"
//---------------------------------------------------------------------------

using std::string;
AT_CORE int MyTest(int r);

typedef unsigned int uint;

class AT_CORE ATObject
{
	public:
    							 ATObject(){}
		virtual					~ATObject() = 0;
        virtual const string 	getTypeName() const;

	protected:
	private:
};

#endif
