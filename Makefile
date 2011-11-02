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

OBJECTS=$(SOURCES:.cc=.o)

vpath %.cc src
vpath %.h src
vpath %.o obj
vpath %.zip bin
vpath %.run bin

OBJECTS_WITH_LOCATION=$(addprefix $(ODIR)/, $(OBJECTS))
EXECUTABLE=InfestorBot.run

ZIPNAME=tosubmit
DATE=today
FULLZIPNAME=$(ZIPNAME).zip

#Uncomment the following to enable debugging
#CFLAGS+=-g -DDEBUG

all: $(OBJECTS) $(EXECUTABLE)
	-rm -f ${EXEDIR}/debug.txt

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

clean: 
	#-rm -f ${EXECUTABLE} ${OBJECTS} *.d
	-rm -f ${EXEDIR}/*.run $(EXEDIR)/*.zip ${ODIR}/*.o $(ODIR)/*.d *.o
	-rm -f ${EXEDIR}/debug.txt

.PHONY: all clean zip

