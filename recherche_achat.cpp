#include "recherche_achat.h"
#include "ui_recherche_achat.h"
#include <QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include"QDate"
#include <QDialog>
#include "client.h"

Recherche_Client::Recherche_Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recherche_client)
{
    ui->setupUi(this);
}

Recherche_Client::~Recherche_Client()
{
    delete ui;
}
void Recherche_Achat::on_pushButton_clicked()
{
    QString id = ui->lineEdit_rechachat->text();

        ui->tabachat->setModel(tmpachat.recherche_achata(id));
}

void Recherche_Achat::on_pushButton_2_clicked()
{
    QString id = ui->lineEdit_rechachat->text();

        ui->tabachat->setModel(tmpachat.recherche_achatd(id));
}

void Recherche_Achat::on_pdf_2_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabachat->model()->rowCount();
        const int columnCount = ui->tabachat->model()->columnCount();
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
            if (!ui->tabachat->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabachat->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabachat->isColumnHidden(column)) {
                    QString data =ui->tabachat->model()->data(ui->tabachat->model()->index(row, column)).toString().simplified();
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
