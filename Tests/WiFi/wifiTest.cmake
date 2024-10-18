cmake_minimum_required(VERSION 3.10)



set(WIFI_TEST "wifitest")

find_package(GTest REQUIRED)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GLIB REQUIRED glib-2.0)

pkg_check_modules(GIO REQUIRED gio-2.0)

pkg_check_modules(LIBNM REQUIRED libnm)



include(FetchContent)

FetchContent_Declare(

        googletest

        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip

)

FetchContent_MakeAvailable(googletest)



add_executable(${WIFI_TEST}

  Tests/L1Tests/tests/test_WiFiSignalStrengthMonitor.cpp

  WiFiSignalStrengthMonitor.cpp

  NetworkManagerLogger.cpp

  NetworkManagerImplementation.cpp

)



set_target_properties(${WIFI_TEST} PROPERTIES

    CXX_STANDARD 11

    CXX_STANDARD_REQUIRED YES

)



target_compile_options(${WIFI_TEST} PRIVATE -Wall -include ${CMAKE_SOURCE_DIR}/INetworkManager.h)

target_include_directories(${WIFI_TEST} PRIVATE ${GLIB_INCLUDE_DIRS} ${LIBNM_INCLUDE_DIRS} ${GIO_INCLUDE_DIRS}{PROJECT_SOURCE_DIR})

target_include_directories(${WIFI_TEST} PRIVATE neworkmanager)



target_link_libraries(${WIFI_TEST} ${WPEFramework}Core::${WPEFramework}Core ${GLIB_LIBRARIES} ${GIO_LIBRARIES} uuid)



target_include_directories(${WIFI_TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



install(TARGETS ${WIFI_TEST} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)