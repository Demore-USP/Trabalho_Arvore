#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaFilmes.h"
// Função para inicializar uma lista de filmes
void InicializarListaFilmes(ListaFilmes *filmes) {
    filmes->ini = NULL;
    filmes->fim = NULL;
}

// Função para inicializar uma lista de ponteiros
void InicializarListaPonteiros(ListaPonteiros *ponteiros) {
    ponteiros->ini = NULL;
    ponteiros->fim = NULL;
}



