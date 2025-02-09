#include <iostream>
#include <string>

    typedef struct no_{
        Lutador* point;
        struct no_* next;
    }NO;

    class List{
        public:
            List(){
                this->start=NULL;
                this->end=NULL;
                this->size=0;
            } 

            void add_list(Lutador* aux){
                if(!this->full_list()){
                    NO* p= new NO;

                    p->point=aux;
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

                    while(aux!=NULL && aux->point->getNome()!=name){
                        ant=aux;
                        aux=aux->next;
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

                        delete aux->point;
                        delete aux;
                        this->size--;
                    }
                }else
                    std::cout<<"Lista vázia"<<std::endl;
            }

            Lutador* search_list(std::string name){
                NO* aux=this->start;

                while(aux!=NULL){
                    if(aux->point->getNome()==name){
                        return aux->point;
                    }
                    aux=aux->next;
                }

            return NULL;
            }

            void print_list(){
                print_aux(this->start);
            }

            int get_size(){
                return this->size;
            }

        private:
            NO* start;
            NO* end;
            int size;

            bool empty_list(){
                if(start==NULL){
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
                    aux->point->apresentar();
                    print_aux(aux->next);
                }
            }
    };
