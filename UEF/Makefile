all: Lutador.o teste.o
	g++ Lutador.o teste.o -Wall -std=c++17 -o oi

Lutador.o:
	g++ -c Lutador.cpp -o Lutador.o

teste.o:
	g++ -c teste.cpp -o teste.o

clean:
	rm *.o oi