#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
using namespace std;
#include "pilhaPonteiro.h"

void setDados(TInfo& Item){
    cout << "Informe o código: ";
    cin >> Item.Chave;
}


int main()
{
    setlocale(LC_ALL,"portuguese");
    TInfo Item;
    int opcao, topo;
    char opcC;
    TPilha p;
    Cria(p);

    do{
        system("cls");
        Imprime(p);
        cout << "\nMenu: " << endl
             << "1. Empilha" << endl
             << "2. Desempilha" << endl
             << "3. Topo" << endl
             << "4. Imprime" << endl
             << "5. Sair do Programa" << endl
             << "Informe sua opção: ";
             cin >> opcao;

        switch(opcao){
        case 1:
            setDados(Item);
            Empilha(p, Item);
            break;
        case 2:
            Desempilha(p);
            break;
        case 3:
            topo = Topo(p);
            if(topo == 0)
                cout << "Pilha vazia" << endl;
            else
                cout << "Topo da pilha: " << topo << endl;
            break;
        case 4:
            Imprime(p);
            break;
        case 5:
            exit(0);
        default:
            cout << "Opção Inválida." << endl;
        }

        cout << "\nDe novo? [s/n]: ";
        cin >> opcC;
    } while(opcC == 'S' || opcC == 's');
    return 0;
}
