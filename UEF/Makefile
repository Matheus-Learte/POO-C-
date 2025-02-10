all: Lutador.o Luta.o main.o
	g++ Lutador.o Luta.o main.o -Wall -std=c++17 -o peixe

Lutador.o:
	g++ -c Lutador.cpp -o Lutador.o

Luta.o:
	g++ -c Luta.cpp -o Luta.o

main.o:
	g++ -c main.cpp -o main.o

run:
	./peixe

clean:
	rm *o peixe