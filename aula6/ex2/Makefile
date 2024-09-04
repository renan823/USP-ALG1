all: main.o fila.o 
	gcc main.o item.o fila.o -Wall -std=c99 -o ex -lm

run: 
	./ex

fila.o:
	gcc -c fila.c

main.o:
	gcc -c main.c

clean:
	rm fila.o main.o ex *.zip

load:
	make clean && make && make run