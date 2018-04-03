#include <iostream>

using namespace std;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade)
            return;
            //this->reserve(2 * _capacitade);
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }

    int size(){
        return this->_size;
    }
    int capacity(){
        return this->_capacidade;
    }

    void reserve(int capacity){
        Vetor jamanga(this->size());

        for(int i=0;i<_size;i++){
            jamanga.push_back(this->at(i));
        }
    if(this->capacity()<=capacity){
         this->_capacidade = capacity;
         this->_size = 0;
         this->_data = new int[capacity];
        for(int i=0;i<jamanga.size();i++){
            this->push_back(jamanga.at(i));
        }
    }
    else{
        this->_capacidade = capacity;
        this->_size = 0;
        this->_data = new int[capacity];
       for(int i=0;i<capacity;i++){
           this->push_back(jamanga.at(i));
       }


    }

    }


};

int main(){
 Vetor pivet(10);

    for(int i=0;i<10;i++){
      pivet.push_back(4);
    }

    for(int i=0;i<10;i++){

    cout << pivet.at(i) << endl;

   }
    cout  << endl;
    pivet.reserve(5);

    for(int i=0;i<pivet.size();i++){
    cout << pivet.at(i) << endl;

   }


    return 0;
}










