cmake_minimum_required(VERSION 2.8)
project(atexplorerPython)

find_package(SWIG REQUIRED)
include(UseSWIG)

if(SWIG_FOUND)
    add_subdirectory(atexplorer)
else(SWIG_FOUND)
    message("Could not find SWIG in your system")
endif(SWIG_FOUND)




