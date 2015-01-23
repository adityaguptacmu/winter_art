#
# Makefile for Winter_art
#

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=kmp.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=kmp

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o kmp

