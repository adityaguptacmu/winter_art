#
# Makefile for Winter_art
#

CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all: tree_test

tree_test: tree_test.o tree.o

tree_test.o: tree_test.c tree.h
	$(CC) $(CFLAGS) -c tree_test.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm -f *~ *.o tree_test core *.tar *.zip *.gzip *.bzip *.gz
