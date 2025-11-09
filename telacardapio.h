#ifndef TELACARDAPIO_H
#define TELACARDAPIO_H
#include "Produto.h"
#include <QMainWindow>
#include "sqlite3.h"
#include "Pedido.h"


namespace Ui {
class TelaCardapio;
}
//representa a tela de cardápio do barzinho
class TelaCardapio : public QWidget
{
    Q_OBJECT

public: //controi a tela
    explicit TelaCardapio(QWidget *parent = nullptr, sqlite3* banco = nullptr, Pedido* pedidoExistente = nullptr, const QString& nomeClienteSalvo = "");
    ~TelaCardapio();
    //define o nome do cliente e atualiza o label "boas-vindas"
    void setNomeCliente(const QString &nome);

private slots:
    void on_botaoAdicionar_clicked();//botão adicionar
    void on_botaoFinalizar_clicked();//botão finalizar

private:
    Ui::TelaCardapio *ui; //ponteiro para a interface gerada
    sqlite3* db; //ponteiro para o banco de dados
    QString nomeCliente; //nome do cliente
    Pedido* pedidoAtual; //ponteiro para pedido atual

    void carregarCardapio();//carrega os produtos do banco de dados e preenche as tabelas bebidas e aperitivos
    void salvarPedidonoBanco(Pedido* pedido);
};

#endif // TELACARDAPIO_H
