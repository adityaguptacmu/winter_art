#
# Makefile for Winter_art
#

CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
OTHERDIR=../stack_queue

SOURCES=main.c tree.c $(OTHERDIR)/stack_queue.c

OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o main

