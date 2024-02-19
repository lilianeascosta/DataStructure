#include <stdio.h>
#include <iostream>
using namespace std;

const int Tmax = 10;

typedef int Apontador;

typedef struct {
    int Chave;
    /* outros componentes */
} TInfo;

typedef struct {
    TInfo Item [Tmax];
    Apontador Topo;
} TPilha;

void Cria (TPilha& Pilha);
void Empilha (TPilha& Pilha , TInfo Item);
void Desempilha (TPilha& Pilha);
void Topo (TPilha& Pilha);
void Imprime (TPilha& Pilha);

bool Cheia(TPilha& Pilha){
    return Pilha.Topo==Tmax?true:false;
}

bool Vazia(TPilha& Pilha){
    return Pilha.Topo==0?true:false;
}

void Cria(TPilha& Pilha){
    Pilha.Topo = 0;
}

void Empilha (TPilha& Pilha, TInfo Item) {
    if ( Cheia ( Pilha ))
        cout << " Erro : Pilha cheia " << endl ;
    else
        Pilha.Item [Pilha.Topo++] = Item ;
}

void Desempilha (TPilha& Pilha) {
    if (Vazia (Pilha))
        cout << " Erro : Pilha vazia .\n" << endl ;
    else
        Pilha.Topo--;
}

void Topo(TPilha& Pilha){
    if(Vazia(Pilha))
        cerr << "Pilha Vazia" << endl;
    else
        printf("Item do Topo: %d\n", Pilha.Item[Pilha.Topo-1]);
}

void Imprime(TPilha& Pilha){
    if(Vazia(Pilha))
        cerr << "Pilha Vazia" << endl;
    else{
        cout << "Itens da Pilha: " << endl;
        for(int i=0; i<Pilha.Topo; i++)
            printf("%d ", Pilha.Item[i]);
    }
}
