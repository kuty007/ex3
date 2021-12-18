CC = gcc
AR = ar
CFLAGS = -Wall -Werror

all: strings


strings: main.o
	${CC} ${CFLAGS} -o strings main.o

main.o: main.c
	${CC} ${CFLAGS} -c main.c

clean:
	rm -f *.a *.o strings