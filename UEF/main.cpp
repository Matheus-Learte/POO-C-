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

int main(void){
    List* lista= new List();
    std::string choice;

    while(1){
        std::cout<<"O que você deseja fazer?\n'add' - Cadastra um novo lutador\n'list' - Lista todos os lutadores\n'search' - Procura um certo lutador e imprime as informações dele\n'fight' - Coloca para lutar 2 pessoas\n"<<std::endl;
        std::cin>>choice;

        if(choice=="add"){
            add_fighter(lista);
        }else
        if(choice=="list"){
            lista->print_list();
        }else
        if(choice=="fight"){

        }else
        if(choice=="exit"){

        }else{
            break;
        }
    }
    delete lista;

return 0;
}