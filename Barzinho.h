#ifndef BARZINHO_H
#define BARZINHO_H

#include "Produto.h"
#include "Pedido.h"
#include "sqlite3.h"

class Barzinho {  
private:
    //o barzinho possuirá, por padrão, um cardápio e pedidos dos clientes

    Produto* cardapio[100]; //array cardapio, com itens do tipo Produto
    int qtdProdutos;

    Pedido* pedidos[100]; //array pedidos, com itens do tipo pedido.
    int qtdPedidos;

    //Banco de dados
    sqlite3* db;

public:
    Barzinho(sqlite3* bd); //Construtor que inicializa o banco de dados
    ~Barzinho();

    //funcao de adicionar produto ao cardápio, getter para os produtos desse cardápio (boa prática) e um getter pra a quantidade de itens no cardápio
    void adicionaProduto(Produto* p);  
    Produto* getProduto(int i) const;
    int getQuantidade() const;


    void adicionarpedido(Pedido* p); //adiciona pedido ao array de pedidos
    void mostrarpedidos() const; //mostrando o resumo do pedido
    void mostrarpocategoria() const; //mostrando o cardapio por categorias

    void salvarpedidobd(Pedido* p); //salvando o pedido no banco de dados
};

#endif
