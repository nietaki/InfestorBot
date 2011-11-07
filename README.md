== How to build ==
Pick a name for your build directory. For me it's "build"

cd path/to/InfestorBot
cd ..
mkdir build
cd build

Now let's construct the native build system from CMake. Let's say you're using Eclipse under Linux:

cmake -G"Eclipse CDT4 - Unix Makefiles" -DECLIPSE_CDT4_GENERATE_SOURCE_PROJECT=FALSE ../InfestorBot

(note that we're not generating the Eclipse project files, they're already in the repository)

Now to build the project

make

And to run the tests

ctest

*Disclaimer*
All the data is totally unencapsulated. For now I'll blame it on the challenge starting code,
and fix it when I have the time and nothing better to do. 

#TODO: format the readme right, with 'preformatted' mark for commands