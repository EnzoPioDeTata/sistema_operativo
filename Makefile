all: main

main: progetto2.o sistema_operativo.o calcolatrice.o indovina_numero.o
	gcc -o main progetto2.o sistema_operativo.o calcolatrice.o indovina_numero.o -lm

progetto2.o: progetto2.c prototipi.h
	gcc -c -o progetto2.o progetto2.c

sistema_operativo.o: sistema_operativo.c prototipi.h
	gcc -c -o sistema_operativo.o sistema_operativo.c

calcolatrice.o: calcolatrice.c prototipi.h
	gcc -c -o calcolatrice.o calcolatrice.c

indovina_numero.o: indovina_numero.c prototipi.h
	gcc -c -o indovina_numero.o indovina_numero.c
clean:
	rm -f *.o main
