
cmake_minimum_required(VERSION 3.8)

find_package(GTest REQUIRED)

include_directories(networkmanager)


set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
  test_WiFiSignalStrengthMonitor
  test_WiFiSignalStrengthMonitor.cpp
)

target_link_libraries(
  test_WiFiSignalStrengthMonitor
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_WiFiSignalStrengthMonitor)
