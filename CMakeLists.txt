

cmake_minimum_required(VERSION 3.6)


project(grip)

set(GRIP_ROOT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(GRIP_ARCHIVE_OUTPUT_DIRECTORY "${GRIP_ROOT_DIRECTORY}/bin/lib")
set(GRIP_LIBRARY_OUTPUT_DIRECTORY "${GRIP_ROOT_DIRECTORY}/bin/lib")
set(GRIP_RUNTIME_OUTPUT_DIRECTORY "${GRIP_ROOT_DIRECTORY}/bin")


include(${GRIP_ROOT_DIRECTORY}/cmake/compiler.cmake)
include(${GRIP_ROOT_DIRECTORY}/cmake/functions.cmake)


include_directories(
    ${GRIP_ROOT_DIRECTORY}/include
	${GRIP_ROOT_DIRECTORY}/dependencies/spdlog/include
)

file_list(grip_src src/grip.cpp)
grip_add_library(grip ${grip_src})


if ("${GRIP_BUILD_OS}" STREQUAL "Windows")
    file_list(grip_main_src src/main_win.cpp)
    grip_add_executable(grip_main ${grip_main_src} grip)
elseif("${GRIP_BUILD_OS}" STREQUAL "Linux")
    file_list(grip_main_src src/main_linux.cpp)
    grip_add_executable(grip_main ${grip_main_src} grip)
elseif("${GRIP_BUILD_OS}" STREQUAL "OS X")
    file_list(grip_main_src src/main_osx.mm)
    grip_add_executable(grip_main ${grip_main_src} grip)
endif()


add_subdirectory(dependencies)

