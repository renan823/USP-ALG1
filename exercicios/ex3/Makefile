all: main.o item.o pilha.o balanceada.o
	gcc main.o balanceada.o item.o pilha.o -Wall -std=c99 -o ex -lm

run: 
	./ex

item.o:
	gcc -c item.c

pilha.o:
	gcc -c pilha.c

main.o:
	gcc -c main.c

balanceada.o:
	gcc -c balanceada.c

clean:
	rm *.o ex *.zip

zip:
	zip -R exercicio.zip '*.c' '*.h' 'Makefile'

load:
	make clean && make && make run