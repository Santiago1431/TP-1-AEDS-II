CC = gcc
CFLAGS = -Wall -g
OBJ = main.o funcs.o pilha.o

all: labirinto

labirinto: $(OBJ)
	$(CC) $(CFLAGS) -o labirinto $(OBJ)

main.o: main.c funcs.h pilha.h
	$(CC) $(CFLAGS) -c main.c

funcs.o: funcs.c funcs.h pilha.h
	$(CC) $(CFLAGS) -c funcs.c

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

clean:
	rm -f $(OBJ) labirinto
