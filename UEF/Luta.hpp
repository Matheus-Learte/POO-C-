#ifndef LUTA
    #define LUTA

    #include <iostream>
    #include <cstdlib>
    #include "Lutador.hpp"

    class Luta{
        public:
            void marcarLuta(Lutador* fighter1, Lutador* fighter2);

            void Lutar();

            std::string getGanhador();

            std::string getNome();

        private:
            Lutador *Desafiante_1, *Desafiante_2;
            int rounds;
            bool aprovada;
            std::string nome, ganhador;

            void setDesafiante_1(Lutador* fighter);

            void setDesafiante_2(Lutador* fighter);

            void setRounds(int aux);

            void setAprovada(bool aux);

            void setNome(std::string nome);

            void setGanhador(std::string winner);

            Lutador* getDesafiante_1();

            Lutador* getDesafiante_2();

            int getRounds();

            bool getAprovada();
    };

#endif