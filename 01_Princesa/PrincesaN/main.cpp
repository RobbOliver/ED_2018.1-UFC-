#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

/*
void pop_front(int vet[], int * qtd){
    for(int i = 0; i < *qtd - 1; i++)
        vet[i] = vet[i + 1];
    *qtd -= 1;
}

void push_back(int vet[], int * qtd, int value){
    vet[*qtd] = value;
    *qtd += 1;
}*/

void rodar(list<int> &lista){

    lista.push_back(lista.front());
    lista.pop_front();
}


void mostrar(list<int> &lista){
    for(int x : lista)
        cout << x << " ";
    cout << "\n";
}


int main(){
    cout << "Digite o valor da quantidade e primeiro elemento a matar" << endl;
    int qtd = 0;
    scanf("%i", &qtd);

    int primeiro = 0;
    cin >> primeiro;

    // Coletou as informações.
    //qtd para a quantidade e primeiro para saber quem vai começar.

    list<int> lista;
        for(int i = 1; i <= qtd; i++){ //Aqui eu só listei do primeiro elemento de cara um da quantidade.
        lista.push_back(i);
        mostrar(lista);
        }


while(lista.size() > 1){
   for(int i = 0; i < primeiro; i++){
       cout << " " << endl;
       rodar(lista);
       mostrar(lista);//Para melhor esclarecimento da vizualização, deixar de comentar essa linha
   }
   lista.pop_front();
    primeiro = lista.front();
           mostrar(lista);
}

//        lista.pop_front();
//        mostrar(lista);
//    while(lista.front() != primeiro){
//        rodar(lista);
//    }
//    mostrar(lista);
//    while(lista.size() > 1){
//            for (int i = 0; i < lista.front(); ++i) {

//                rodar(lista);
//            }
//            lista.pop_front();
//            mostrar(lista);
//    }
    return 0;
}
