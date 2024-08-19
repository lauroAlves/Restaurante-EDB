#ifndef MENU_H
#define MENU_H

#include "pedido.h"

// Declaração das funções para exibição dos menus

// Função para exibir o cardápio de entradas
void exibir_entradas();

// Função para exibir o cardápio de pratos principais
void exibir_pratos_principais();

// Função para exibir o cardápio de sobremesas
void exibir_sobremesas();

// Função para exibir o menu principal de categorias (Entradas, Pratos Principais, Sobremesas)
void exibir_menu_principal();

// Função para adicionar um pedido ao menu de pedidos pendentes
// Recebe um ponteiro para o ponteiro da lista de pedidos pendentes
void adicionar_pedido_menu(Pedido **pedidos_pendentes);

// Função para remover um pedido do menu de pedidos pendentes
// Recebe um ponteiro para o ponteiro da lista de pedidos pendentes
void remover_pedido_menu(Pedido **pedidos_pendentes);

#endif // MENU_H
