#include <iostream>
#include <string>
#include "Lutador.hpp"

Lutador::Lutador(std::string nome, std::string nacionalidade, int idade, float altura, float peso, int vitorias, int derrotas, int empates){
    this->setNome(nome);
    this->setNacionalidade(nacionalidade);
    this->setIdade(idade);
    this->setAltura(altura);
    this->setPeso(peso);
    this->setVitorias(vitorias);
    this->setDerrotas(derrotas);
    this->setEmpates(empates);
}

void Lutador::apresentar(){
    std::cout<<"Apresentando nosso lutador!!!"<<std::endl; 
    std::cout<<"Lutador: "<<this->nome<<std::endl;
    std::cout<<"Origem: "<<this->nacionalidade<<std::endl;
    std::cout<<this->idade<<" anos"<<std::endl;
    std::cout<<this->altura<<" metros de altura"<<std::endl;
    std::cout<<"Pesando: "<<this->peso<<" Kg"<<std::endl;
    std::cout<<"Ganhou: "<<this->vitorias<<std::endl;
    std::cout<<"Perdeu: "<<this->derrotas<<std::endl;
    std::cout<<std::endl;
}

void Lutador::status(){
    std::cout<<this->getNome()<<std::endl;
    std::cout<<"É um peso "<<this->getCategoria()<<std::endl;
    std::cout<<this->getVitorias()<<" vitórias"<<std::endl;
    std::cout<<this->getDerrotas()<<" derrotas"<<std::endl;
    std::cout<<this->getEmpates()<<" empates"<<std::endl;
    std::cout<<"\n";
}

void Lutador::ganharLuta(){
    setVitorias(1);
}

void Lutador::perderLuta(){
    setDerrotas(1);
}

void Lutador::empatarLuta(){
    setEmpates(1);
}

void Lutador::setNome(std::string nome){
    this->nome=nome;
}

void Lutador::setNacionalidade(std::string country){
    this->nacionalidade=country;
}

void Lutador::setIdade(int age){
    this->idade=age;
}

void Lutador::setAltura(float height){
    this->altura=height;
}

void Lutador::setPeso(float weight){
    this->peso=weight;
    this->setCategoria();
}

void Lutador::setCategoria(){
    if(this->peso<52.2 || this->peso>120.2){
        this->categoria="Inválido";
    }else
    if(this->peso<=70.3){
        this->categoria="Leve";
    }else
    if(this->peso<=83.9){
        this->categoria="Medio";
    }else
        this->categoria="Pesado";
}

void Lutador::setVitorias(int victories){
    this->vitorias+=victories;
}

void Lutador::setDerrotas(int losts){
    this->derrotas+=losts;
}

void Lutador::setEmpates(int draws){
    this->empates+=draws;
}

std::string Lutador::getNome(){
    return this->nome;
}

std::string Lutador::getNacionalidade(){
    return this->nacionalidade;
}

int Lutador::getIdade(){
    return this->idade;
}

float Lutador::getAltura(){
    return this->altura;
}

float Lutador::getPeso(){
    return this->peso;
}

std::string Lutador::getCategoria(){
    return this->categoria;
}

int Lutador::getVitorias(){
    return this->vitorias;
}

int Lutador::getDerrotas(){
    return this->derrotas;
}

int Lutador::getEmpates(){
    return this->empates;
}