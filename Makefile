CFLAGS= -Wall -g

all: scanner match
	gcc scanner.o match.o -o scanner

scanner: scanner.c
	gcc $(CFLAGS) -c scanner.c

match: match.c
	gcc $(CFLAGS) -c match.c

clean:
	rm *.o
