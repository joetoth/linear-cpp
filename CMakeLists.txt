cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
project(MyProject)

# Enable testing
set(BUILD_TESTING ON)
include(CTest)


# Download gtest at configure time
include(add_dl_project.cmake)
add_dl_project(PROJ     gtest
               URL      https://googletest.googlecode.com/files/gtest-1.7.0.zip
               URL_HASH SHA1=f85f6d2481e2c6c4a18539e391aa4ea8ab0394af
               EXCLUDE_FROM_ALL
)


# gtest doesn't add a public include directory to the target for
# its headers, so we have to explicitly add it ourselves so that
# client code finds gtest/gtest.h
target_include_directories(gtest INTERFACE "${CMAKE_BINARY_DIR}/gtest-src/include")

# Example for how to define a test which uses gtest
add_executable(mytest tester.cpp Matrix.cpp Matrix.h)
target_link_libraries(mytest gtest_main)
add_test(NAME mytest COMMAND mytest)

