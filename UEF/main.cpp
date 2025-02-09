#include <iostream>
#include <vector>
#include "Lutador.hpp"
#include "Luta.hpp"
#include "Lista.cpp"

int main(void){
    std::vector<Lutador*>fighter(6);

    fighter[0]= new Lutador("Pretty Boy", "França", 31, 1.75, 68.9, 11, 2, 1);
    fighter[1]= new Lutador("Putscript", "Brasil", 29, 1.68, 57.8, 14, 2, 3);
    fighter[2]= new Lutador("Snapshadow", "EUA", 35, 1.65, 80.9, 12, 2, 1);
    fighter[3]= new Lutador("Dead Code", "Austrália", 28, 1.93, 81.6, 13, 0, 2);
    fighter[4]= new Lutador("Ufocobol", "Brasil", 37, 1.70, 119.3, 5, 4, 3);
    fighter[5]= new Lutador("Nerdaard", "EUA", 30, 1.81, 105.7, 12, 2, 4);

    for(int i=0; i<fighter.size(); i++){
        fighter[i]->apresentar();
        fighter[i]->status();
    }

    Luta* fight= new Luta();

    fight->marcarLuta(fighter[0], fighter[1]);
    fight->Lutar();

return 0;
}