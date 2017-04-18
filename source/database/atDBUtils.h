#ifndef abDBUtilsH
#define abDBUtilsH
#include "atExporter.h"
#include <string>
//---------------------------------------------------------------------------

namespace at
{

enum dbSQLKeyword {dbAscending = 0, dbDescending};
std::string AT_CORE toString(dbSQLKeyword kw);


//!MySQL stuff
void AT_CORE handleMySQLException();


//!SQLite stuff
void AT_CORE handleSQLiteException();

//ATDB enums, especially lookup table values

enum CoversSlipStatusE
{
	cssFreshOutOfTheBox = 1,
    cssPostEhtanolClean = 2,
    cssPostPlasmaClean 	= 3,
    cssPostSilanization = 4,
    cssPostCarbonCoat 	= 5,
    cssPostSectioning 	= 6,
    cssPostMounting 	= 7,
    cssDiscarded 		= 8
};

};

#endif
