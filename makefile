all: prova.exe
prova.exe: llista.o main.o
	gcc llista.o main.o -o prova.exe
llista.o: llista.c llista.h 
	gcc -c llista.c
main.o: main.c
	gcc -c main.c
