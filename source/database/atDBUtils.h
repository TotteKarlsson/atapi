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

}
#endif
