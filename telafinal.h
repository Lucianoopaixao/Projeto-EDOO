#ifndef TELAFINAL_H
#define TELAFINAL_H

#include <QWidget>
#include <QMessageBox>
#include "sqlite3.h"
#include "Pedido.h"

namespace Ui {
class TelaFinal;
}
// Tela que mostra o resumo do pedido: itens, quantidade e valo
class TelaFinal : public QWidget
{
    Q_OBJECT

public://recebe ponteiro do banco e pedido atual
    explicit TelaFinal(QWidget *parent = nullptr, sqlite3* db = nullptr, Pedido* pedido = nullptr);
    ~TelaFinal();

private slots:
    void on_btnVoltar_clicked();//volta para o cardapio
    void on_btnFecharPedido_clicked();//fecha o programa

private:
    Ui::TelaFinal *ui;//interface
    sqlite3* db;  // ponteiro pro banco já aberto
    Pedido* pedidoAtual;//pedido do cliente
    void carregarTabela();// preenche a tabela com os itens e calcula o total
};

#endif // TELAFINAL_H
