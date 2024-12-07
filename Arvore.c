#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaFilmes.h"
#include "Arvore.h"

// Função para inicializar a árvore
void InicializarArvore(Arvore *A)
{
    A->raiz = NULL; // Define a raiz como NULL, indicando que a árvore está vazia
}

// Função que cadastra um usuário na árvore
// (inserido pelo valor do seu nusp)
void Cadastrar(Arvore *A, char *nome, int nusp, int *flag)
{
    // Aloca memória para o novo nó
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    novo->usuario = strdup(nome); // Copia o nome para o nó
    novo->nusp = nusp;
    InicializarListaPonteiros(&novo->filmes); // Inicializa a lista de filmes do usuário
    novo->esq = NULL;
    novo->dir = NULL;

    // Verifica se a raiz está vazia
    if (A->raiz == NULL)
    {
        A->raiz = novo; // Faz a raiz apontar para o novo nó
        return;
    }

    // Caso contrário, percorre a árvore para encontrar a posição correta
    No *atual = A->raiz;
    No *anterior = NULL;

    while (atual != NULL)
    {
        anterior = atual;
        if (nusp < atual->nusp)
        {
            // Vai para a subárvore esquerda
            atual = atual->esq;
        }
        else if (nusp > atual->nusp)
        {
            // Vai para a subárvore direita
            atual = atual->dir;
        }
        else
        {
            // Número USP já existe, não insere duplicado
            printf("Erro: ja existe um usuario com o número USP '%d'\n", nusp);
            free(novo->usuario);
            free(novo);
            (*flag) = 1;
            return;
        }
    }

    // Insere o novo nó no lugar apropriado
    if (nusp < anterior->nusp)
    {
        anterior->esq = novo;
    }
    else
    {
        anterior->dir = novo;
    }
}

// Função que busca um usuário e retorna o nó dele
No *BuscarUsuario(No *raiz, int nusp)
{
    if (raiz == NULL)
    {
        return NULL; // Caso base: não encontrou o usuário
    }

    if (raiz->nusp == nusp)
    {
        return raiz; // Encontrou o usuário
    }

    // Decide qual lado da árvore explorar
    if (nusp < raiz->nusp)
    {
        return BuscarUsuario(raiz->esq, nusp);
    }
    else
    {
        return BuscarUsuario(raiz->dir, nusp);
    }
}

// Função que insere o título na lista do usuário
void InserirFilmeUsuario(Arvore *arvore, ListaFilmes *filmes, int nusp, char *titulo, int *contador)
{
    No *usuario = BuscarUsuario(arvore->raiz, nusp);
    Bloco *filme = BuscarFilme(filmes, titulo);

    // Verifica se o filme já está na lista de filmes do usuário
    BlocoPonteiro *aux = usuario->filmes.ini;
    while (aux != NULL)
    {
        if (aux->filme == filme)
        {
            printf("Erro: Filme '%s' ja esta na lista do usuario '%s'.\n", titulo, usuario->usuario);
            return;
        }
        aux = aux->prox;
    }

    // Cria um novo nó para o filme na lista de ponteiros
    BlocoPonteiro *novo = (BlocoPonteiro *)malloc(sizeof(BlocoPonteiro));
    if (novo == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo->filme = filme;
    novo->prox = NULL;

    // Insere o novo nó na lista de filmes do usuário
    if (usuario->filmes.ini == NULL)
    {
        // Lista estava vazia
        usuario->filmes.ini = novo;
        usuario->filmes.fim = novo;
    }
    else
    {
        // Lista não está vazia
        usuario->filmes.fim->prox = novo;
        usuario->filmes.fim = novo;
    }

    (*contador)++; // Atualiza o contador
}

// Função que imprime todos os filmes de um usuário
void ImprimirFilmesUsuario(Arvore *A, int nusp)
{

    No *usuario = BuscarUsuario(A->raiz, nusp);
    BlocoPonteiro *aux = usuario->filmes.ini;
    while (aux != NULL)
    {
        printf("- %s\n", aux->filme->titulo);
        aux = aux->prox;
    }
}

// Função que Imprime todos os usuários cadastrados
void ImprimirUsuarios(Arvore *A)
{
    No *atual = A->raiz;
    printf("Listagem completa:\n");
    ImprimirAux(atual);
}

// Função auxiliar para imprimir os usuários
void ImprimirAux(No *n)
{
    if (n != NULL)
    {
        ImprimirAux(n->esq);
        printf("Usuario: '%s'\n", n->usuario);
        printf("Numero USP: %d\n\n", n->nusp);
        ImprimirAux(n->dir);
    }
}

// Função que retorna se um usuário está ou não na árvore
void EstaNaArvore(Arvore *A, int nusp)
{
    char resposta;
    No *aux = BuscarUsuario(A->raiz, nusp);
    if (aux == NULL)
        printf("Este usuario nao existe!\n");
    else
    {
        printf("Este usuario existe! Deseja ver suas informacoes? (S ou N): ");
        while (getchar() != '\n')
            ; // Limpando o buffer
        scanf("%c", &resposta);
        if (resposta == 'S' || resposta == 's')
        {
            printf("Nome: %s\n", aux->usuario);
            printf("Numero USP: %d\n", aux->nusp);
            printf("Filmes favoritos: ");
            ImprimirFilmesUsuario(A, nusp);
        }
        else
        {
            return;
        }
    }
}

void ArquivarArvore(Arvore *A, FILE *file)
{
    ArquivarRecursivo(A->raiz, file);
}

void ArquivarRecursivo(No *raiz, FILE *file)
{
    if (raiz == NULL)
    {
        return;
    }

    // Percorrer a árvore em ordem (esquerda, raiz, direita)
    ArquivarRecursivo(raiz->esq, file);

    // Escrever o valor do nó no arquivo
    int tamanho = strlen(raiz->usuario) + 1;
    char *temp = (char *)malloc(tamanho * sizeof(char)); // Aloca memória para temp
    if (temp == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    strcpy(temp, raiz->usuario);
    fprintf(file, "N° USP: %d\n", raiz->nusp);
    fprintf(file, "Nome: %s\n", temp);

    free(temp); // Libera a memória alocada para evitar vazamentos

    ArquivarRecursivo(raiz->dir, file);
}
