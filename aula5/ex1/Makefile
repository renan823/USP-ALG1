all: main.o stack.o 
	gcc main.o item.o stack.o -Wall -std=c99 -o ex -lm

run: 
	./ex

stack.o:
	gcc -c stack.c

main.o:
	gcc -c main.c

clean:
	rm stack.o main.o ex *.zip

load:
	make clean && make && make run