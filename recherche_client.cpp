#include "recherche_client.h"
#include "ui_recherche_client.h"
#include <QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include"QDate"
#include "connection.h"
#include "client.h"

recherche_client::recherche_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recherche_client)
{
    ui->setupUi(this);
    ui->tabclient->setModel(tmpclient.afficher_Client());
}

recherche_client::~recherche_client()
{
    delete ui;
}
void recherche_client::on_pushButton_clicked()
{
    QString id = ui->lineEdit_rechachat->text();

        ui->tabclient->setModel(tmpclient.recherche_Clienta(id));
}

void recherche_client::on_pushButton_2_clicked()
{
    QString id = ui->lineEdit_rechachat->text();

        ui->tabclient->setModel(tmpclient.recherche_Clientd(id));
}

void recherche_client::on_pdf_2_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabclient->model()->rowCount();
        const int columnCount = ui->tabclient->model()->columnCount();
        QString TT = QDate::currentDate().toString("yyyy/MM/dd");
        out <<"<html>\n"
              "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            << "<title>ERP - COMmANDE LIST<title>\n "
            << "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Factures ****** "+TT+"</strong></h1>"
            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
              "</br> </br>";
        // headers
        out << "<thead><tr bgcolor=#d6e5ff>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabclient->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabclient->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabclient->isColumnHidden(column)) {
                    QString data =ui->tabclient->model()->data(ui->tabclient->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *baba = new QPrintDialog(&printer, NULL);
        if (baba->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;
}
