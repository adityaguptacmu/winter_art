#
# Makefile for Winter_art
#

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=subset_sum.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=subset_sum

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o subset_sum

