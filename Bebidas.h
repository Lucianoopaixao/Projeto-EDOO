#ifndef BEBIDAS_H
#define BEBIDAS_H

//Classe filha de Produto, voltada para as bebidas

#include "Produto.h"
#include <iostream>
#include <string>
using namespace std;

class Bebidas : public Produto { //Bebida tambem é subclasse de produto, então pode acessar a classe produto (no caso está acessando o que foi definido como public em produto.h).
public:
    Bebidas(const string& n = "", double p = 0) : Produto(n, p, "Bebida") {} //Em produto.h, todo objeto tem nome, preco e categoria, aqui estamos dizendo que a categoria é bebidas.

    void mostrar() const override { //Essa função vai ser a q substitue a virtual que esta em produto.h.
        cout  << nome << " (R$" << preco << ")" << endl;
    }
};

#endif
