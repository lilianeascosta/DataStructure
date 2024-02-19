#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "funcoes.h"
using namespace std;

int main()
{
    string resp;
    int opc;
    TLista Lista;
    do{
        system("cls");
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Cria" << endl;
        cout << "2. Insere Inicio" << endl;
        cout << "3. Insere Posicao" << endl;
        cout << "4. Insere Final" << endl;
        cout << "5. Remove Inicio" << endl;
        cout << "6. Remove Final" << endl;
        cout << "7. Pesquisa Remove" << endl;
        cout << "8. Imprime" << endl;
        cout << "9. Interface" << endl;
        printf("Informe sua opc: ");
        scanf("%d", &opc);

        switch(opc){
            TInfo ultDado, priDado, item;
            int p, item7;

            case 1: cria(Lista); break;

            case 2: printf("Informe o dado que deseja inserir no inicio: ");
                    scanf("%d", &priDado);
                    insereInicio(Lista, priDado);
                    break;

            case 3: cout << "Informe a posicao que deseja ser inserida: ";
                    cin >> p;
                    printf("Informe o dado que deseja inserir nessa posicao: ");
                    scanf("%d", &item);
                    inserePosicao(Lista, p, item); break;

            case 4: printf("Informe o dado que deseja inserir no final: ");
                    scanf("%d", &ultDado);
                    insereFinal(Lista, ultDado);
                    break;

            case 5: removeInicio(Lista); break;

            case 6: removeFinal(Lista); break;

            case 7: printf("Informe o indice do vetor que deseja remover o seu respectivo dado: ");
                    scanf("%d", &item7);
                    pesquisaRemove(Lista, item7);
                    break;

            case 8: imprime(Lista); break;

            default: cout << "opc invalida";
        }

        cout << "De novo? (s/n): " << endl;
        cin >> resp;
    }while(resp == "S" || resp == "s");
    return 0;
}
