CC=gcc
CFLAGS=-Wall -g
OBJS=scanner.o match.o
PROGNAME=scanner

all: scanner

scanner: $(OBJS)
	$(CC) $(OBJS) -o $(PROGNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o
