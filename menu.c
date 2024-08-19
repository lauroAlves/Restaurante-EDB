#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "pedido.h"

// Função para exibir o cardápio de entradas
void exibir_entradas() {
    printf("\nEntradas:\n");
    printf("1. Sopa de Cebola\n");
    printf("2. Salada Caesar\n");
    printf("3. Bruschetta\n");
    printf("4. Carpaccio de Carne\n");
    printf("5. Camarão ao Alho\n");
}

// Função para exibir o cardápio de pratos principais
void exibir_pratos_principais() {
    printf("\nPratos Principais:\n");
    printf("1. Lasanha à Bolonhesa\n");
    printf("2. Filé Mignon com Fritas\n");
    printf("3. Frango Grelhado com Legumes\n");
    printf("4. Bacalhau à Gomes de Sá\n");
    printf("5. Risoto de Cogumelos\n");
}

// Função para exibir o cardápio de sobremesas
void exibir_sobremesas() {
    printf("\nSobremesas:\n");
    printf("1. Tiramisu\n");
    printf("2. Cheesecake de Frutas Vermelhas\n");
    printf("3. Mousse de Chocolate\n");
    printf("4. Pudim de Leite\n");
    printf("5. Sorvete de Baunilha com Calda de Morango\n");
}

// Função para exibir o menu principal
void exibir_menu_principal() {
    printf("\nMenu:\n");
    printf("1. Entradas\n");
    printf("2. Pratos Principais\n");
    printf("3. Sobremesas\n");
}

// Função para adicionar um pedido com base na categoria e item escolhido
void adicionar_pedido_menu(Pedido **pedidos_pendentes) {
    int opcao_categoria, opcao_item;
    char nome[MAX_NOME_PRATO];

    // Exibe o menu principal e solicita a categoria do pedido
    exibir_menu_principal();
    printf("\nEscolha uma categoria (Digite o número correspondente): ");
    scanf("%d", &opcao_categoria);
    getchar(); // Consumir newline

    // Exibe o cardápio da categoria escolhida e solicita o item
    switch (opcao_categoria) {
        case 1:
            exibir_entradas();
            printf("\nEscolha um item de Entradas (Digite o número correspondente): ");
            scanf("%d", &opcao_item);
            getchar(); // Consumir newline

            // Define o nome do prato com base na opção escolhida
            switch (opcao_item) {
                case 1: strncpy(nome, "Sopa de Cebola", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Salada Caesar", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Bruschetta", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Carpaccio de Carne", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Camarão ao Alho", MAX_NOME_PRATO); break;
                default: printf("Opção inválida.\n"); return;
            }
            break;

        case 2:
            exibir_pratos_principais();
            printf("\nEscolha um item de Pratos Principais (Digite o número correspondente): ");
            scanf("%d", &opcao_item);
            getchar(); // Consumir newline

            // Define o nome do prato com base na opção escolhida
            switch (opcao_item) {
                case 1: strncpy(nome, "Lasanha à Bolonhesa", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Filé Mignon com Fritas", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Frango Grelhado com Legumes", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Bacalhau à Gomes de Sá", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Risoto de Cogumelos", MAX_NOME_PRATO); break;
                default: printf("Opção inválida.\n"); return;
            }
            break;

        case 3:
            exibir_sobremesas();
            printf("\nEscolha um item de Sobremesas (Digite o número correspondente): ");
            scanf("%d", &opcao_item);
            getchar(); // Consumir newline

            // Define o nome do prato com base na opção escolhida
            switch (opcao_item) {
                case 1: strncpy(nome, "Tiramisu", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Cheesecake de Frutas Vermelhas", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Mousse de Chocolate", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Pudim de Leite", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Sorvete de Baunilha com Calda de Morango", MAX_NOME_PRATO); break;
                default: printf("Opção inválida.\n"); return;
            }
            break;

        default:
            // Mensagem de erro para categoria inválida
            printf("Categoria inválida.\n");
            return;
    }

    // Adiciona o pedido à lista de pedidos pendentes
    adicionar_pedido(pedidos_pendentes, nome);
}

// Função para remover um pedido com base na categoria e item escolhido
void remover_pedido_menu(Pedido **pedidos_pendentes) {
    int opcao_categoria, opcao_item;
    char nome[MAX_NOME_PRATO];
    int item_encontrado = 0;

    // Exibe o menu principal e solicita a categoria do pedido a ser removido
    exibir_menu_principal();
    printf("\nQual tipo de prato você deseja remover? (Digite o número correspondente): ");
    scanf("%d", &opcao_categoria);
    getchar(); // Consumir newline

    // Exibe o cardápio da categoria escolhida
    switch (opcao_categoria) {
        case 1:
            exibir_entradas();
            break;
        case 2:
            exibir_pratos_principais();
            break;
        case 3:
            exibir_sobremesas();
            break;
        default:
            // Mensagem de erro para categoria inválida
            printf("Categoria inválida.\n");
            return;
    }

    // Solicita o item a ser removido
    printf("\nEscolha um item para remover (Digite o número correspondente): ");
    scanf("%d", &opcao_item);
    getchar(); // Consumir newline

    // Define o nome do prato com base na opção escolhida
    switch (opcao_categoria) {
        case 1:
            switch (opcao_item) {
                case 1: strncpy(nome, "Sopa de Cebola", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Salada Caesar", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Bruschetta", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Carpaccio de Carne", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Camarão ao Alho", MAX_NOME_PRATO); break;
                default: printf("Item inválido.\n"); return;
            }
            break;
        case 2:
            switch (opcao_item) {
                case 1: strncpy(nome, "Lasanha à Bolonhesa", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Filé Mignon com Fritas", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Frango Grelhado com Legumes", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Bacalhau à Gomes de Sá", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Risoto de Cogumelos", MAX_NOME_PRATO); break;
                default: printf("Item inválido.\n"); return;
            }
            break;
        case 3:
            switch (opcao_item) {
                case 1: strncpy(nome, "Tiramisu", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Cheesecake de Frutas Vermelhas", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Mousse de Chocolate", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Pudim de Leite", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Sorvete de Baunilha com Calda de Morango", MAX_NOME_PRATO); break;
                default: printf("Item inválido.\n"); return;
            }
            break;
    }

    // Procura o item na lista de pedidos pendentes e remove se encontrado
    Pedido *current = *pedidos_pendentes;
    Pedido *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->nome, nome) == 0) {
            item_encontrado = 1;
            break;
        }
        prev = current;
        current = current->proximo;
    }

    if (!item_encontrado) {
        printf("Você não selecionou este prato.\n");
        return;
    }

    // Confirma a remoção do prato
    char confirmacao;
    printf("Deseja remover este prato? (s/n): ");
    scanf("%c", &confirmacao);
    getchar(); // Consumir newline

    if (confirmacao == 's' || confirmacao == 'S') {
        if (prev == NULL) {
            *pedidos_pendentes = (*pedidos_pendentes)->proximo;
        } else {
            prev->proximo = current->proximo;
        }
        free(current);
        printf("Prato removido com sucesso.\n");
    } else {
        printf("Prato não removido.\n");
    }
}
