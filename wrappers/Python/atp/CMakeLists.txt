find_package(PythonInterp)
find_package(PythonLibs)

message("Python include folder: "   ${PYTHON_INCLUDE_DIRS})
message("Python libraries: "        ${PYTHON_LIBRARIES})

get_filename_component(PYTHON_LIB_FOLDER ${PYTHON_LIBRARIES} DIRECTORY CACHE)
message("Python lib folder: " ${PYTHON_LIB_FOLDER})

include_directories(
.
    ${PYTHON_INCLUDE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ATAPI_ROOT}
    ${ATAPI_ROOT}/source
    ${ATAPI_ROOT}/source/core
    ${THIRD_PARTY_INSTALL_PREFIX}/include
)

link_directories(
${CMAKE_BINARY_DIR}/lib
${PYTHON_LIB_FOLDER}
)

message("Lib folder: " ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_SWIG_FLAGS "-DPOCO_STATIC")
set(CMAKE_MODULE_LINKER_FLAGS ${CMAKE_CURRENT_SOURCE_DIR}/atp.def)


if(BORLAND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w-8105 -tR -tM")
endif(BORLAND)

set_source_files_properties(atp.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(atp.i PROPERTIES SWIG_FLAGS "-threads")

SWIG_ADD_LIBRARY(atp
    MODULE LANGUAGE python 
    SOURCES atp.i)
    
SWIG_LINK_LIBRARIES (atp
    atCore
    ${PYTHON_LIB_FOLDER}/Python3_CG.lib
    ${PYTHON_LIB_FOLDER}/Python37_CG.lib
    ${CMAKE_INSTALL_PREFIX}/lib/dslCommon.lib
    ${CMAKE_INSTALL_PREFIX}/lib/dslPlugins.lib
    ${CMAKE_INSTALL_PREFIX}/lib/dslPythonPlugins.lib
)

# INSTALL PYTHON BINDINGS
# Get the python site packages directory by invoking python
execute_process(COMMAND python -c "import site; print(site.getsitepackages()[0])" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
message("PYTHON_SITE_PACKAGES = ${PYTHON_SITE_PACKAGES}")
install(
    TARGETS _atp
    DESTINATION ${PYTHON_SITE_PACKAGES})

install(
    FILES         ${CMAKE_CURRENT_BINARY_DIR}/atp.py 
                  ${CMAKE_BINARY_DIR}/lib/_atp.tds
    DESTINATION   ${PYTHON_SITE_PACKAGES}
)
