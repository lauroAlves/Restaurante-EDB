#ifndef PEDIDO_H
#define PEDIDO_H

// Define o tamanho máximo do nome de um prato
#define MAX_NOME_PRATO 100

// Estrutura para representar um pedido
typedef struct Pedido {
    char nome[MAX_NOME_PRATO];       // Nome do prato do pedido
    struct Pedido *proximo;          // Ponteiro para o próximo pedido na lista
} Pedido;

// Funções para manipulação dos pedidos
// Adiciona um novo pedido à lista de pedidos
void adicionar_pedido(Pedido **pedidos, const char *nome);

// Lista todos os pedidos pendentes
void listar_pedidos_pendentes(Pedido *pedidos);

#endif // PEDIDO_H
