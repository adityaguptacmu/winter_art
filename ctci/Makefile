#
# Makefile for Winter_art
#

CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=moderate.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=moderate

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o moderate

