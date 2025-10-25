CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -O2

OBJS=equipe_paroquial.o lista_equipes.o

all: teste_equipe teste_lista

equipe_paroquial.o: equipe_paroquial.c equipe_paroquial.h
	$(CC) $(CFLAGS) -c equipe_paroquial.c

lista_equipes.o: lista_equipes.c lista_equipes.h equipe_paroquial.h
	$(CC) $(CFLAGS) -c lista_equipes.c

teste_equipe: teste_equipe.c $(OBJS)
	$(CC) $(CFLAGS) -o teste_equipe teste_equipe.c $(OBJS)

teste_lista: teste_lista.c $(OBJS)
	$(CC) $(CFLAGS) -o teste_lista teste_lista.c $(OBJS)

clean:
	rm -f *.o teste_equipe teste_lista