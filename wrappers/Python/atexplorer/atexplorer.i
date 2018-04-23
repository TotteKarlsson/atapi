// atexplorer.i 
%include "std_string.i"
%include "windows.i"

%module atexplorer
%{
#include "atATObject.h"
//#include "UC7/atUC7Component.h"
%}
 
#define AT_CORE
#define AT_UC7

//Expose class ATObject to Python
%include "atATObject.h"
//%include "UC7/atUC7Component.h"

