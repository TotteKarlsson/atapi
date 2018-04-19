// atexplorer.i 

%module atexplorer

 %{
 #include "atATObject.h"
 %}
 
//Need to #define export macros. 

#define AT_CORE


//These are classes, and other entitites we want to expose to python
%include "atATObject.h"

