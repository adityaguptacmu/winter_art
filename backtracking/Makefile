#
# Makefile for Winter_art
#

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=knights_tour.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=knights_tour

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o knights_tour

