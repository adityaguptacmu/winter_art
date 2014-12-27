#
# Makefile for Winter_art
#

CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all: linked_list

linked_list: linked_list.o hash.o

linked_list.o: linked_list.c hash.h
	$(CC) $(CFLAGS) -c linked_list.c

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

clean:
	rm -f *~ *.o linked_list core *.tar *.zip *.gzip *.bzip *.gz
