# Compile tests
CC=gcc
CCFLAGS=-Wall -c

all:
	$(CC) $(CCFLAGS) reader.c
	$(CC) $(CCFLAGS) node.c
	$(CC) $(CCFLAGS) automata.c
	$(CC) -o main main.c reader.o node.o automata.o

automata:
	$(CC) $(CCFLAGS) node.c
	$(CC) -o automata automata.c node.o

clean:
	rm -rf *.o
	rm -rf reader main automata

