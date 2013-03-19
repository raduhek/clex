# Compile tests
CC=gcc
CCFLAGS=-Wall -c

all:
	$(CC) $(CCFLAGS) reader.c
	$(CC) -o main main.c reader.o

automata:
	$(CC) $(CCFLAGS) node.c
	$(CC) -o automata automata.c node.o

clean:
	rm -rf *.o
	rm -rf main automata

