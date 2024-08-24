all: racional.o main.o
	gcc main.o racional.o -std=c99 -Wall -o racionais
racional.o:
	gcc -c racional.c
maio.o:
	gcc -c main.o
clean:
	rm -rf *.o racionais