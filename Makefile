#
# Makefile for Winter_art
#

CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all: prep

prep: prep.o hash.o

prep.o: prep.c hash.h
	$(CC) $(CFLAGS) -c prep.c

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

clean:
	rm -f *~ *.o prep core *.tar *.zip *.gzip *.bzip *.gz
