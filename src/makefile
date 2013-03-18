# Compile tests
CC=gcc
CCFLAGS=-Wall -c

all:
	$(CC) $(CCFLAGS) reader.c
	$(CC) -o main main.c reader.o
clean:
	rm -rf *.o
	rm -rf *.c

