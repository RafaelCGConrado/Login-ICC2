all: hash.o main.o
	gcc hash.o main.o -o p_e_c -std=c99 -Wall

funcoes.o:
	gcc -c hash.c -o hash.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o p_e_c

run:
	./p_e_c


