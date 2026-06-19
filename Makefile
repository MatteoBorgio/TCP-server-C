CFLAGS = -O2 -Wall -fPIC
CC = gcc

all: server

server.o: server.c server.h
    $(CC) -c $(CFLAGS) server.c

server: server.o 
    $(CC) server.o -o server -O2 -Wall 

clean:
	rm -f server server.o
