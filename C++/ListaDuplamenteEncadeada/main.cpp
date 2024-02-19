#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
using namespace std;
#include "ListaDupEncadeada.h"

void setDados(TInfo& item){
    cout << "Informe o codigo: ";
    cin >> item.chave;
}

void setPosicao(int& pos){
    cout << "Informe a posição: ";
    cin >> pos;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
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
             << "1. Insere no Início" << endl
             << "2. Insere na Posição" << endl
             << "3. Insere no Final" << endl
             << "4. Remove no Início" << endl
             << "5. Remove no Final" << endl
             << "6. Pesquisa e Remove" << endl
             << "7. Imprime da frente pra trás" << endl
             << "8. Imprime de trás pra frente" << endl
             << "9. Fim do Programa" << endl
             << "Opção: ";
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
                PesquisaRemove(l,item);
                break;
             case 7:
                Imprime(l);
                break;
             case 8:
                ImprimeAnterior(l);
                break;
             case 9:
                exit(0);
             default:
                cerr << "Opção Inválida." << endl;


             }
             cout << "De novo? (s/n): ";
             cin >> opcC;
    } while(opcC == "s");
    return 0;
}
