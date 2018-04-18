cmake_minimum_required(VERSION 2.8)
project(atexplorer)

SET(ATAPI_MAJOR_VERSION 0)
SET(ATAPI_MINOR_VERSION 8)
SET(ATAPI_BUILD_VERSION 5)
SET(ATAPI_VERSION "${ATAPI_MAJOR_VERSION}.${ATAPI_MINOR_VERSION}.${ATAPI_BUILD_VERSION}")

set(ATAPI_ROOT 	${CMAKE_CURRENT_SOURCE_DIR})


#Options
if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE )
endif()

OPTION(BUILD_STATIC_LIBS 		    "Build Static Libs"                         OFF)

#Wait with the shared version
OPTION(BUILD_SHARED_LIBS 		    "Build Shared Libs"                         ON)

OPTION(INSTALL_CXX_LIBS 		    "Install CXX libraries and header"          OFF)
OPTION(INSTALL_PYTHON 			    "Build Python Module"                       OFF)
 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/bin)

#=== COMPILER SPECIFICS 
if(${BORLAND})
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release")
    set(SUPPRESS_WARNINGS   "-w-8128 -w-8057 -w-8012 -w-8004 -w-8070" )
    include_directories( 
        "C:/CG/Embarcadero/RAD Studio/10.0/include/boost_1_39"
        )
endif()

if(${MSVC})
    set(SUPPRESS_WARNINGS   "/wd4221 /wd4018 /wd4996 /wd4251" )
#    set(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS} /EHsc ")
    set(CMAKE_SHARED_LINKER_FLAGS      "${CMAKE_SHARED_LINKER_FLAGS} ") 
    set(CMAKE_STATIC_LINKER_FLAGS      "${CMAKE_STATIC_LINKER_FLAGS} ") 
#    set(CMAKE_CXX_MP_FLAG               ON CACHE BOOL "")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
#    message(STATUS "Added parallel build arguments to CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
    add_definitions(
    -D_CRT_NONSTDC_NO_DEPRECATE
    -D_CRT_SECURE_NO_WARNINGS
    )
endif()

if(${UNIX})
    set (CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS} -std=c++0x -fPIC -fpermissive -Wno-deprecated")
endif()    

#Warning string looks different depending on the compiler..
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SUPPRESS_WARNINGS}")

#ThidParty include
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(THIRD_PARTY_INSTALL_PREFIX  CACHE PATH "Directory containing ThirdParty install.")
    if("${THIRD_PARTY_INSTALL_PREFIX}" STREQUAL "")
      set(THIRD_PARTY_INSTALL_PREFIX "x:/" CACHE PATH "Directory containing ThirdParty install" FORCE)
    endif()
else()
    set(THIRD_PARTY_INSTALL_PREFIX  CACHE PATH "Directory containing ThirdParty install.")
    if("${THIRD_PARTY_INSTALL_PREFIX}" STREQUAL "")
      set(THIRD_PARTY_INSTALL_PREFIX "/usr/local" CACHE PATH "Directory containing ThirdParty install" FORCE)
    endif()
endif()

set(TP_INCLUDE                     ${THIRD_PARTY_INSTALL_PREFIX}/include)

link_directories(
${THIRD_PARTY_INSTALL_PREFIX}/lib
)


set(DSL_INCLUDE                     ${THIRD_PARTY_INSTALL_PREFIX}/include/dsl)
   
#Source Code Folders
add_subdirectory(source)
add_subdirectory(wrappers)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(RootDest lib/python2.7/dist-packages/atexplorer)
else()
	set(RootDest .)
endif()

#======================= INSTALL ========================================================
install (FILES 
    README.txt 
    LICENSE.txt 
    AUTHORS.txt 
    VERSION.txt 
    INSTALL.txt 
    NOTICE.txt
    CHANGELOG.txt
    DESTINATION ${RootDest} 	
    COMPONENT info
   )

