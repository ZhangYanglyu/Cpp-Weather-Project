cmake_minimum_required(VERSION 3.0.0)
project(project3 VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(CURL REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

add_executable(project3 main.cpp)

target_link_libraries(project3 ${CURL_LIBRARIES} ${JSONCPP_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
