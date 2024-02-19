typedef struct NodoLista *Apontador;

typedef struct {
    int Chave;
} TInfo;

struct NodoLista{
    TInfo Item;
    struct NodoLista *Proximo;
};

typedef struct{
    struct NodoLista *Primeiro;
    struct NodoLista *Ultimo;
} TLista;


void Cria(TLista& Lista);
bool Vazia (TLista Lista);
void InsereInicio(TLista& Lista, TInfo Item);
void InserePosicao(TLista& Lista, int pos, TInfo Item);
void InsereFinal(TLista& Lista, TInfo Item);
void RemoveInicio(TLista& Lista);
void RemoveFinal(TLista Lista);
void PesquisaRemove(TLista& Lista, TInfo Item);
void Imprime(TLista Lista);


void Cria(TLista& Lista){
    Lista.Primeiro = (Apontador) malloc(sizeof(struct NodoLista));
    Lista.Ultimo = Lista.Primeiro;
    Lista.Primeiro -> Proximo = NULL;
}

bool Vazia (TLista Lista){
    return Lista.Primeiro == Lista.Ultimo?true:false;
}

void InsereInicio(TLista& Lista, TInfo Item){
    Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
    p -> Item = Item;
    p -> Proximo = Lista.Primeiro->Proximo;
    Lista.Primeiro -> Proximo = p;

    if(p->Proximo == NULL)
        Lista.Ultimo = p;
}

void InserePosicao(TLista& Lista, int pos, TInfo Item){
    Apontador p = (Apontador)malloc(sizeof(struct NodoLista));
    Apontador ant = Lista.Primeiro;
    p->Item = Item;
    for(int i=0; i<pos; i++){
        ant = ant->Proximo;
    }
    p->Proximo = ant->Proximo;
    ant->Proximo = p;
    if(p->Proximo == NULL)
        Lista.Ultimo = p;
}

void InsereFinal(TLista& Lista, TInfo Item){
    Apontador p = (Apontador) malloc (sizeof(struct NodoLista));
    p->Item = Item;
    p->Proximo = Lista.Ultimo->Proximo;
    Lista.Ultimo->Proximo = p;

    if(p->Proximo == NULL)
        Lista.Ultimo = p;
}

void RemoveInicio(TLista& Lista){
    if(Vazia(Lista))
        cout << "Erro: A lista esta vazia.\n" <<endl;
    else{
        Apontador p = Lista.Primeiro->Proximo;
        cout << "Elemento Removido = " << p->Item.Chave << endl;
        Lista.Primeiro->Proximo = p->Proximo;
        if(Lista.Primeiro->Proximo == NULL)
            Lista.Ultimo = Lista.Primeiro;
        free(p);
    }
}

void PesquisaRemove(TLista& Lista, TInfo Item){
    if(Vazia(Lista))
        cout << "Erro: Lista vazia." << endl;
    else{
        Apontador anterior = Lista.Primeiro;
        Apontador excluir = Lista.Primeiro->Proximo;
        while(excluir != NULL){
            if(excluir->Item.Chave == Item.Chave)
                anterior->Proximo = excluir->Proximo;
            anterior = anterior->Proximo;
            excluir = excluir->Proximo;
        }
        if(Lista.Primeiro->Proximo == NULL)
            Lista.Ultimo = Lista.Primeiro;
        free(excluir);
        free(anterior);
        cout << "Item removido com sucesso." << endl;
    }
}

void RemoveFinal(TLista Lista){
    if(Vazia(Lista))
        cout << "Erro: A lista esta vazia" << endl;
    else{
        Apontador aux = Lista.Primeiro;
        Apontador penul;
        while(aux ->Proximo != NULL){
            penul = aux;
            aux = aux->Proximo;
        }
        penul -> Proximo = NULL;
        Lista.Ultimo = penul;
        free(aux);
        if(Lista.Primeiro->Proximo==NULL)
            Lista.Ultimo = Lista.Primeiro;
    }
}


void Imprime(TLista Lista){
    cout << "Itens na LISTA: " << endl;
    if(Vazia(Lista))
        cout << "Lista esta vazia." << endl;
    else{
        Apontador aux;
        aux = Lista.Primeiro->Proximo;
        while(aux != NULL){
            cout << aux->Item.Chave << " ";
            aux = aux->Proximo;
        }
        cout << endl;
    }
}
