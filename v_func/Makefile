#
# Makefile for Winter_art
#

CC=g++
CFLAGS=
LDFLAGS=-m32
OTHERDIR=

SOURCES=v_func.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o main

