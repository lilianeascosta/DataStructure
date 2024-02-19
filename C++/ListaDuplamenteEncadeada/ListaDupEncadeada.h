#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

typedef struct NodoLista *Apontador;

typedef struct{
    int chave;
    /*outros componentes*/
}TInfo;

struct NodoLista{
    TInfo Item;
    struct NodoLista *Anterior;
    struct NodoLista *Proximo;
}; // struct da modelagem de cada componente da Lista

typedef struct{
    struct NodoLista *Primeiro;
    struct NodoLista *Ultimo;
} TLista; //TLista é só o controlador de toda a cadeia de NodoListas que serão criados.


void Cria(TLista& Lista);
bool Vazia(TLista Lista);
void InsereInicio(TLista& Lista, TInfo Item);
void InserePosicao(TLista& Lista, int pos, TInfo Item);
void InsereFinal(TLista& Lista, TInfo Item);
//void RemoveInicio(TLista Lista);
//void RemoveFinal(TLista Lista);
//void PesquisaRemove(TLista& Lista, TInfo Item);
void Imprime(TLista Lista);
void ImprimeAnterior(TLista Lista);

void Cria(TLista& Lista){
    Lista.Primeiro = (Apontador) malloc (sizeof(struct NodoLista));
    Lista.Ultimo = Lista.Primeiro;
    Lista.Primeiro->Anterior = NULL;
    Lista.Primeiro->Proximo = NULL;
}

bool Vazia(TLista Lista){
    return Lista.Primeiro == Lista.Ultimo?true:false;
}

void InsereInicio(TLista& Lista, TInfo Item){
    Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
    p->Item = Item;
    p->Anterior = NULL;
    p->Proximo = Lista.Primeiro->Proximo;

    if(p->Proximo == NULL)
        Lista.Ultimo = p;
    else
        Lista.Primeiro->Proximo->Anterior = p;
    Lista.Primeiro->Proximo = p;
}

void InserePosicao(TLista& Lista, int pos, TInfo Item){
    if(pos == 1){
        fflush(stdin);
        InsereInicio(Lista, Item);
    }
    else{
        Apontador aux = Lista.Primeiro->Proximo;
        int i = 1;
        while((i<pos-1) && (aux!=NULL)){
            i++;
            aux = aux->Proximo;
        }

        if((aux == NULL) || (pos<1)){
            cerr << "Posição não existe" <<  endl;
            getch();
        }
        else{
            Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
            p->Item = Item;
            p->Proximo = aux->Proximo;
            p->Anterior = aux;
            aux->Proximo = p;

            if(p->Proximo == NULL)
                Lista.Ultimo = p;
            else
                p->Proximo->Anterior = p;
        }
    }
}

void InsereFinal(TLista& Lista, TInfo Item){
    Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
    p->Item = Item;
    p->Proximo = NULL;

    if(Vazia(Lista)){
        p->Anterior = NULL;
    }
    else{
        p->Anterior = Lista.Ultimo;
    }
    Lista.Ultimo->Proximo = p;
    Lista.Ultimo = p;
}

void Imprime(TLista Lista){
    cout << "Itens na LISTA: " << endl;
    if(Vazia(Lista))
        cout << "Lista está vazia." << endl;
    else{
        Apontador aux ;
        aux = Lista.Primeiro->Proximo;
        while(aux != NULL){
            printf(" %d ", aux->Item);
            aux = aux->Proximo;
        }
        cout << endl;
    }
}


void ImprimeAnterior(TLista Lista){
    cout << "Itens de trás pra frente: " << endl;
    if(Vazia(Lista))
        cout << "A lista está vazia." << endl;
    else{
        Apontador aux = Lista.Ultimo;
        while(aux != NULL){
            cout << " " << aux->Item.chave;
            aux = aux->Anterior;
        }
        cout << endl;
        free(aux);
    }
}

void RemoveInicio(TLista& Lista){
    if(Vazia(Lista))
        cout << "Erro: A lista esta vazia.\n" <<endl;
    else{
        Apontador p = Lista.Primeiro->Proximo;
        //cout << "Elemento Removido = " << p->Item.Chave << endl;
        if(p->Proximo == NULL)
            Lista.Primeiro->Proximo = NULL;
        else{
            Lista.Primeiro->Proximo = p->Proximo;
            p->Proximo->Anterior = NULL;
        }
        if(Lista.Primeiro->Proximo == NULL)
            Lista.Ultimo = Lista.Primeiro;
        free(p);
    }
}

void RemoveFinal(TLista Lista){
    if(Vazia(Lista)){
        cout << "Erro: A lista esta vazia" << endl;
        getch();
    }
    else{
        Apontador p = Lista.Primeiro->Proximo;
        Apontador aux = Lista.Ultimo;
        if(p->Proximo == NULL){
            RemoveInicio(Lista);
        }
        else{
            Lista.Ultimo = Lista.Ultimo->Anterior;
            Lista.Ultimo->Proximo = NULL;
        }
        free(p);
        free(aux);
    }
}


void PesquisaRemove(TLista& Lista, TInfo Item){
    if(Vazia(Lista)){
        cout << "Erro: Lista vazia." << endl;
        getch();
    }

    else{
        if(Lista.Primeiro->Proximo->Item.chave == Item.chave) //verifica se é o primeiro da lista
            RemoveInicio(Lista);
        else if(Lista.Ultimo->Item.chave == Item.chave) //verifica se é o ultimo da lista
            RemoveFinal(Lista);
        else{
            Apontador aux = Lista.Primeiro;

            while((aux->Item.chave != Item.chave) && (aux->Proximo != NULL))
                aux = aux->Proximo;

            if(aux->Proximo == NULL){
                cout << "Item não encontrado" << endl;
            }
            else{
                if(aux->Proximo == NULL)
                    Lista.Ultimo = aux;
                else{
                    aux->Anterior->Proximo = aux->Proximo;
                    aux->Proximo->Anterior = aux->Anterior;
                }
            }
        }
    }
}
