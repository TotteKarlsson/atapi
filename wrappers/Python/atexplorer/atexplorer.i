// atexplorer.i 
%include "std_string.i"
%include "windows.i"

%module atexplorer
%{
//#define SWIG_FILE_WITH_INIT
#include "atATObject.h"
%}
 
//#define AT_CORE
//Expose class ATObject to Python
%include "atATObject.h"

