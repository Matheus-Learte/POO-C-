#ifndef FIGHTER
    #define FIGHTER

        #include <string>

        class Lutador{
            public:
                Lutador(std::string nome, std::string nacionalidade, int idade, float altura, float peso, int vitorias, int derrotas, int empates);

                void apresentar();

                void status();

                void ganharLuta();

                void perderLuta();

                void empatarLuta();

                std::string getNome();

                std::string getNacionalidade();

                std::string getCategoria();

                void setNome(std::string nome);
                
                void setNacionalidade(std::string country);

                void setCategoria();

                int getIdade();

                int getVitorias();

                int getDerrotas();

                int getEmpates();

                void setIdade(int age);

                void setVitorias(int victories);

                void setDerrotas(int losts);

                void setEmpates(int draws);

                float getAltura();

                float getPeso();

                void setAltura(float height);

                void setPeso(float weight);

            private:
                std::string nome, nacionalidade, categoria;
                int idade, vitorias=0, derrotas=0, empates=0;
                float altura, peso;
        };
        
#endif