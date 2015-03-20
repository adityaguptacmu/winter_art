#
# Makefile for Winter_art
#

CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=strings.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=strings

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o strings core *.tar *.zip *.gzip *.bzip *.gz

