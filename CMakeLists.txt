cmake_minimum_required (VERSION 2.6)
project (InfestorBot)

subdirs(google_test)
#include_directories(tests)
#include_directories (${INFESTORBOT_SOURCE_DIR}) 
include_directories (.)
include_directories (google_test/include)
add_library(everything Ant.cc AntManager.cc InfestorBot.cc Location.cc NotImplementedException.cc State.cc Bugger.cc)

# add the executable
add_executable(InfestorBot.run MyBot.cc)

target_link_libraries(InfestorBot.run everything)


#creating directory for the tests
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)
#creating the tests
add_executable(tests/location.test tests/location_test.cc)
target_link_libraries(tests/location.test everything gtest_main)