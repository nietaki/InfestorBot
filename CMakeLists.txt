cmake_minimum_required (VERSION 2.6)
project (InfestorBot)

#TODO: pick the default compiler
#TODO: add compilation flags to CMakeLists.txt

subdirs(google_test)
#include_directories(tests)
#include_directories (${INFESTORBOT_SOURCE_DIR}) 
include_directories (.)
include_directories (google_test/include)
add_library(everything Ant.cc AntManager.cc InfestorBot.cc Location.cc NotImplementedException.cc State.cc Bugger.cc Square.cc BucketMaster.cc Bucket.cc)

# add the executable
add_executable(InfestorBot.run MyBot.cc)

target_link_libraries(InfestorBot.run everything)


ENABLE_TESTING()

## Google Test can be better integrated with CMake, but I can't get it to work
## generic integration for now
# SET(GTest_DIR ${CMAKE_CURRENT_SOURCE_DIR}/google_test)
# find_package(GTest REQUIRED
# GTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/google_test/include)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/google_test/include)

## creating directory for the tests
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)

## this is the list of unit tests in the test/ directory
## the filename searched for is created by appending
## "_test.cc" to the test name
## make sure to add all the new tests here
set(TESTNAMES Location AntManager BucketMaster Bucket)

foreach(testname ${TESTNAMES})
	add_executable(tests/${testname}.test tests/${testname}_test.cc)
	target_link_libraries(tests/${testname}.test everything gtest_main)
	add_test(${testname} tests/${testname}.test)
endforeach(testname)