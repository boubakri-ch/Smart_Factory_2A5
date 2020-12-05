#ifndef RECHERCHE_CLIENT_H
#define RECHERCHE_CLIENT_H
#include "client.h"
#include <QDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

#include <QDialog>

namespace Ui {
class recherche_client;
}

class recherche_client : public QDialog
{
    Q_OBJECT

public:
    explicit recherche_client(QWidget *parent = nullptr);
    ~recherche_client();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pdf_2_clicked();


private:
    Ui::recherche_client *ui;
    Client tmpclient;
};

#endif // RECHERCHE_CLIENT_H
