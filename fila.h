#ifndef FILA_H
#define FILA_H

// Inclui o cabeçalho para a estrutura de Pedido, que é usada na fila
#include "pedido.h"

typedef struct Fila {
    Pedido *inicio; // Ponteiro para o primeiro pedido na fila
    Pedido *fim; // Ponteiro para o último pedido na fila
} Fila;

// Declara as funções para manipulação da fila
// Função para criar uma nova fila
// Retorna um ponteiro para a nova fila criada
Fila *criar_fila();
// Função para adicionar um pedido à fila
// Recebe um ponteiro para a fila e um ponteiro para o pedido a ser adicionado
void adicionar_a_fila(Fila *fila, Pedido *pedido);
// Função para remover um pedido da fila
// Recebe um ponteiro para a fila
// Retorna o ponteiro para o pedido removido ou NULL se a fila estiver vazia
Pedido *remover_da_fila(Fila *fila);
// Função para listar todos os pedidos em processamento
// Recebe um ponteiro para a fila e imprime os nomes dos pedidos
void listar_pedidos_em_processamento(Fila *fila);


#endif // FILA_H
