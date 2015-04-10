#
# Makefile for Winter_art
#

CC=gcc
CFLAGS=-c -g
LDFLAGS=
SOURCES=hash_test.c hash.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o main

