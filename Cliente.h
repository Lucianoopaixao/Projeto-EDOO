#ifndef CLIENTE_H
#define CLIENTE_H

//Classe do cliente de nosso barzinho.

#include <string>
using namespace std;

class Cliente {
private: 
    //Como uma boa prática, o nome do cliente deve ser privado.
    string nome;

public:
    //Construtor, getter e destrutor, respectivamente.
    Cliente(const string& n = "");
    string getnome() const;
    ~Cliente();
};

#endif
