#ifndef atATObjectH
#define atATObjectH
#include "core/atCoreExporter.h"
#include <string>
//---------------------------------------------------------------------------
using std::string;

class AT_CORE ATObject
{
	public:
    							ATObject();
		virtual					~ATObject();
        virtual const string 	getTypeName() const;

	protected:

	private:
};
#endif
