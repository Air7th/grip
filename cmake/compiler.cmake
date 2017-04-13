


if(MSVC15 OR MSVC14 OR MSVC12)
    # remove unnecessary warnings about unchecked iterators
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    foreach (flag_var
             CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
             CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      if (NOT BUILD_SHARED_LIBS AND NOT gtest_force_shared_crt)
        string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")
      endif()
      string(REPLACE "/W3" "/W4" ${flag_var} "${${flag_var}}")
    endforeach()
else()
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
    CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
    if(COMPILER_SUPPORTS_CXX14)
    	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wno-missing-braces")
    elseif(COMPILER_SUPPORTS_CXX11)
    	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-missing-braces")
    else()
      message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif()
endif()
