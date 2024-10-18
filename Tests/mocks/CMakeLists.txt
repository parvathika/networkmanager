cmake_minimum_required(VERSION 3.8)
set(MODULE_NAME TestMocklib)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e39786088138f2749d64e9e90e0f9902daa77c40.zip
)
FetchContent_MakeAvailable(googletest)


add_library(${MODULE_NAME} SHARED
    Rfc.cpp
    Iarm.cpp
    Wraps.cpp
    Udev.cpp
)
target_link_libraries(${MODULE_NAME} PRIVATE gmock_main)

set_target_properties(${MODULE_NAME} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES)


install(TARGETS ${MODULE_NAME}
    DESTINATION lib)
