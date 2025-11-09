#include "Barzinho.h"
#include <iostream>
#include "Bebidas.h"
#include "Aperitivo.h"
#include "sqlite3.h"
using namespace std;

Barzinho::Barzinho(sqlite3* bd) : qtdProdutos(0), qtdPedidos(0), db(nullptr) {
    if(sqlite3_open("barzinho.db",&db)){
        cout<<"Deu merda: "<< sqlite3_errmsg(db)<<endl;
        db=nullptr;
    }
} //Construtor, que cria um barzinho e tenta abrir o banco de daods

Barzinho::~Barzinho() { // destrutor
    for (int i = 0; i < qtdProdutos; i++) // quando o destrutor é chamado tanto os objetos de cardapio quanto os pedidos sao deletados 
        delete cardapio[i];
    for (int i = 0; i < qtdPedidos; i++)
        delete pedidos[i];

    if(db) sqlite3_close(db);
}

Produto* Barzinho::getProduto(int i) const { //retorna o ponteiro para o produto da posição i do cardapio 
    return cardapio[i]; 
}

void Barzinho::adicionaProduto(Produto* p) {  //adiciona um produto ao cardapio
    if (qtdProdutos < 100)
        cardapio[qtdProdutos++] = p;
}

int Barzinho::getQuantidade() const {  //retorna a quantidade de produtos cadastrados
    return qtdProdutos;
}

void Barzinho::adicionarpedido(Pedido* p) { //quando um pedido é finalizado ele é guardado em pedidos
    if (qtdPedidos < 100)
        pedidos[qtdPedidos++] = p;
}

void Barzinho::mostrarpedidos() const { //mostra todos os pedidos guardados
    for (int i = 0; i < qtdPedidos; i++) {
        pedidos[i]->mostrarpedido(); //para cada pedido, ele aponta para a função mostrar pedido declarada em pedido.cpp
        cout << "=============================" << endl;
    }
}

void Barzinho:: salvarpedidobd(Pedido* p){ //logica quase igual a de pedido cpp, salva todo pedido no banco de dados
    int qtdpropedidos=p->getQtd();
    bool gerenciamentop[50];

    for (int i=0; i<qtdpropedidos; i++) { //inicializando tudo como false
        gerenciamentop[i]=false;
    }

    for (int i=0;i<qtdpropedidos;i++){
        if(gerenciamentop[i]==false){ //Começando a analizar os itens do pedido com o contador em 1
            int contador=1;
            double preco=p->getProdutos()[i]->getpreco();

            for (int j=i+1;j<qtdpropedidos;j++){ //Finalmente, checando a quantidade de cada item para adicionar corretamente no banco de dados
                if(gerenciamentop[j]==false && p->getProdutos()[j]->getnome() == p->getProdutos()[i]->getnome()){
                    contador++;
                    gerenciamentop[j]=true;
                }
            }

        double totalporitem=contador*preco;

        //agora, add ao bd
        string sql= "INSERT INTO pedidos (cliente,item,quantidade,total) VALUES ('" +
                    p->getCliente().getnome() + "', '"+
                    p->getProdutos()[i]->getnome() + "', "+
                    to_string(contador) + ", " +
                    to_string(totalporitem) + ");";
        char* errMsg = nullptr;
        int errobanco= sqlite3_exec(db,sql.c_str(), nullptr,nullptr,&errMsg);
        if(errobanco!=SQLITE_OK){
            cout<< "Nao adicionou no banco: "<< errMsg<<endl;
            sqlite3_free(errMsg);
        }
    }
    }
}

void Barzinho::mostrarpocategoria() const { //mostrando tudo em categorias

    cout<<"===Menu do Barzinho==="<<endl; 

    cout<<endl;

    cout<<"===Aperitivos==="<<endl; //começando com aperetivos
    for(int i=0;i<qtdProdutos;i++){
        if(dynamic_cast<Aperitivo*>(cardapio[i])){ //o dynamic cast serve pra averiguar se o tipo do produto é aperitivo
            cout<< i+1<< "-";
            cardapio[i]->mostrar();
        }
    }
    

    cout<<endl;
    
    cout<<"===Bebidas==="<<endl; //agora bebidas
    for(int i=0;i<qtdProdutos;i++){
        if(dynamic_cast<Bebidas*>(cardapio[i])){ //o dynamic cast serve pra averiguar se o tipo do produto é bebidas
            cout<< i+1<< "-";
            cardapio[i]->mostrar();
        }
    }

    cout<<"\n====================================";
}

