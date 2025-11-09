#include "Pedido.h"
#include <iostream>
using namespace std;

Pedido::Pedido(const Cliente& c) //construtor de pedido
    : cliente(c), qtd(0) 
{}

Pedido::~Pedido() {} //destrutor de pedido (vazio)



void Pedido::adicionaProduto(Produto* p) { 
    if (qtd < 50) { //limite de 50
        produtos[qtd++] = p;
    } else {
        cout << "Limite de produtos no pedido atingido!" << endl;
    }
}

void Pedido::mostrarpedido() const {
    cout << "Cliente: " << cliente.getnome() << endl;
    cout << "Itens do pedido:" << endl;

    bool gerenciamentop[50]; //array criado pra gerenciar itens ja adicionados

    for(int i=0;i<qtd;i++){
        gerenciamentop[i]= false ;//inicializando todos os itens como false pra checar depois se ja foi adicionado
    }


    double total = 0; //total inicializdo

    for(int i=0; i<qtd; i++){
        if (gerenciamentop[i]==false){ //se ainda nao foi implementado no pedido
            int contador = 1 ; //contador de quantas vezes o item apareceu(inicia em 1)
            double preco =produtos[i]->getpreco();

        

            //botando true nos outros itens iguais do array
            for(int h= i +1; h<qtd ; h++){
                if(gerenciamentop[h]==false && produtos[h]->getnome()==produtos[i]->getnome()){//ou seja, so entra na condicao se ainda nao tiver virado true e o nome for igual
                    contador=contador+1; //incrementando contadpr
                    gerenciamentop[h]=true; //vira true!
            }
        }

        double totalporitem= contador*preco;//calculando o total(qtd de itens repetidos * seu preco)
        total= total + totalporitem;// add no total

        cout<< contador<< "x "<< produtos[i]->getnome()<< " - R$"<< totalporitem<< endl;
    }


    }

    cout << "Total: R$" << total << endl;
}
