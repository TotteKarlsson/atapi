#ifndef atATObjectH
#define atATObjectH
//#include "core/atCoreExporter.h"
#include <string>
//---------------------------------------------------------------------------
using std::string;

int MyTest(int r);

class ATObject
{
	public:
    							ATObject();
		virtual					~ATObject();
        virtual const string 	getTypeName() const;

	protected:

	private:
};
#endif
