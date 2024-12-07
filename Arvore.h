#ifndef ARVORE_H
#define ARVORE_H
#include "ListaFilmes.h"

// Struct do nó da árvore
typedef struct no {
    char *usuario; // Nome do usuário
    int nusp; // Número USP
    ListaPonteiros filmes; // Lista de ponteiros para os filmes do usuário
    struct no *esq; // Ponteiro para o filho esquerdo
    struct no *dir; // Ponteiro para o filho direito
} No;

typedef struct {
    No *raiz;
} Arvore;

// Declarações
void InicializarArvore(Arvore *A);
void Cadastrar(Arvore *A, char *nome, int nusp, int *flag);
No* BuscarUsuario(No* raiz, int nusp);
void InserirFilmeUsuario(Arvore *arvore, ListaFilmes *filmes, int nusp, char *titulo, int *contador);
void ImprimirFilmesUsuario(Arvore *A, int nusp);
void ImprimirUsuarios(Arvore *A);
void ImprimirAux(No *n);
void EstaNaArvore(Arvore *A, int nusp);

#endif
