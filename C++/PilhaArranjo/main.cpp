#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include "pilhaArranjo.h"
using namespace std;

void setDados(TInfo& Item){
    cout << "Informe o código: ";
    cin >> Item.Chave;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    TPilha Pilha;
    TInfo Item;
    Cria(Pilha);
    int opcMenu;
    char opcC;

    do{
        system("cls");
        Imprime(Pilha);
        cout << "\nMENU" << endl;
        cout << "1. Empilha" << endl;
        cout << "2. Desempilha" << endl;
        cout << "3. Topo" << endl;
        cout << "4. Imprime" << endl;
        cout << "5. Sair do Programa" << endl;
        cout << "Informe sua opção: " << endl;
        cin >> opcMenu;

        switch(opcMenu){
        case 1:
            setDados(Item);
            Empilha(Pilha,Item);
            break;
        case 2:
            Desempilha(Pilha);
            break;
        case 3:
            Topo(Pilha);
            break;
        case 4:
            Imprime(Pilha);
            break;
        case 5:
            exit(0);
        default:
            cout << "Opção Inválida." << endl;
        }
        cout << "\nDe novo? (s/n): ";
        cin >> opcC;
    } while(opcC == 's' || opcC == 'S');

    return 0;
}
