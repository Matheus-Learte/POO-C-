#include "Luta.hpp"

void Luta::marcarLuta(Lutador* fighter1, Lutador* fighter2){
    if(fighter1->getCategoria()==fighter2->getCategoria() && fighter1!=fighter2){
        this->setAprovada(true);
        this->setDesafiante_1(fighter1);
        this->setDesafiante_2(fighter2);
        this->setNome(fighter1->getNome()+" X "+fighter2->getNome());
    }else{
        this->setAprovada(false);
        this->setDesafiante_1(NULL);
        this->setDesafiante_2(NULL);
        this->setNome("Not Approved");
    }
}

void Luta::Lutar(){
    if(this->getAprovada()){
        this->Desafiante_1->apresentar();
        this->Desafiante_2->apresentar();
        
        std::srand(time(0));

        int valor=std::rand()%3;
        this->setRounds(std::rand()%12+1);

        switch(valor){
            case 0:
                std::cout<<"A luta empatou"<<std::endl;

                this->Desafiante_1->empatarLuta();
                this->Desafiante_2->empatarLuta();
                this->setGanhador("Empatou");
                break;
            
            case 1:
                std::cout<<"O "<<this->Desafiante_1->getNome()<<" ganhou em uma luta de "<<this->getRounds()<<" round(s)"<<std::endl;

                this->Desafiante_1->ganharLuta();
                this->Desafiante_2->perderLuta();
                this->setGanhador(this->getDesafiante_1()->getNome()+" ganhou");
                break;
            
            case 2:
                std::cout<<"O "<<this->Desafiante_2->getNome()<<" ganhou em uma luta de "<<this->getRounds()<<" round(s)"<<std::endl;

                this->Desafiante_1->perderLuta();
                this->Desafiante_2->ganharLuta();
                this->setGanhador(this->getDesafiante_1()->getNome()+" ganhou");
                break;
        }

    }else
        std::cout<<"Essa luta não foi aprovada"<<std::endl;
}

void Luta::setDesafiante_1(Lutador* fighter){
    this->Desafiante_1=fighter;
}

void Luta::setDesafiante_2(Lutador* fighter){
    this->Desafiante_2=fighter;
}

void Luta::setRounds(int aux){
    this->rounds=aux;
}

void Luta::setAprovada(bool aux){
    this->aprovada=aux;
}

void Luta::setNome(std::string nome){
    this->nome=nome;
}

void Luta::setGanhador(std::string winner){
    this->ganhador=winner;
}

Lutador* Luta::getDesafiante_1(){
    return this->Desafiante_1;
}

Lutador* Luta::getDesafiante_2(){
    return this->Desafiante_2;
}

int Luta::getRounds(){
    return this->rounds;
}

bool Luta::getAprovada(){
    return this->aprovada;
}

std::string Luta::getNome(){
    return this->nome;
}

std::string Luta::getGanhador(){
    return this->ganhador;
}