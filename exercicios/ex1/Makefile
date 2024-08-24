all: main.o ponto.o circulo.o
	gcc main.o ponto.o circulo.o -Wall -std=c99 -o ex1

run: 
	./ex1

ponto.o:
	gcc -c ponto.c

circulo.o:
	gcc -c circulo.c

main.o:
	gcc -c main.c

clean:
	rm *.o ex1