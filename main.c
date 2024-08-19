#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "pedido.h"
#include "fila.h"

int main() {
    // Inicializa a lista de pedidos pendentes como NULL
    Pedido *pedidos_pendentes = NULL;
    
    // Cria uma nova fila para processamento de pedidos
    Fila *fila_de_processamento = criar_fila();
    if (fila_de_processamento == NULL) {
        // Se a criação da fila falhar, exibe uma mensagem de erro e encerra o programa
        fprintf(stderr, "Erro ao criar a fila de processamento.\n");
        return 1;
    }

    int opcao;

    do {
        // Exibe o menu de opções para o usuário
        printf("\nMenu:\n");
        printf("1. Adicionar Pedido\n");
        printf("2. Remover Pedido\n");
        printf("3. Processar Pedido\n");
        printf("4. Listar Pedidos Pendentes\n");
        printf("5. Listar Pedidos em Processamento\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere de nova linha deixado pelo scanf

        // Executa a ação correspondente à opção escolhida pelo usuário
        switch (opcao) {
            case 1:
                // Adiciona um pedido à lista de pedidos pendentes
                adicionar_pedido_menu(&pedidos_pendentes);
                break;

            case 2:
                // Remove um pedido da lista de pedidos pendentes
                remover_pedido_menu(&pedidos_pendentes);
                break;

            case 3:
                // Processa um pedido, movendo-o da lista de pendentes para a fila de processamento
                if (pedidos_pendentes != NULL) {
                    // Remove o primeiro pedido da lista de pendentes
                    Pedido *pedido_para_processar = pedidos_pendentes;
                    pedidos_pendentes = pedidos_pendentes->proximo;
                    pedido_para_processar->proximo = NULL;
                    // Adiciona o pedido à fila de processamento
                    adicionar_a_fila(fila_de_processamento, pedido_para_processar);
                } else {
                    // Se não houver pedidos pendentes, exibe uma mensagem
                    printf("Nenhum pedido pendente para processar.\n");
                }
                break;

            case 4:
                // Lista todos os pedidos pendentes
                printf("Pedidos Pendentes:\n");
                listar_pedidos_pendentes(pedidos_pendentes);
                break;

            case 5:
                // Lista todos os pedidos em processamento na fila
                printf("Pedidos em Processamento:\n");
                listar_pedidos_em_processamento(fila_de_processamento);
                break;

            case 6:
                // Opção para sair do programa
                break;

            default:
                // Mensagem de erro para opção inválida
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 6); // Continua o loop até que o usuário escolha sair

    // Liberar memória alocada para pedidos pendentes
    while (pedidos_pendentes != NULL) {
        Pedido *temp = pedidos_pendentes;
        pedidos_pendentes = pedidos_pendentes->proximo;
        free(temp);
    }

    // Liberar memória alocada para pedidos na fila de processamento
    while (fila_de_processamento->inicio != NULL) {
        Pedido *temp = remover_da_fila(fila_de_processamento);
        free(temp);
    }

    // Liberar memória alocada para a fila de processamento
    free(fila_de_processamento);

    return 0;
}
