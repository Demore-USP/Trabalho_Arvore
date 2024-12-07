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

// Função para cadastrar um filme
void CadastrarFilme(ListaFilmes *lista, char *titulo) {

    // Aloca memória para um novo nó
    Bloco *novo = (Bloco *)malloc(sizeof(Bloco)); 
    if (!novo) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    novo->titulo = strdup(titulo); 
    novo->prox = NULL; 

    //Lógica de inserção em ordem alfabética (com verificação de duplicidade)
    Bloco *ant = NULL;
    Bloco *aux = lista->ini;

    // Percorre a lista até encontrar a posição correta de inserir o filme
    while (aux != NULL && strcmp(aux->titulo, titulo) < 0) {
        ant = aux;
        aux = aux->prox; // Avança para o próximo nó
    }

    // Se o filme já existir, libera a memória 
    if (aux != NULL && strcmp(aux->titulo, titulo) == 0) {
        free(novo->titulo);
        free(novo);
        return;
    }

    if (ant == NULL) {
        novo->prox = lista->ini;
        lista->ini = novo; 
    } else {
        ant->prox = novo;
        novo->prox = aux;
    }

    if (aux == NULL) { 
        lista->fim = novo; 
    }
}

Bloco *BuscarFilme(ListaFilmes *filmes, char *titulo) {
    Bloco *aux = filmes->ini;

    while (aux != NULL) {
        if (strcmp(aux->titulo, titulo) == 0) {
            return aux; // Encontrou o filme
        }
        aux = aux->prox;
    }

    return NULL; 
}

void ImprimirFilmes(ListaFilmes *filmes) {
    Bloco *aux = filmes->ini;
    int contador = 0;
    while(aux != NULL) {
        contador++;
        aux = aux->prox;
    }
    aux = filmes->ini;
    printf("Listagem completa: ");
    for(int i=0; i<contador; i++) {
        printf("%s", aux->titulo);
        aux = aux->prox;
        if(i<(contador-1)) 
            printf(", ");
    }
}

int EstaNaLista(ListaFilmes *filmes, char *titulo) {
    Bloco *aux = filmes->ini;
    while(aux != NULL) {
        if(strcmp(aux->titulo, titulo) == 0) {
            return (1);
        }
        aux = aux->prox;
    }
    return (0);
}

void ArquivarFilmes(ListaFilmes *filmes, FILE *file) {
    Bloco *aux = filmes->ini;
    while(aux != NULL) {
        fprintf(file, "%s\n", aux->titulo);
        aux = aux->prox;
    }
}