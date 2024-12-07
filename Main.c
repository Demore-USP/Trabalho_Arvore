#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaFilmes.h"
#include "Arvore.h"

// Funções utilizadas
void CriarCadastro(Arvore *arvore, ListaFilmes *filmes);
void ListarUsuarios(Arvore *arvore, ListaFilmes *filmes);
void BuscaUsuario(Arvore *arvore, ListaFilmes *filmes);
void ListarFilmes(Arvore *arvore, ListaFilmes *filmes);
void BuscaFilme(Arvore *arvore, ListaFilmes *filmes);
void ProduzirArquivo(Arvore *arvore, ListaFilmes *filmes);
void DadosTecnicos(Arvore *arvore, ListaFilmes *filmes);
void RemoverCadastro(Arvore *arvore, ListaFilmes *filmes);

int main (void){

    Arvore arvore;
    ListaFilmes filmes;

    InicializarArvore(&arvore);
    InicializarListaFilmes(&filmes);
    int opcao = 0;

    while(opcao != 9){
        // Tela de opções do usuário
        printf("\n");
        printf("      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("      |          Escolha uma opcao abaixo:      |\n");
        printf("      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~           ~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("| 1) Criar um cadastro |           | 2) Listar usuarios |\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~           ~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~~                ~~~~~~~~~~~~~~~~~~~~\n");
        printf("| 3) Buscar usuario |                | 4) Listar filmes |\n");
        printf("~~~~~~~~~~~~~~~~~~~~~                ~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("| 5)  Buscar filme |         | 6) Produzir arquivo .txt |\n");
        printf("~~~~~~~~~~~~~~~~~~~~         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~         ~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
        printf("| 7)  Dados tecnicos |         | 8) Remover um cadastro |\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~         ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~        ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("| 9) Alterar cadastro |        | 10) Finalizar programa |\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~        ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1){
        CriarCadastro(&arvore, &filmes);

        } else if (opcao == 2){
        ListarUsuarios(&arvore, &filmes);

        } else if (opcao == 3){
        BuscaUsuario(&arvore, &filmes);

        } else if (opcao == 4){
        ListarFilmes(&arvore, &filmes);

        } else if (opcao == 5){
        BuscaFilme(&arvore, &filmes);

        } else if (opcao == 6){
        ProduzirArquivo(&arvore, &filmes);

        } else if (opcao == 7){
        DadosTecnicos(&arvore, &filmes);

        } else if (opcao == 8){
        RemoverCadastro(&arvore, &filmes);

        } else if (opcao == 9){
            //lógica se necessário
            break;

        } else {
            printf("Opcao invalida! Por favor, digite uma das opcoes disponiveis!\n");
        }
    } // Fim do loop

    printf("Programa encerrado!");
    return 0;
}

// Função que permite o usuário criar um cadastro no sistema
void CriarCadastro(Arvore *arvore, ListaFilmes *filmes){
    // Variáveis auxiliares
    char nome[100];
    char titulo[100];
    int nusp, contador = 0, flag = 0; // Contador pois o usuário deve inserir no mínimo 1 filme

    // Leitura do nome
    printf("Entre com seu nome: ");
    getchar(); // Consumir o caractere de nova linha pendente no buffer
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' do final da string

    // Leitura do número USP
    printf("Entre com seu numero USP: ");
    scanf("%d", &nusp); // Lê o número USP (ID)
    while (getchar() != '\n'); // Limpar o buffer de entrada antes de usar fgets no loop
    printf("\n");

    Cadastrar(arvore, nome, nusp, &flag); // Cadastra o nome e o nusp do usuário, sem os filmes
    if(flag == 1)
        return;

    while(1) {
        printf("Digite 'sair' para finalizar\n");
        printf("Entre com seus filmes favoritos: ");

        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = '\0'; // Remove o '\n' do final da string 

        // Verificação do caso 'sair'
        if (strcmp(titulo, "sair") == 0) {
            if (contador >= 1) {
                // Permite sair se ao menos um filme foi inserido
                break;
            } else {
                printf("Insira ao menos um filme antes de sair!\n\n");
                continue;
            }
        }

        // Insere o filme na lista geral e na lista do usuário
        CadastrarFilme(filmes, titulo);
        InserirFilmeUsuario(arvore, filmes, nusp, titulo, &contador);
        
    }
    printf("Usuario '%s' cadastrado com sucesso!\n", nome);
    printf("Voce cadastrou estes %d filmes:\n", contador);
    ImprimirFilmesUsuario(arvore, nusp);

}

// Função que mostra todos os usuários cadastrados
void ListarUsuarios(Arvore *arvore, ListaFilmes *filmes){
    ImprimirUsuarios(arvore);
}

//Função que busca um usuário específico 
void BuscaUsuario(Arvore *arvore, ListaFilmes *filmes){
    int nusp;
    printf("Insira o numero USP do usuario a buscar: ");
    scanf("%d", &nusp);
    EstaNaArvore(arvore, nusp);
}

// Função que mostra todos os filmes cadastrados
void ListarFilmes(Arvore *arvore, ListaFilmes *filmes){

}

// Função que busca um filme específico
void BuscaFilme(Arvore *arvore, ListaFilmes *filmes){

}

// Função que gera um .txt com as informações necessárias
void ProduzirArquivo(Arvore *arvore, ListaFilmes *filmes){

}

// Função que mostra os dados tecnicos da árvore
void DadosTecnicos(Arvore *arvore, ListaFilmes *filmes){

}

// Função que remove um usuário da árvore 
void RemoverCadastro(Arvore *arvore, ListaFilmes *filmes){

}






