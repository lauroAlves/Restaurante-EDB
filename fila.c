#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"
#include "fila.h"

// Função que cria uma nova fila
Fila *criar_fila() {
    // Aloca memória para uma nova estrutura de fila
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    
    // Verifica se a alocação de memória foi bem-sucedida
    if (fila == NULL) {
        return NULL; // Retorna NULL se a alocação falhar
    }

    // Inicializa a fila com início e fim apontando para NULL
    fila->inicio = NULL;
    fila->fim = NULL;

    // Retorna o ponteiro para a fila recém-criada
    return fila;
}

// Função que adiciona um pedido à fila
void adicionar_a_fila(Fila *fila, Pedido *pedido) {
    // Se a fila estiver vazia, o novo pedido será tanto o início quanto o fim da fila
    if (fila->fim == NULL) {
        fila->inicio = pedido; // O início da fila agora aponta para o novo pedido
        fila->fim = pedido;    // O fim da fila também aponta para o novo pedido
    } else {
        // Se a fila não estiver vazia, adiciona o novo pedido ao final da fila
        fila->fim->proximo = pedido; // O último pedido da fila aponta para o novo pedido
        fila->fim = pedido;          // O fim da fila agora é o novo pedido
    }
}

// Função que remove um pedido da fila
Pedido *remover_da_fila(Fila *fila) {
    // Verifica se a fila está vazia
    if (fila->inicio == NULL) {
        return NULL; // Retorna NULL se não houver pedidos na fila
    }

    // Aponta para o pedido que será removido, que é o primeiro da fila
    Pedido *pedido = fila->inicio;

    // Move o início da fila para o próximo pedido
    fila->inicio = pedido->proximo;

    // Se a fila estiver vazia após a remoção, ajusta o fim da fila para NULL
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    // Retorna o pedido removido
    return pedido;
}

// Função que lista todos os pedidos em processamento
void listar_pedidos_em_processamento(Fila *fila) {
    // Aponta para o início da fila
    Pedido *current = fila->inicio;

    // Percorre a fila até o final, imprimindo o nome de cada pedido
    while (current != NULL) {
        printf("%s\n", current->nome); // Imprime o nome do pedido
        current = current->proximo;    // Avança para o próximo pedido na fila
    }
}
