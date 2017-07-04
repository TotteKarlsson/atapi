#ifndef atQueryBuilderH
#define atQueryBuilderH
#include <sstream>
#include "atDBExporter.h"
#include "core/atATObject.h"
//---------------------------------------------------------------------------

class AT_DB QueryBuilder : public std::stringstream, public ATObject
{
	public:
		std::string				asString();
        const char* 			asCString();
        void					clear();

    protected:
};
#endif
