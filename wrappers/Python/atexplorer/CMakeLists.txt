find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
find_package(PythonInterp)
find_package(PythonLibs)
message(${PYTHON_INCLUDE_DIRS})
message(${PYTHON_LIBRARIES})


include_directories(${PYTHON_INCLUDE_PATH})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(
.
${ATAPI_ROOT}
${ATAPI_ROOT}/source
${ATAPI_ROOT}/source/core
)
set (CMAKE_LINK_DEF_FILE_FLAG "/DEF:")
link_directories(${LIBRARY_OUTPUT_PATH} C:/Python37)

set(CMAKE_SWIG_FLAGS "")

set_source_files_properties(atexplorer.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(atexplorer.i PROPERTIES SWIG_FLAGS "-threads")
#SET_SOURCE_FILES_PROPERTIES(atexplorer.i PROPERTIES SWIG_FLAGS "-includeall")

SWIG_ADD_LIBRARY(atexplorer MODULE LANGUAGE python SOURCES atexplorer.def atexplorer.i ${ATAPI_ROOT}/source/core/atATObject.cpp )
SWIG_LINK_LIBRARIES (atexplorer 
    Python3_CG.lib
    Python37_CG.lib
)

# INSTALL PYTHON BINDINGS
# Get the python site packages directory by invoking python
execute_process(COMMAND python -c "import site; print(site.getsitepackages()[0])" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
message("PYTHON_SITE_PACKAGES = ${PYTHON_SITE_PACKAGES}")
install(TARGETS _atexplorer DESTINATION ${PYTHON_SITE_PACKAGES})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/atexplorer.py DESTINATION ${PYTHON_SITE_PACKAGES})


