#include <iostream>
#include "Lutador.hpp"
#include "Lista.cpp"

int main(void){
    List* lista=new List();

    lista->add_list(new Lutador("Pretty Boy", "França", 31, 1.75, 68.9, 11, 2, 1));
    lista->print_list();

    std::cout<<"-----------------------------------------------------------------------------"<<std::endl<<std::endl;

    lista->add_list(new Lutador("Putscript", "Brasil", 29, 1.68, 57.8, 14, 2, 3));
    lista->print_list();

    std::cout<<"-----------------------------------------------------------------------------"<<std::endl<<std::endl;

    lista->add_list(new Lutador("Snapshadow", "EUA", 35, 1.65, 80.9, 12, 2, 1));
    lista->print_list();

    std::cout<<"-----------------------------------------------------------------------------"<<std::endl<<std::endl;
    
    lista->print_list();

    lista->apagar_tudo();

    std::cout<<lista->get_size()<<std::endl;
    lista->print_list();
return 0;
}