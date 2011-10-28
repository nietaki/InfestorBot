CC=g++
CFLAGS=-O3 -funroll-loops -c
LDFLAGS=-O2 -lm
VPATH=src#code directory
ODIR=obj#object directory
EXEDIR=bin
SOURCES=Bot.cc MyBot.cc State.cc
#SOURCES=*.cc #TODO

OBJECTS=$(SOURCES:.cc=.o)
OBJECTS_WITH_LOCATION=$(addprefix $(ODIR)/, $(OBJECTS))
EXECUTABLE=MyBot

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
	touch $(EXEDIR)/$(FULLZIPNAME)

clean: 
	#-rm -f ${EXECUTABLE} ${OBJECTS} *.d
	-rm -f ${EXEDIR}/$(EXECUTABLE) $(EXEDIR)/$(FULLZIPNAME) ${ODIR}/*.o *.d
	-rm -f debug.txt

.PHONY: all clean zip

