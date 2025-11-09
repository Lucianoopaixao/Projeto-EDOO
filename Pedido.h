#ifndef PEDIDO_H
#define PEDIDO_H

//Classe Pedido que utiliza conceitos das classes Cliente e Produto

#include "Cliente.h"
#include "Produto.h"

class Pedido {
private:
    Cliente cliente; //Inicializando um cliente pro pedido (privado, claro)
    Produto* produtos[50]; //array produtos, onde será adicionado itens do tipo produto,
    int qtd;

public:
    Pedido(const Cliente& c); //construtor 
    ~Pedido(); //destrutor


    void adicionaProduto(Produto* p); //adicionando itens ao array produto
    void mostrarpedido() const; //resumo dos itens do pedido

    //getters  pra utilizar no banco de dados

    Produto* const* getProdutos() const { return produtos;}
    int getQtd() const { return qtd;}
    const Cliente& getCliente() const { return cliente;}
};


#endif
