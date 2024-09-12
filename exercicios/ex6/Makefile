all: fila.o main.o 
	gcc -std=c99 -Wall main.o  item.o fila.o -o ex

main.o:
	gcc -c main.c

fila.o:
	gcc -c fila.c

run:
	./ex

clear:
	rm main.o fila.o ex *.zip

zip:
	zip -R deque.zip 'apagar.c'