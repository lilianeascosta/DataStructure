
const int Tmax = 8000;

typedef int Apontador;

typedef struct{
     string chave ;
     string municipio ;
     string Rodovia ;
     string Data ;
     string Dia_Semana ;
     string Horario ;
     string Tipo_Acidente ;
     string Mortos ;
     string Feridos ;
     string Descricao ;
     int disponivel ;
} TInfo;

typedef struct{
    TInfo Item[Tmax];
    Apontador Primeiro;
    Apontador Ultimo;
} TLista;
