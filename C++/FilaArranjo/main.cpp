#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include "FilaArranjo.h"
using namespace std;

void setDados(TInfo& Item){
    cout << "Informe o código: ";
    cin >> Item.Chave;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    TFila Fila;
    TInfo Item;
    Cria(Fila);
    int opcMenu;
    char opcC;

    do{
        system("cls");
        Imprime(Fila);
        cout << "\nMENU" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Imprime" << endl;
        cout << "4. Sair do Programa" << endl;
        cout << "Informe sua opção: " << endl;
        cin >> opcMenu;

        switch(opcMenu){
        case 1:
            setDados(Item);
            Enqueue(Fila,Item);
            break;
        case 2:
            Dequeue(Fila);
            break;
        case 3:
            Imprime(Fila);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Opção Inválida." << endl;
        }
        cout << "\nDe novo? (s/n): ";
        cin >> opcC;
    } while(opcC == 's' || opcC == 'S');

    return 0;
}
