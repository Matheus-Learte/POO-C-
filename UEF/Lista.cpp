#include <iostream>
#include <string>

typedef struct no_{
    Lutador* point;
    Luta* fight;
    struct no_* next;
}NO;

class List{
    public:
        List(char aux){
            this->start=NULL;
            this->end=NULL;
            this->size=0;
            this->type=aux;
        } 

        void add_list(void* aux){
            if(!this->full_list()){
                NO* p= new NO;

                if(this->type=='F'){
                    p->point=(Lutador*)aux;
                    p->fight=NULL;
                }else{
                    p->fight=(Luta*)aux;
                    p->point=NULL;
                }
                p->next=NULL;

                if(this->start==NULL){
                    this->start=p;
                    this->end=p;
                    this->size++;
                }else{
                    this->end->next=p;
                    this->end=p;
                    this->size++;
                }
            }else
                std::cout<<"Não há mais memória"<<std::endl;
        }

        void remove_list(std::string name){
            if(!this->empty_list()){
                NO* aux=this->start;
                NO* ant=NULL;

                if(this->type=='F'){
                    while(aux!=NULL && aux->point->getNome()!=name){
                        ant=aux;
                        aux=aux->next;
                    }
                }else{
                    while(aux!=NULL && aux->fight->getNome()!=name){
                        ant=aux;
                        aux=aux->next;
                    }
                }

                if(aux==NULL){
                    std::cout<<"Não encontrado"<<std::endl;
                }else{
                    if(aux==this->start){
                        this->start=aux->next;
                    }else
                        ant->next=aux->next;

                    if(aux==this->end){
                        this->end=ant;
                    }
                    
                    if(this->type=='L'){
                        delete aux->fight;
                    }else
                        delete aux->point;

                    delete aux;
                    this->size--;
                }
            }else
                std::cout<<"Lista vázia"<<std::endl;
        }

        void* search_list(std::string name){
            NO* aux=this->start;

            if(this->type=='F'){
                while(aux!=NULL){
                    if(aux->point->getNome()==name){
                        return aux->point;
                    }
                    aux=aux->next;
                }
            }else{
                while(aux!=NULL){
                    if(aux->fight->getNome()==name){
                        return aux->fight;
                    }
                    aux=aux->next;
                }
            }
            std::cout<<"Não encontrado"<<std::endl;

        return NULL;
        }

        void print_list(){
            if(!this->empty_list()){
                print_aux(this->start);
            }else
                std::cout<<"lista vázia"<<std::endl;
        }

        int get_size(){
            return this->size;
        }

        ~List(){
            apagador_aux(this->start);
            this->start=NULL;
            this->end=NULL;
            std::cout<<"Tudo apagado"<<std::endl;
        }

    private:
        NO* start;
        NO* end;
        int size;
        char type;

        bool empty_list(){
            if(this->start==NULL){
                return true;
            }

        return false;
        }

        bool full_list(){
            NO* aux= new NO;

            if(aux==NULL){
                return true;
            }
            delete aux;

        return false;
        }

        void print_aux(NO* aux){
            if(aux!=NULL){
                if(this->type=='L'){
                    std::cout<<aux->fight->getNome()<<" : "<<aux->fight->getGanhador()<<std::endl;
                }else
                    std::cout<<aux->point->getNome()<<std::endl;
                print_aux(aux->next);
            }
        }

        void apagador_aux(NO* aux){
            if(aux!=NULL){
                apagador_aux(aux->next);

                if(this->type=='F'){
                    delete aux->point;
                }else
                    delete aux->fight;

                delete aux;
                this->size--;
            }
        }
};