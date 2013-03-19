# Compile tests
CC=gcc
CCFLAGS=-Wall -c

all:
	$(CC) $(CCFLAGS) reader.c
	$(CC) $(CCFLAGS) node.c
	$(CC) $(CCFLAGS) automata.c
	$(CC) $(CCFLAGS) token.c
	$(CC) -o main main.c reader.o node.o automata.o token.o
	make clean_o

automata:
	$(CC) $(CCFLAGS) node.c
	$(CC) -o automata automata.c node.o

clean_o:
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf token reader main automata

debug: CCFLAGS += -DDEBUG -g
debug: all

