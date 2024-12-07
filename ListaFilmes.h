#ifndef LISTAFILMES_H
#define LISTAFILMES_H

// Struct que guarda o nome do filme (alocado dinamicamente)
typedef struct bloco {
    char* titulo;
    struct bloco *prox;
} Bloco;

// Struct que guarda uma lista de filmes 
typedef struct {
    Bloco *ini, *fim;
} ListaFilmes;

// Struct que guarda um ponteiro para um filme
typedef struct ponteiros {
    Bloco *filme; // Ponteiro para um filme na lista geral
    struct ponteiros *prox;
} BlocoPonteiro;

// Struct que guarda uma lista de ponteiros para filmes
typedef struct {
    BlocoPonteiro *ini, *fim;
} ListaPonteiros;

// Declarações das funções
void InicializarListaFilmes(ListaFilmes *filmes);
void InicializarListaPonteiros(ListaPonteiros *ponteiros);
void CadastrarFilme(ListaFilmes *lista, char *titulo);
Bloco *BuscarFilme(ListaFilmes *filmes, char *titulo);
void ImprimirFilmes(ListaFilmes *filmes);
int EstaNaLista(ListaFilmes *filmes, char *titulo);
void ArquivarFilmes(ListaFilmes *filmes, FILE *file);
void ExcluirFilmes(ListaFilmes *filmes);

#endif