cmake_minimum_required (VERSION 2.6)
project (InfestorBot)

# SUBDIRS(engine)
# INCLUDE_DIRECTORIES(${InfestorBot_SOURCE_DIR}/engine)



# add the executable
add_executable(InfestorBot.run MyBot.cc)

add_library(everything Ant.cc AntManager.cc InfestorBot.cc Location.cc NotImplementedException.cc State.cc)
target_link_libraries(InfestorBot.run everything)
