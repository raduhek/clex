# Compile tests
CC=gcc
CCFLAGS=-Wall -c

all:
	$(CC) $(CCFLAGS) reader.c
	$(CC) $(CCFLAGS) node.c
	$(CC) $(CCFLAGS) automata.c
	$(CC) $(CCFLAGS) token.c
	$(CC) $(CCFLAGS) utils.c
	$(CC) $(CCFLAGS) keywords.c
	$(CC) $(CCFLAGS) lexer.c
	$(CC) -o main main.c lexer.o reader.o node.o automata.o token.o utils.o keywords.o

clean_o:
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf token reader main automata utils lexer keywords

debug: CCFLAGS += -DDEBUG -g
debug: all

help:
	@echo "Available make options:"
	@echo ""
	@echo "make -> build executable"
	@echo "make debug -> build executable with debug option"
	@echo "make clean -> remove executable and object files"
	@echo "make clean_o -> remove object files"
	@echo "make help -> display this text"
