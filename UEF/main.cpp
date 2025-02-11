#include <iostream>
#include <vector>
#include <string>
#include "Lutador.hpp"
#include "Luta.hpp"
#include "Lista.cpp"

void add_fighter(List* lista){
    std::string nome, country;
    int idade, vde[3];
    float altura, peso;

    std::cout<<"Digite o nome do lutador"<<std::endl;
    std::cin>>nome;

    std::cout<<"Digite o páis de origem do lutador"<<std::endl;
    std::cin>>country;

    std::cout<<"Digite a idade do lutador"<<std::endl;
    std::cin>>idade;

    std::cout<<"Digite a altura do lutador"<<std::endl;
    std::cin>>altura;

    std::cout<<"Digite o peso do lutador"<<std::endl;
    std::cin>>peso;

    std::cout<<"Digite o número de vitórias, derrotas e empates"<<std::endl;
    std::cin>>vde[0]>>vde[1]>>vde[2];

    lista->add_list(new Lutador(nome, country, idade, altura, peso, vde[0], vde[1], vde[2]));
}

void make_fight(List* lista, List* lutas){
    Lutador* desafiante, *desafiado;
    std::string nome1, nome2;
    Luta* fight;

    while(1){
        std::cout<<"Qual lutador será o desafiador?"<<std::endl;
        std::cin>>nome1;

        desafiante=(Lutador*)lista->search_list(nome1);

        if(desafiante!=NULL){
            break;
        }else
            std::cout<<"Tente novamente"<<std::endl;
    }

    while(1){
        std::cout<<"Qual lutador será o desfiado?"<<std::endl;
        std::cin>>nome2;

        desafiado=(Lutador*)lista->search_list(nome2);

        if(desafiado!=NULL){
            break;
        }else
            std::cout<<"Tente novamente"<<std::endl;
    }
    fight=new Luta();

    fight->marcarLuta(desafiante, desafiado);

    if(fight->getAprovada()){
        std::cout<<std::endl;
        fight->Lutar();
        lutas->add_list(fight);
    }else
        std::cout<<"Os dois lutadores não são da mesma categoria, ou seja, a luta não pode ser realizada"<<std::endl;
}

int main(void){
    List* lista= new List('F');
    List* lutas= new List('L');
    std::string choice;

    while(1){
        std::cout<<"O que você deseja fazer? (Obs: Digite as palavras);"<<std::endl;
        std::cout<<"1° 'add' - Cadastra um novo lutador;"<<std::endl;
        std::cout<<"2° 'remove' - Remove um determinado lutador da lista;"<<std::endl;
        std::cout<<"3° 'list-fighters' - Lista todos os lutadores;"<<std::endl;
        std::cout<<"4° 'search-fighter' - Procura um certo lutador e imprime as informações dele;"<<std::endl;
        std::cout<<"5° 'fight' - Coloca para lutar 2 pessoas;"<<std::endl;
        std::cout<<"6° 'list-fights' - Lista todas as lutas feitas;"<<std::endl;
        std::cout<<"7° 'search-fight' - Procura certa luta (Obs: a luta do jogadorA x jogadorB é diferente da jogadorB x jogadorA)."<<std::endl;
        std::cout<<"R: ";
        std::cin>>choice;
        std::cout<<std::endl;

        if(choice=="add"){
            add_fighter(lista);
            std::cout<<std::endl;
        }else
        if(choice=="remove"){
            std::string aux;

            std::cout<<"Qual lutador deve ser removido da lista?"<<std::endl;
            std::cin>>aux;

            lista->remove_list(aux);
            std::cout<<std::endl;
        }else
        if(choice=="list-fighters"){
            lista->print_list();
            std::cout<<std::endl;
        }else
        if(choice=="search-fighters"){
            std::string aux;
            Lutador* fighter;

            std::cout<<"Qual lutador deve ser procurado?"<<std::endl;
            std::cin>>aux;
            std::cout<<std::endl;

            fighter=(Lutador*)lista->search_list(aux);

            if(fighter!=NULL){
                fighter->apresentar();
            }else
                std::cout<<"Não encontrado"<<std::endl<<std::endl;
        }else
        if(choice=="fight"){
            make_fight(lista, lutas);
            std::cout<<std::endl;
        }else
        if(choice=="list-fights"){
            lutas->print_list();
            std::cout<<std::endl;
        }else
        if(choice=="search-fight"){
            std::string aux;
            Luta* luta;

            std::cout<<"Qual luta deve ser procurada?"<<std::endl;
            std::cin.ignore();
            std::getline(std::cin, aux);
            std::cout<<std::endl;

            luta=(Luta*)lutas->search_list(aux);

            if(luta!=NULL){
                std::cout<< luta->getNome()<<" : "<< luta->getGanhador()<< " : Número de rounds: ";
                if(luta->getGanhador()=="Empatou"){
                    std::cout<<"12\n"<<std::endl;
                }else
                    std::cout<<luta->getRounds()<<"\n"<<std::endl;
            }else
                std::cout<<"Não encontrado"<<std::endl<<std::endl;
        }else
        if(choice=="remove-fight"){
            std::string senha;

            std::cout<<"Digite a senha mestra"<<std::endl;
            std::cin>>senha;

            if(senha=="052005"){
                std::string aux;

                std::cout<<"Qual luta deve ser removida da lista?"<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, aux);

                lutas->remove_list(aux);
            }
            std::cout<<std::endl;
        }else
        if(choice=="exit"){
            break;
        }else{
            std::cout<<"Comando inválido. Tente novamente.\n"<<std::endl;
        }
    }
    delete lista;
    delete lutas;

return 0;
}