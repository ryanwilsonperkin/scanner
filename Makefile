CFLAGS= -Wall -g

all: scanner
	gcc scanner.o -o scanner

scanner: scanner.c
	gcc $(CFLAGS) -c scanner.c

clean:
	rm *.o
