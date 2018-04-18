set(target atCore)

include_directories(
.
${ATAPI_ROOT}
${ATAPI_ROOT}/source
${CG_BOOST_ROOT}
${TR1_ROOT}
${DSL_INCLUDE}
${THIRD_PARTY_INSTALL_PREFIX}/include
)

set(src
atATObject
)

#===== Static library
if(${BUILD_STATIC_LIBS})
    add_library(${target}-static STATIC
    ${src}
    )

    set_property(TARGET ${target}-static  
    PROPERTY COMPILE_DEFINITIONS 
    DSL_STATIC
    POCO_STATIC
    )

    target_link_libraries(${target}-static 
    mtkCommon-static
    mtkMath-static
    )

    if(${INSTALL_CXX_LIBS})
        install(    
        TARGETS ${target}-static
        RUNTIME DESTINATION bin COMPONENT core
        LIBRARY DESTINATION lib COMPONENT core
        ARCHIVE DESTINATION lib COMPONENT core
        )            
    endif()
endif()

#===== Shared library
if(${BUILD_SHARED_LIBS})
    add_library(${target} SHARED
    ${src}
    )

    set_property(TARGET ${target}  
    PROPERTY COMPILE_DEFINITIONS 
    AT_EXPORT_CORE
    POCO_STATIC
    )

    target_link_libraries(${target} 
    )


    install(    
    TARGETS ${target} 
    RUNTIME DESTINATION bin COMPONENT core
    LIBRARY DESTINATION lib COMPONENT core
    ARCHIVE DESTINATION lib COMPONENT core
    )            

endif()

#===== General Installs
if(${INSTALL_CXX_LIBS})
FILE (GLOB headers *.h)
install (   FILES ${headers}			 	
            DESTINATION include/atexplorer 
            COMPONENT cxx_headers)

endif()

