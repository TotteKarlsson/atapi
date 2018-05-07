%module(docstring="Array Tomogrpahy Library for Python (atp), (c) 2016-2018 Allen Institute",threads="1", directors="1" ) atp

// ************************************************************
// Module Includes
// ************************************************************

// These are copied directly to the .cxx file and are not parsed
// by SWIG.  Include include files or definitions that are required
// for the module to build correctly.

%{
#include "atATObject.h"
#include "dsl/dslTypeInfo.h"
#include "dsl/dslBaseProperty.h"
#include "dsl/dslProperty.h"
#include "dsl/dslStringList.h"
#include "dsl/dslProperties.h"
#include "dsl/dslPlugin.h"
#include "dsl/dslPluginMetaData.h"
#include "dsl/dslPluginmanager.h"
#include  <string>
using namespace dsl;
using namespace std;
%}
 
%include "std_string.i"
%include "std_vector.i"
%include "std_map.i"
%include "std_list.i"
%include "std_pair.i"
%include "std_set.i"
//%include "std_iostream.i"
//%include "std_sstream.i"
//%include "std_wsstream.i"
//%include "windows.i"

#define DSL_COMMON
#define DSL_PLUGINS
#define DSL_PYTHONPLUGINS
#define Foundation_API

//%feature("director");

%ignore *::operator[];
%ignore *::operator=;
%ignore std::ostream;
%ignore operator<<;
%ignore operator int;
%ignore operator std::string;

%warnfilter(315) ostream; 
%warnfilter(315) stringstream; 

%import "dsl/dslConstants.h"
%import "Poco/DateTimeFormatter.h"
%import "Poco/SharedLibrary.h"

//Expose  Python
%include "dsl/dslObject.h"
%include "dsl/dslTypeInfo.h"
%include "dsl/dslBaseProperty.h"
%include "dsl/dslProperty.h"
%include "dsl/dslProperties.h"
%include "dsl/dslPluginMetaData.h"
%include "dsl/dslPlugin.h"
%include "dsl/dslPluginManager.h"

%template(intProperty)          dsl::Property<int>;
%template(stringProperty)       dsl::Property<std::string>;


