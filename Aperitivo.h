#ifndef APERITIVO_H
#define APERITIVO_H

//Classe filha de Produto, voltada para os aperitivos.
#include "Produto.h"
#include <iostream>
#include <string>
using namespace std;

class Aperitivo : public Produto { // Aperitivo é uma subclasse de produto (herança).
public:
    Aperitivo(const string& n, double p) : Produto(n, p, "Aperitivo") {} 

    void mostrar() const override { // O override foi utilizado para fazer polimorfismo, essa versao substitui o virtual la em produto.h.
        cout << nome << " (R$" << preco << ")" << endl; // Isso é o que aparece quando a função mostrar() é chamada  por um ponteiro ou referencia q aponta para aperitivo.
    }
};

#endif
