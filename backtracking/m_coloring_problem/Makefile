#
# Makefile for Winter_art
#

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=m_coloring_problem.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=m_coloring_problem

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o m_coloring_problem

