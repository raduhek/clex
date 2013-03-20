# Compile tests
CC=gcc
CCFLAGS=-Wall -c

all:
	$(CC) $(CCFLAGS) reader.c
	$(CC) $(CCFLAGS) node.c
	$(CC) $(CCFLAGS) automata.c
	$(CC) $(CCFLAGS) token.c
	$(CC) $(CCFLAGS) utils.c
	$(CC) $(CCFLAGS) lexer.c
	$(CC) -o main main.c reader.o node.o automata.o token.o utils.c lexer.c
	make clean_o

automata:
	$(CC) $(CCFLAGS) node.c
	$(CC) -o automata automata.c node.o

clean_o:
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf token reader main automata utils lexer

debug: CCFLAGS += -DDEBUG -g
debug: all

