#include <stdio.h>
#include <iostream>
using namespace std;

const int Tmax = 3;

typedef int Apontador;

typedef struct {
    int Chave;
    /*outros componentes*/
} TInfo;

typedef struct {
    TInfo Item[Tmax];
    Apontador Primeiro;
    Apontador Ultimo;
    int Total;
} TFila;

void adc(int& pos);
bool Cheia(TFila& Fila);
bool Vazia(TFila& Fila);
void Cria (TFila& Fila);
void Enqueue(TFila& Fila,TInfo Item);
void Dequeue (TFila& Fila);
void Imprime (TFila& Fila);

void adc(int& pos){
    pos++;
    if(pos == Tmax)
        pos = 0;
}

bool Cheia(TFila& Fila){
    return Fila.Total == Tmax?true:false;
}

bool Vazia(TFila& Fila){
    return Fila.Total == 0?true:false;
}

void Cria(TFila& Fila){
    Fila.Primeiro = 0;
    Fila.Ultimo = 0;
    Fila.Total = 0;
}

void Enqueue(TFila& Fila, TInfo Item){
    if(Cheia(Fila))
        cout << "ERRO: Fila cheia." << endl;
    else{
        Fila.Item[Fila.Ultimo] = Item;
        adc(Fila.Ultimo);
        Fila.Total++;
    }
}

void Dequeue(TFila& Fila){
    if(Vazia(Fila))
        cout << "ERRO: Fila vazia." << endl;
    else{
        adc(Fila.Primeiro);
        Fila.Total--;
    }
}

void Imprime(TFila& Fila){
    if (Vazia(Fila))
        cout << "Erro : A Fila está vazia.\n" << endl;
    else
    {
        int ax=0;
        while(ax<Fila.Total)
        {
            ax++;
            int p=Fila.Primeiro;
            adc(p);
        }
        cout << endl;
    }
    int i=0;
    cout << "\nPRIMEIRO = " << Fila.Primeiro << endl;
    cout << "ULTIMO = " << Fila.Ultimo << endl;
    cout << "TOTAL = " << Fila.Total << endl;
    while(i < Fila.Total)
    {
        i++;
        cout << Fila.Item[Fila.Primeiro].Chave << " ";
        adc(Fila.Primeiro);
    }
    cout << endl;
}
