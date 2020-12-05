#ifndef RECHERCHE_ACHAT_H
#define RECHERCHE_ACHAT_H
#include "client.h"
#include <QDialog>

namespace Ui {
class Recherche_Client;
}

class Recherche_Client : public QDialog
{
    Q_OBJECT

public:
    explicit Recherche_Client(QWidget *parent = nullptr);
    ~Recherche_Client();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pdf_2_clicked();

private:
    Ui::Recherche_Client *ui;
    Client tmpachat;
};

#endif // RECHERCHE_ACHAT_H
