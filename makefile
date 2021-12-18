CC = gcc
AR = ar
FLAGS = -Wall -g
all: connections
connections: main.o
	$(CC) $(FLAGS) -o connections main.o

main.o: main.c
	$(CC) $(FLAGS) -c main.c

 .PHONY: clean all