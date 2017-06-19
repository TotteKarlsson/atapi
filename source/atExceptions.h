#ifndef abExceptionsH
#define abExceptionsH
#include "atCoreExporter.h"
#include "atATObject.h"
#include <exception>
#include <string>
#include <sstream>
//---------------------------------------------------------------------------
using std::string;
using std::stringstream;

class AT_CORE ATException : public std::exception, public ATObject
{
    public:
                                            ATException(const string& desc);
                                            ATException(const stringstream& msg);
        virtual                             ~ATException() throw();
        virtual const char*                 what() const throw();
        string                              Message() const;

    protected:
                                            //ATException message
        string                              mMessage;
};

#endif
