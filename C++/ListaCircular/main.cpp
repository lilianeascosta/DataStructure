#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
struct no {
    int dado;
    struct no *prox;
};

typedef struct {
    struct no *inicio;
    // struct no *fim;
} ListaC;

void create(ListaC *q){
    q->inicio=NULL;
    // q->fim=NULL;
}

int isEmpty(ListaC q){
    if (q.inicio==NULL)
        return (true);
    else
        return (false);
}

int inserirInicio(ListaC *lista, int valor)
{
    cout << "Inserindo o valor " << valor << "\n"; // teste
    struct no *novoNo;
    if (lista->inicio == NULL)
    {
        if (valor == 20){
            cout << "entrei com 20 aqui, algo errado";
        } // teste

        novoNo = (struct no *) malloc(sizeof(struct no));
        novoNo->dado = valor;
        lista->inicio = novoNo;
        // lista->fim = novoNo;
        novoNo->prox = lista->inicio; // lista->inicio pode ser apenas novoNo?
        return(true);
    }
    novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo->dado = valor;
    novoNo->prox = lista->inicio;
    lista->inicio = novoNo;
    cout << "Acho que inseriu o 20"; // teste
    // lista->fim->prox = novoNo;
    return(true);
}

void inverter(ListaC *resp){
    no* atual = resp->inicio; 
    resp->inicio= NULL; 
    while (atual) { 
      
        no* corrente = atual; 
        atual = atual->prox; 
        corrente->prox = resp->inicio; 
        resp->inicio = corrente; 
      
    } 
    // swap(resp->inicio,resp->fim);
    // swap precisa de dois parametros para trocar, então para inverter mesmo será necessária alguma outra lógica.
} 

void imprimir(ListaC lista) {
    if(lista.inicio==NULL)
        return;
    // ListaC* primeiro = lista;
    struct no *aux = lista.inicio;
    do
    {
        printf("%d\n", lista.dado);
        lista = lista -> prox;
    }while(lista != primeiro);
    printf("\n");
}

// void imprimir(ListaC lista)
// {
//     struct no *aux;
//     if (!isEmpty(lista))
//     {
//         aux = lista.inicio;
//         // if (aux != lista.fim)
//         if (aux->prox != lista.inicio)
//         {
//             do
//             {
//                 printf("%d ", aux->dado);

//                 aux = aux->prox;
//             }
//             while (aux != lista.inicio);
//         }
//         else{
//             printf("%d ", aux->dado);
//             aux = aux->prox;
//         }
//     }
//     else
//         cout<<"Lista vazia..."<<endl;

// }

int main (){
    int opction;
    int x,q,res=0;
    ListaC L;

    create(&L);

    // MENU
    cout << "1. Inserir Elemento" << "\n";
    cout << "2. Remover Elemento" << "\n";
    cout << "3. Pesquisar Elemento" << "\n";
    cout << "4. Imprimir Lista Circular" << "\n";
    cout << "Digite sua opção: ";
    cin >> opction;

    switch(opction) {
        case 1:
            int valor;
            char continuar;
            system("clear");
            cout << "1. Inserir no início / final" << "\n";
            cout << "2. Inserir numa posição específica" << "\n";
            cout << "3. Inserir no meio" << "\n";
            cout << "Digite sua opção: ";
            cin >> opction;
            switch (opction)
            {
                case 1: 
                    do{
                        // system("clear");
                        cout << "Informe o valor do elemento que você deseja inserir: ";
                        cin >> valor;
                        cout << "Valor = " << valor; // teste
                        inserirInicio(&L, valor); 
                        cout << "Inserir no início novamente? (S|s): ";
                        cin >> continuar;
                        imprimir(L);
                    } while (continuar == 's' || continuar == 'S');
                    break;
                // case 2: inserirPosicao(); break;
                // case 3: inserirMeio(); break;
                default: cout << "Opção inválida.";
            }
            break;
        case 2:
            system("clear");
            cout << "1. Remover no início / final" << "\n";
            cout << "2. Remover numa posição específica" << "\n";
            cout << "3. Remover no meio" << "\n";
            cout << "Digite sua opção: ";
            cin >> opction;
            switch (opction)
            {
                // case 1: removerInicio(); break;
                // case 2: removerPosicao(); break;
                // case 3: removerMeio(); break;
                default: cout << "Opção inválida.";
            }
            break;
        case 3:
            system("clear");
            cout << "Informe o valor do elemento de pesquisa: ";
            // pesquisar(x);
        default: cout << "Opção inválida.";
    }

    // insereinicio(&L, 1);
    // insereinicio(&L, 2);
    // insereinicio(&L, 3);
    // insereinicio(&L, 4);
    // insereinicio(&L, 5);


    return 0;
}