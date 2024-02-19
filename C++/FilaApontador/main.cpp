#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
#include "ListaApontador.h"

void setDados(TInfo& item){ //função pra sempre que vc precisar pedir o dado
    cout << "\nInforme o codigo: ";
    cin >> item.Chave;
}

void setPosicao(int& pos){ //função pra sempre que vc precisar pedir a posição
    cout << "\nInforme a posicao: ";
    cin >> pos;
}

int main(){
    setlocale (LC_ALL, "portuguese");
    TInfo item;
    int p, opcao;
    string opcC;
    TLista l;
    Cria(l);
    Imprime(l);

    do{
    system("cls");
    Imprime(l);
     cout << "\nMenu: " << endl
         << "1. Insere no Inicio\n"
         << "2. Insere na Posicao\n"
         << "3. Insere no Final\n"
         << "4. Remove no Inicio\n"
         << "5. Remove no Final\n"
         << "6. Pesquisa e Remove\n"
         << "7. Imprime da frente pra trás\n"
         << "8. Imprime de trás pra frente\n"
         << "Opcao: ";
         cin >> opcao;

        switch(opcao){
        case 1:
            setDados(item);
            InsereInicio(l,item);
            break;
        case 2:
            setDados(item);
            setPosicao(p);
            InserePosicao(l,p,item);
            break;
        case 3:
            setDados(item);
            InsereFinal(l,item);
            break;
        case 4:
            RemoveInicio(l);
            break;
        case 5:
            RemoveFinal(l);
            break;
        case 6:
            setDados(item);
            PesquisaRemove(l, item);
            break;
        case 7:
            Imprime(l);
            break;
        case 8:
            exit(0);
        default:
            cerr << "Opcao incorreta\n";
        }
        cout << "De novo? (s/n): ";
        cin >> opcC;
   } while(opcC == "s");
    return 0;
}
