// atexplorer.i 

%module atexplorer

namespace std 
{    
//    class fstream{}; 
//    class stringstream{}; 
}

////Suppres warnings of "nothing known about"
//namespace tinyxml2
//{
//	class XMLNode;
//	class XMLElement;
//	class XMLDocument;
//}

namespace dsl 
{ 
    //class DSLObject{};
//    class SQLite{};
    //class dslExplorer{};
}

 %{
// #include <vector>
 #include "atATObject.h"
//using std::vector;
//using namespace dsl;
 %}
 
//%include "std_string.i"
//%include "std_vector.i"
//%include "std_list.i"
//%include "std_iostream.i"
//%include <windows.i>

//namespace std 
//{
//    %template(IntVector)    std::vector<int>;
//    %template(DoubleVector) std::vector<double>;
//    %template(StringVector) std::vector<std::string>;
//    //   %template(StringList) std::list<std::string>;
//    %template(ConstCharVector) std::vector<const char*>;
//}

//Need to #define export macros. 
#define AT_CORE 


//Suppress some warnings
//%warnfilter(451) dsl::gDoubleFormat;
//%warnfilter(451) dsl::gIntFormat;
//%warnfilter(503) ;
//%warnfilter(389) ;
//%warnfilter(362) ;

%ignore operator<<;
%ignore operator=;
//%ignore operator[];

/////////////////////////////////////////
//These are classes, and other entitites we want to expose to python
/////////////////////////////////////////
%include "p:/libs/atapi/source/core/atATObject.h"

