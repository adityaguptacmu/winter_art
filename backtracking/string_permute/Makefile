#
# Makefile for Winter_art
#

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=string_permute.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=string_permute

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o string_permute

