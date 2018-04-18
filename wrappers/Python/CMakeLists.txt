cmake_minimum_required(VERSION 2.8)
project(atexplorerPython)

include(
    ${CMAKE_CURRENT_SOURCE_DIR}/FindSWIG.cmake
)

find_package(SWIG REQUIRED)
include(UseSWIG)

find_package(PythonLibs )#REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
find_package(PythonInterp)

include_directories(
    ${PYTHON_INCLUDE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}
#    ${CMAKE_BINARY_DIR}/include
    ${ATEXPLORER_ROOT}
    ${ATEXPLORER_ROOT}/source
    ${ATEXPLORER_ROOT}/source/core
)

link_directories(					
${LIBRARY_OUTPUT_PATH}
)

set(CMAKE_SWIG_FLAGS "")

if(SWIG_FOUND)
    add_subdirectory(atexplorer)
else(SWIG_FOUND)
    message("Could not find SWIG in your system")
endif(SWIG_FOUND)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#Don't install the setup.py on Linux or Windows.
else()
	install(FILES setup.py
        DESTINATION ${CMAKE_INSTALL_PREFIX}
		COMPONENT MISC
)
endif()



