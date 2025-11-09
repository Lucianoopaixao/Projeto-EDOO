#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Aperitivo.h"
#include "Barzinho.h"
#include "Bebidas.h"
#include "telacardapio.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
    // alocando memória para o objeto que representa sua interface visual
{
    ui->setupUi(this); // carrega o layout e os widgets definidos em .ui

    if (sqlite3_open("barzinho.db", &db)) {
        QMessageBox::critical(this, "erro", QString("falha ao abrir banco %1").arg(sqlite3_errmsg(db)));
        return;
    }

    sqlite3_exec(db, "PRAGMA journal_mode=WAL;", nullptr, nullptr, nullptr); // permite leituras e escritas simultâneas
    // Abrindo o banco de dados "barzinho.db".
    // Se não conseguir, mostra uma mensagem de erro e para por aqui.
    this->db = db;
    funcaotabela();
    b = new Barzinho(db);
    carregarcardapio();
}

MainWindow::~MainWindow()
{
    if (db) sqlite3_close(db); //fecha o banco de dados se ele estiver aberto
    delete ui;  // Libera a memória usada pela interface
}

void MainWindow::on_pushButtonTeste_clicked() {

    QString nomeCliente = ui->lineEditNome->text();//pega o nome do usuario
    //se não digitou nada, avisa e não deixa continuar
    if(nomeCliente.isEmpty()) {
        QMessageBox::warning(this, "Atenção", "Digite seu nome antes de continuar!");
        return;
    }

    // abrir tela do cardápio
    TelaCardapio *cardapio = new TelaCardapio(nullptr, db, nullptr, nomeCliente);
    cardapio->show();

    this->hide();

}



//cria as tabelas do banco caso ainda não existam
void MainWindow::funcaotabela() {
    const char* sql_cardapio =
        "CREATE TABLE IF NOT EXISTS cardapio("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nome TEXT,"
        "preco REAL,"
        "categoria TEXT);";

    const char* sql_pedidos=
        "CREATE TABLE IF NOT EXISTS pedidos("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "cliente TEXT,"
        "item TEXT,"
        "quantidade INTEGER,"
        "total REAL);";

    //executa os comandos no banco de dados
    char* errMSG= nullptr;
    sqlite3_exec(db,sql_cardapio,nullptr,nullptr,&errMSG);
    sqlite3_exec(db,sql_pedidos,nullptr,nullptr,&errMSG);
}
//adiciona os produtos no banco
void MainWindow::adicionaraobanco(const QString& nome, double preco, const QString& categoria) {
    QString sql = QString(
        "INSERT INTO cardapio (nome, preco, categoria)"
        "VALUES ('%1', %2, '%3')"
                      ).arg(nome).arg(preco).arg(categoria);

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.toUtf8().constData(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        qDebug() << "Erro ao inserir produto:" << errMsg;
        sqlite3_free(errMsg);
    }
}
//carrega o cardapio
void MainWindow::carregarcardapio() {

    sqlite3_stmt* stmt;
    const char* sqlCheck = "SELECT COUNT(*) FROM cardapio;";
    int count=0;
    //ver se o produto ja esta cadastrado
    if (sqlite3_prepare_v2(db, sqlCheck, -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            count = sqlite3_column_int(stmt, 0); //quantidade do produto
        }
    }

    sqlite3_finalize(stmt);

    if (count==0) {

        //criando os produtos na memória
        //aperitivos
        b->adicionaProduto(new Aperitivo("Caldinho", 8.00));
        b->adicionaProduto(new Aperitivo("Batatas Fritas", 10.00));
        b->adicionaProduto(new Aperitivo("Bolinhos de Bacalhau", 12.00));
        b->adicionaProduto(new Aperitivo("Espetinho de Frango", 15.00));
        b->adicionaProduto(new Aperitivo("Espetinho de Carne", 15.50));
        b->adicionaProduto(new Aperitivo("Espetinho de Frango com Bacon ", 16.00));

        //bebidas
        b->adicionaProduto(new Bebidas("Brahma Chopp", 6.00));  //esse new ele serve para você guardar os objetos dentro do heap e nao deixar so na pilha
        //inclusive, é por isso que temos que usar o "delete"
        b->adicionaProduto(new Bebidas("Corona Long Neck", 10.00));
        b->adicionaProduto(new Bebidas("Heineken Long Neck", 12.00));
        b->adicionaProduto(new Bebidas("Caipirinha", 8.00));
        b->adicionaProduto(new Bebidas("Sangria", 18.00));
        b->adicionaProduto(new Bebidas("Negroni", 18.00));
        b->adicionaProduto(new Bebidas("Pina Colada", 18.00));
        b->adicionaProduto(new Bebidas("Aperol", 25.00));
        b->adicionaProduto(new Bebidas("Sex on the Beach", 23.00));
        b->adicionaProduto(new Bebidas("Coca-Cola Zero", 6.00));
        b->adicionaProduto(new Bebidas("Agua", 2.00));


        //adicionando os produtos ao banco

        adicionaraobanco("Caldinho", 8.00, "aperitivo");
        adicionaraobanco("Batatas Fritas", 10.00, "aperitivo");
        adicionaraobanco("Bolinhos de Bacalhau", 12.00, "aperitivo");
        adicionaraobanco("Espetinho de Frango", 15.00, "aperitivo");
        adicionaraobanco("Espetinho de Frango com Bacon", 16.00, "aperitivo");

        adicionaraobanco("Brahma Chopp", 6.00, "bebida");
        adicionaraobanco("Corona Long Neck", 10.00, "bebida");
        adicionaraobanco("Heineken Long Neck", 12.00, "bebida");
        adicionaraobanco("Caipirinha", 8.00, "bebida");
        adicionaraobanco("Sangria", 18.00, "bebida");
        adicionaraobanco("Negroni", 18.00, "bebida");
        adicionaraobanco("Pina Colada", 18.00, "bebida");
        adicionaraobanco("Aperol", 25.00, "bebida");
        adicionaraobanco("Sex on the Beach", 23.00, "bebida");
        adicionaraobanco("Coca-Cola Zero", 6.00, "bebida");
        adicionaraobanco("Agua", 2.00, "bebida");

    }
}
