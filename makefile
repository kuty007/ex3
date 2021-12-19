CC = gcc 
Flags = -Wall -g

all: stringProg

stringProg: main.o
	$(CC) $(Flags) -o stringProg main.o

main.o: main.c
	$(CC) $(Flags) -c main.c

.Phony:clean all

clean:
	rm -f *.o *.a stringProg
