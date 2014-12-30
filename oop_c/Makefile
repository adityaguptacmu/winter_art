#
# Makefile for Winter_art
#

CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c new.c Object.c Set.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o main core *.tar *.zip *.gzip *.bzip *.gz

