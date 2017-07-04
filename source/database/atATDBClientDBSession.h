#ifndef abATDBClientDBSessionH
#define abATDBClientDBSessionH
#include "atDBExporter.h"
#include "core/atATObject.h"
#include "atDBUtils.h"
#include <deque>
#include "atDBConnection.h"
//---------------------------------------------------------------------------
namespace Poco
{
	namespace Data
    {
        class RecordSet;
        class Session;
    }
}
using Poco::Data::RecordSet;
using Poco::Data::Session;


//!The ATDB server session class encapsulate a database session
//!with the ATDB MySQL database
class AT_DB ATDBClientDBSession : public DBConnection
{
    public:
					        	        ATDBClientDBSession(const string& db, const string& host="127.0.0.1", const string& user="atdb_client", const string& password="atdb123");
					        	        ~ATDBClientDBSession();

										//!Statements
		bool							insertImageFile(const string& fName, int userID, const string& note="");
		bool							insertImageNote(int imageID, int userID, const string& note="");

        bool							insertSensorData(int id, double t, double h);
		RecordSet* 	    				getBlocks(at::dbSQLKeyword kw =at::dbDescending);

        bool							insertBlock(int userID, const string& lbl, const string& note);
        bool							deleteBlock(int bId);

        								//Users
		RecordSet* 	   					getUsers(at::dbSQLKeyword kw = at::dbAscending);

        								//!Maintain user id from server
        bool							insertOrUpdateUser(int uid, const string& u);

    protected:
};
#endif
