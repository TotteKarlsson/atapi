#ifndef atATObjectH
#define atATObjectH
#include "core/atCoreExporter.h"
#include <string>
//---------------------------------------------------------------------------
using std::string;

AT_CORE int MyTest(int r);

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
