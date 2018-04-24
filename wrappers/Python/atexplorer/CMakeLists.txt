find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
find_package(PythonInterp)
find_package(PythonLibs)
message("Python include folder: " ${PYTHON_INCLUDE_DIRS})
message("Python libraries: " ${PYTHON_LIBRARIES})

get_filename_component(PYTHON_LIB_FOLDER ${PYTHON_LIBRARIES} DIRECTORY CACHE)
message("Python lib folder: " ${PYTHON_LIB_FOLDER})


set(DSL_ROOT "P:/libs/dsl")

include_directories(${PYTHON_INCLUDE_PATH})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(
.
${DSL_ROOT}/Common
${DSL_ROOT}/IPC
${ATAPI_ROOT}
${ATAPI_ROOT}/source
${ATAPI_ROOT}/source/core
${THIRD_PARTY_INSTALL_PREFIX}/include
)

set (CMAKE_MODULE_LINKER_FLAGS ${CMAKE_CURRENT_SOURCE_DIR}/atexplorer.def)
link_directories(${LIBRARY_OUTPUT_PATH} C:/Python37/libs)

set(CMAKE_SWIG_FLAGS "")

set_source_files_properties(atexplorer.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(atexplorer.i PROPERTIES SWIG_FLAGS "-threads")
#SET_SOURCE_FILES_PROPERTIES(atexplorer.i PROPERTIES SWIG_FLAGS "-includeall")
SET( CMAKE_MODULE_LINKER_FLAGS  "${CMAKE_MODULE_LINKER_FLAGS} ${CMAKE_CURRENT_SOURCE_DIR}/atexplorer.def" )
SWIG_ADD_LIBRARY(atexplorer MODULE LANGUAGE python SOURCES atexplorer.def atexplorer.i)
SWIG_LINK_LIBRARIES (atexplorer 
    ${PYTHON_LIB_FOLDER}/Python3_CG.lib
    ${PYTHON_LIB_FOLDER}/Python37_CG.lib
    ${CMAKE_INSTALL_PREFIX}/lib/atCore.lib
    ${CMAKE_INSTALL_PREFIX}/lib/dslFoundation.lib
)

# INSTALL PYTHON BINDINGS
# Get the python site packages directory by invoking python
execute_process(COMMAND python -c "import site; print(site.getsitepackages()[0])" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
message("PYTHON_SITE_PACKAGES = ${PYTHON_SITE_PACKAGES}")
install(TARGETS _atexplorer DESTINATION ${PYTHON_SITE_PACKAGES})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/atexplorer.py DESTINATION ${PYTHON_SITE_PACKAGES})


