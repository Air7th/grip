


macro(file_list VARIABLE_NAME)
    set(TEMP_FILE_LIST ${ARGN})
    foreach(ELEMENT IN LISTS TEMP_FILE_LIST)
        if(${ELEMENT} MATCHES .mm$ OR ${ELEMENT} MATCHES .m$)
            set_source_files_properties(
                ${ELEMENT}
                PROPERTIES
                COMPILE_FLAGS
                "${CMAKE_OBJCXX_FLAGS}"
            )
        endif()
        get_filename_component(ELEMENT_DIR ${ELEMENT} DIRECTORY)
        if (NOT ${ELEMENT_DIR} STREQUAL "")
            string(REPLACE ".." "" group_name ${ELEMENT_DIR})
            string(REPLACE "/" "\\" group_name ${group_name})
            source_group("${group_name}" FILES ${ELEMENT})
        else()
            source_group("\\" FILES ${ELEMENT})
        endif()
    endforeach()
    list(APPEND ${VARIABLE_NAME} ${TEMP_FILE_LIST})
    list(SORT ${VARIABLE_NAME})
    unset(TEMP_FILE_LIST)
endmacro()


macro(add_executable_platform name)
    if(WIN32)
        add_executable(${name} WIN32 ${ARGN})
    else()
        add_executable(${name} MACOSX_BUNDLE ${ARGN})
    endif()
endmacro()


macro(grip_add_executable name sources)
    add_executable_platform(${name} ${sources})
    target_link_libraries(${name} ${ARGN})
    set_target_properties(
        ${name} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${GRIP_ARCHIVE_OUTPUT_DIRECTORY}
        LIBRARY_OUTPUT_DIRECTORY ${GRIP_LIBRARY_OUTPUT_DIRECTORY}
        RUNTIME_OUTPUT_DIRECTORY ${GRIP_RUNTIME_OUTPUT_DIRECTORY}
    )
endmacro()


macro(grip_add_library name sources)
    add_library(${name} ${sources})
    target_link_libraries(${name} ${ARGN})
    set_target_properties(
        ${name} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${GRIP_ARCHIVE_OUTPUT_DIRECTORY}
        LIBRARY_OUTPUT_DIRECTORY ${GRIP_LIBRARY_OUTPUT_DIRECTORY}
        RUNTIME_OUTPUT_DIRECTORY ${GRIP_RUNTIME_OUTPUT_DIRECTORY}
    )
endmacro()
