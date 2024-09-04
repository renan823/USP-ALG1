all: main.o item.o pilha.o rpn.o
	gcc main.o rpn.o item.o pilha.o -Wall -std=c99 -o ex -lm

run: 
	./ex

item.o:
	gcc -c item.c

pilha.o:
	gcc -c pilha.c

main.o:
	gcc -c main.c

rpn.o:
	gcc -c rpn.c

clean:
	rm *.o ex *.zip

zip:
	zip -R exercicio.zip '*.c' '*.h' 'Makefile'

load:
	make clean && make && make run