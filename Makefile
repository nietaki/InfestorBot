CC=g++
CFLAGS=-O3 -funroll-loops -Wall -c -Woverloaded-virtual
LDFLAGS=-O2 -lm

SRCDIR=src
ODIR=obj#object directory
EXEDIR=bin
## LEGACY CLASS LISTING
#SOURCES=InfestorBot.cc MyBot.cc State.cc Bucketable.cc BucketableLocationListener.cc NotImplementedException.cc
LONE_HEADERS=Bug.h State.h Square.h Timer.h
SOURCES1=$(wildcard src/*.cc)
SOURCES=$(subst src/,,$(SOURCES1))
#SOURCES=*.cc #TODO

#include google_test/Makefile 

OBJECTS=$(SOURCES:.cc=.o)

vpath %.cc src
vpath %.h src
vpath %.o obj
vpath %.a obj
vpath %.zip bin
vpath %.run bin

OBJECTS_WITH_LOCATION=$(addprefix $(ODIR)/, $(OBJECTS))
EXECUTABLE=InfestorBot.run

ZIPNAME=tosubmit
DATE=today
FULLZIPNAME=$(ZIPNAME).zip


### GOOGLE TEST VARIABLES ###

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ./google_test

# Where to find user code.
USER_DIR = ./google_test/samples

# Flags passed to the preprocessor.
CPPFLAGS += -I$(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = sample1_unittest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

### END GOOGLE TEST VARIABLES ###

#Uncomment the following to enable debugging
#CFLAGS+=-g -DDEBUG

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS_WITH_LOCATION) -o $(EXEDIR)/$@ 



#.cc.o: *.h 
%.o: src/%.cc %.h $(LONE_HEADERS)
	$(CC) $(CFLAGS) $< -o $(ODIR)/$@

#echo $^;
#echo $*;


### Very special rules for my very special MyBot - override the implicit, which doesn't work for MyBot ###
#make some kind of rule for Mybot.cc
MyBot.cc:

MyBot.o: MyBot.cc
	$(CC) $(CFLAGS) $< -o $(ODIR)/$@
	
zip: $(FULLZIPNAME)

$(FULLZIPNAME):
	rm -f $(EXEDIR)/*.zip
	zip -j $(EXEDIR)/$(FULLZIPNAME) $(SRCDIR)/*




.PHONY: all clean zip




### GOOGLE TEST RECIPES ###

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $(ODIR)/$@

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $(ODIR)/$@

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $(ODIR)/$@ $(addprefix $(ODIR)/,$^)

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $(ODIR)/$@ $(addprefix $(ODIR)/,$^)

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

sample1.o : $(USER_DIR)/sample1.cc $(USER_DIR)/sample1.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1.cc -o $(ODIR)/$@

sample1_unittest.o : $(USER_DIR)/sample1_unittest.cc \
                     $(USER_DIR)/sample1.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1_unittest.cc -o $(ODIR)/$@

sample1_unittest : sample1.o sample1_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $(addprefix $(ODIR)/,$^) -o $(EXEDIR)/$@ 


####  GLOBAL CLEAN TARGET ###

#TODO: remove the tests in the correct directory
clean: 
	rm -f ${EXEDIR}/*.run $(EXEDIR)/*.zip ${ODIR}/*.o $(ODIR)/*.d *.o
	rm -f ${EXEDIR}/debug.txt
	rm -f $(TESTS) gtest.a gtest_main.a *.o

	

all: $(OBJECTS) $(EXECUTABLE) $(TESTS)
	-rm -f ${EXEDIR}/debug.txt
	