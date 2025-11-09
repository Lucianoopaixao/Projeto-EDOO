#include "Cliente.h"

Cliente::Cliente(const string& n) : nome(n) {} //construtor


string Cliente::getnome() const { return nome; } // retorna o nome do cliente


Cliente::~Cliente() {} // destrutor
