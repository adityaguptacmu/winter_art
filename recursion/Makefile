#
# Makefile for Winter_art
#

CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all: recursion

recursion: recursion.o

recursion.o: recursion.c
	$(CC) $(CFLAGS) -c recursion.c

clean:
	rm -f *~ *.o recursion core *.tar *.zip *.gzip *.bzip *.gz
