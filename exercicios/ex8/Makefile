all: lista.o main.o
	gcc item.o lista.o main.o -Wall -std=c99 -o ex

main.o:
	gcc -c main.c

lista.o:
	gcc -c lista.c

run:
	./ex

clear:
	rm lista.o main.o ex