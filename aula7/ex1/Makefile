all: Deque.o main.o
	gcc -std=c99 -Wall main.o Deque.o -o ex

main.o:
	gcc -c main.c

Deque.o:
	gcc -c Deque.c

run:
	./ex

clear:
	rm main.o Deque.o ex