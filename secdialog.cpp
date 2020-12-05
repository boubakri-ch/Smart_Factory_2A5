#include "secdialog.h"
#include "ui_secdialog.h"
#include "connection.h"
#include <QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include"QDate"
#include "wwindow.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}
void SecDialog::on_pushButton_clicked()
{
    QString CIN = ui->lineEdit_rechachat->text();

        ui->tabclient->setModel(tmpclient.recherche_Clienta(CIN));
}

void SecDialog::on_pushButton_2_clicked()
{
    QString CIN = ui->lineEdit_rechachat->text();

        ui->tabclient->setModel(tmpclient.recherche_Clientd(CIN));
}

void SecDialog::on_pdf_2_clicked()
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


}
