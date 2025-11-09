#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Barzinho.h"
#include "sqlite3.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow // classe MainWindow herda de QMainWindow
{
    Q_OBJECT // Macro essencial do QT
    // ativa sistema de sinais e slots (comunic. entre widgets e lógica)

public:
    explicit MainWindow(QWidget *parent = nullptr); // construtor
    ~MainWindow(); // destrutor

private slots:
    void on_pushButtonTeste_clicked();

private:
    Ui::MainWindow *ui; // o ponteiro é o objeto gerado a partir do arquivo .ui
    sqlite3 *db;
    Barzinho *b;

    void funcaotabela();
    void carregarcardapio();
    void adicionaraobanco(const QString&, double, const QString&);
};

#endif // MAINWINDOW_H
