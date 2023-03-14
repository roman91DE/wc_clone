CC=gcc-12
CFLAGS=-Wall -Werror -g

all: wc

wc: main.o wc.o
	$(CC) $(CFLAGS) main.o wc.o -o wc

main.o: main.c wc.h
	$(CC) $(CFLAGS) -c main.c

wc.o: wc.c wc.h
	$(CC) $(CFLAGS) -c wc.c

clean:
	rm -f *.o wc
