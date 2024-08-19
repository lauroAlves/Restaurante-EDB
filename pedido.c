#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

// Função para adicionar um pedido à lista de pedidos
void adicionar_pedido(Pedido **pedidos, const char *nome) {
    // Aloca memória para um novo pedido
    Pedido *novo_pedido = (Pedido *)malloc(sizeof(Pedido));
    if (novo_pedido == NULL) {
        // Se a alocação falhar, exibe uma mensagem de erro e encerra o programa
        fprintf(stderr, "Erro ao alocar memória para novo pedido.\n");
        exit(1);
    }

    // Copia o nome do pedido para a estrutura do novo pedido
    // Usa strncpy para evitar buffer overflow e garantir que a string esteja terminada em '\0'
    strncpy(novo_pedido->nome, nome, MAX_NOME_PRATO);
    novo_pedido->nome[MAX_NOME_PRATO - 1] = '\0'; // Assegura que o nome é uma string terminada em '\0'

    // Insere o novo pedido no início da lista de pedidos
    novo_pedido->proximo = *pedidos;
    *pedidos = novo_pedido;
}

// Função para listar todos os pedidos pendentes
void listar_pedidos_pendentes(Pedido *pedidos) {
    Pedido *current = pedidos;

    // Percorre a lista de pedidos e imprime o nome de cada pedido
    while (current != NULL) {
        printf("%s\n", current->nome);
        current = current->proximo;
    }
}
