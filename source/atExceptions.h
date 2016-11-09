#ifndef abExceptionsH
#define abExceptionsH
#include "atExporter.h"
#include "atABObject.h"
#include <exception>
#include <string>
#include <sstream>
//---------------------------------------------------------------------------
using std::string;
using std::stringstream;

class AT_CORE ABException : public std::exception, public ABObject
{
    public:
                                            ABException(const string& desc);
                                            ABException(const stringstream& msg);
        virtual                             ~ABException() throw();
        virtual const char*                 what() const throw();
        string                              Message() const;

    protected:
                                            //ABException message
        string                              mMessage;
};

#endif
