set_source_files_properties(atexplorer.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(atexplorer.i PROPERTIES SWIG_FLAGS "-threads")

SWIG_ADD_LIBRARY(atexplorer LANGUAGE python SOURCES atexplorer.i)

include_directories(
.
${ATAPI_ROOT}
${ATAPI_ROOT}/source
${ATAPI_ROOT}/source/core
)

link_directories(					
${LIBRARY_OUTPUT_PATH}
)
    set_target_properties(_atexplorer PROPERTIES SUFFIX ".pyd")

    set_property(TARGET _atexplorer
        PROPERTY COMPILE_DEFINITIONS
        POCO_STATIC
        )

    SWIG_LINK_LIBRARIES ( atexplorer
        atCore
        ${PYTHON_LIBRARIES}
        )


##Todo: make site-package destination an option
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(ATEXPLORER_PACKAGE_DIR lib/python2.7/dist-packages/atexplorer)
else()
	set(ATEXPLORER_PACKAGE_DIR site-package)
endif()

set( python_files_path ${CMAKE_BINARY_DIR}/wrappers/python/atexplorer)

install(    
    TARGETS _atexplorer
    DESTINATION ${ATEXPLORER_PACKAGE_DIR}
    COMPONENT python_module
)

install(    
    FILES ${python_files_path}/atexplorer.py __init__.py    
    DESTINATION ${ATEXPLORER_PACKAGE_DIR}   
    COMPONENT python_module
)

