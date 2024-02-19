#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct NodoPilha *Apontador ;

typedef struct {
    int Chave ;
    /* outros componentes */
} TInfo ;

struct NodoPilha {
    TInfo Item;
    struct NodoPilha *Proximo ;
};

typedef struct {
    struct NodoPilha * Primeiro ;
    struct NodoPilha * Ultimo ;
} TPilha ;

bool Vazia(TPilha& Pilha);
void Cria(TPilha& Pilha);
void Empilha(TPilha& Pilha , TInfo Item );
void Desempilha(TPilha& Pilha );
int Topo(TPilha& Pilha );
void Imprime(TPilha& Pilha );


bool Vazia(TPilha& Pilha){
    return Pilha.Ultimo==Pilha.Primeiro?true:false;
}

void Cria(TPilha& Pilha){
    Pilha.Primeiro = (Apontador) malloc(sizeof(struct NodoPilha));
    Pilha.Ultimo = Pilha.Primeiro;
    Pilha.Primeiro -> Proximo = NULL;
    cout << "Célula Cabeça da Pilha criada com sucesso." << endl; // teste
}

void Empilha(TPilha& Pilha, TInfo Item){
    Apontador p = (Apontador) malloc(sizeof(struct NodoPilha));
    p->Item = Item;
    p->Proximo = Pilha.Primeiro->Proximo;
    Pilha.Primeiro->Proximo = p;
    if(p->Proximo==NULL)
        Pilha.Ultimo = p;
}

void Desempilha(TPilha& Pilha){
    if(Vazia(Pilha))
        cerr << "Pilha Vazia." << endl;
    else{
        Apontador p = Pilha.Primeiro->Proximo;
        Pilha.Primeiro->Proximo = p->Proximo;
        if(Pilha.Primeiro->Proximo == NULL)
            Pilha.Ultimo = Pilha.Primeiro;
        free(p);
    }
}

void Imprime(TPilha& Pilha){
    cout << "Itens da PIILHA: " << endl;
    if(Vazia(Pilha))
        cout << "Pilha está vazia" << endl;
    else{
        Apontador aux;
        aux = Pilha.Primeiro->Proximo;
        int count = 0;
        while(aux != NULL && count < 10){
            cout << aux->Item.Chave << " ";
            count++;
            aux = aux->Proximo;
        }
    }

    cout << endl;
}

int Topo(TPilha& Pilha){
    if(Vazia(Pilha))
        return 0;
        //cerr << "Pilha vazia." << endl;
    else
        return Pilha.Primeiro->Proximo->Item.Chave;
        //printf("Item do topo: %d\n", Pilha.Primeiro->Proximo->Item.Chave);

}
