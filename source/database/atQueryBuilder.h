#ifndef atQueryBuilderH
#define atQueryBuilderH
#include <sstream>
#include "atExporter.h"
#include "atATObject.h"
//---------------------------------------------------------------------------

class AT_CORE QueryBuilder : public std::stringstream, public ATObject
{
	public:
		std::string				asString();
        const char* 			asCString();
        void					clear();

    protected:
};
#endif
