CC=g++
CFLAGS=-O3 -funroll-loops -c
LDFLAGS=-O2 -lm

SRCDIR=src
ODIR=obj#object directory
EXEDIR=bin
SOURCES=InfestorBot.cc MyBot.cc State.cc
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

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS_WITH_LOCATION) -o $(EXEDIR)/$@ 

.cc.o: *.h
	$(CC) $(CFLAGS) $< -o $(ODIR)/$@

zip: $(FULLZIPNAME)

$(FULLZIPNAME):
	rm -f $(EXEDIR)/*.zip
	zip -j $(EXEDIR)/$(FULLZIPNAME) $(SRCDIR)/*

clean: 
	#-rm -f ${EXECUTABLE} ${OBJECTS} *.d
	-rm -f ${EXEDIR}/*.run $(EXEDIR)/*.zip ${ODIR}/*.o $(ODIR)/*.d
	-rm -f debug.txt

.PHONY: all clean zip

