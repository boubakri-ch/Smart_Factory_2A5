#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include "produit.h"
#include <QMessageBox>
#include <QTabWidget>
#include <QString>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempEtudiant.afficher());
    ui->tableView_3->setModel(tempProduit.afficherp());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Ajouter_clicked()
{
    int ide=ui->lineEdit_ID->text().toInt();
    QString nome=ui->lineEdit_Nom->text();
    QString prenome=ui->lineEdit_Prnom->text();
    etudiant e(ide,nome,prenome);
    bool test=e.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempEtudiant.afficher());
        ui->lineEdit_ID->clear();
        ui->lineEdit_Nom->clear();
        ui->lineEdit_Prnom->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_Supprimer_clicked()
{
    int ide=ui->lineEdit_ID_Suppr->text().toInt();
    bool test=tempEtudiant.supprimer(ide);
    if(test){
        QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempEtudiant.afficher());
        ui->lineEdit_ID_Suppr->clear();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifier_clicked()
{
    tempEtudiant.setID(ui->lineEdit_I_MOD->text().toInt());
    tempEtudiant.setNOM(ui->lineEdit_N_MOD->text());
    tempEtudiant.setPrenom(ui->lineEdit_P_MOD->text());

    if(tempEtudiant.modifier())
    {
        QMessageBox::information(nullptr, QObject::tr("modification etudiant"),
                                 QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempEtudiant.afficher());
        ui->lineEdit_I_MOD->clear();
        ui->lineEdit_N_MOD->clear();
        ui->lineEdit_P_MOD->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification etudiant"),
                                 QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_trier_clicked()
{
     ui->tableView->setModel(tempEtudiant.afficher_tri_alphabetique());
}

void MainWindow::on_pushButton_rechercher_clicked()
{


        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery query1;
        int ide=ui->lineEdit_ID_rech->text().toInt();
        query1.prepare("select * from etudiant where id=:id");
        QString idds=QString::number(ide);
        query1.bindValue(":id",idds);
        query1.exec();
        model->setQuery(query1);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
        ui->tableView_2->setModel(model);
        ui->lineEdit_ID_rech->clear();

}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(tempEtudiant.afficher_tri_identifiant());
}

void MainWindow::on_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    QString  title ="categorie";
    QString  title1 ="slim";
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->rowCount();

    /*for(int column = 0; column < columnCount ; column++)
     if(!ui->tableView->isColumnHidden(column))
         out <<QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());*/
    for(int row = 0; row < rowCount ; row++)
    {
        for(int column = 0; column < rowCount ; column++)
        {
            if(!ui->tableView->isColumnHidden(column))
            {
                QString data =ui->tableView->model()->data(ui->tableView->model()->index(row,column)).toString().simplified();
                out <<QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                out<<QString("\n");
            }
        }
    }

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf");}
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QTextDocument doc;
    doc.setHtml(document->toPlainText());
    doc.print(&printer);


}

void MainWindow::on_print_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();
    for(int column = 0;column < columnCount; column++)
        if(!ui->tableView->isColumnHidden(column))
            out <<QString("<td>%1</td>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
    for(int row = 0;row < rowCount; row++)
    {
        out <<"<tr>";
        for(int column = 0 ;column < columnCount ; column++)
        {
            if(!ui->tableView->isColumnHidden(column))
            {
                QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
    }
    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);
    QPrinter printer;
    QPrintDialog *daddy = new QPrintDialog(&printer , NULL);
    if(daddy->exec() == QDialog::Accepted){
        document->print(&printer);
    }
    delete document;

}

void MainWindow::on_pushButton_apply_clicked()
{

}

void MainWindow::on_pushButton_Ajout_P_clicked()
{
    int idp=ui->lineEdit_IDP->text().toInt();
    QString nomp=ui->lineEdit_NOMP->text();
    int quantity=ui->lineEdit_QP->text().toInt();
     int prix=ui->lineEdit_PP->text().toInt();

    produit p(idp,nomp,quantity,prix);
    bool test=p.ajouterP();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempProduit.afficherp());
        ui->lineEdit_IDP->clear();
        ui->lineEdit_NOMP->clear();
        ui->lineEdit_QP->clear();
        ui->lineEdit_PP->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_afficherp_clicked()
{
    ui->tableView_3->setModel(tempProduit.afficherp());
}

void MainWindow::on_pushButton_produit_mod_clicked()
{
    tempProduit.setIDP(ui->lineEdit_IDP_MOD->text().toInt());
    tempProduit.setNOMP(ui->lineEdit_NP_MOD->text());
    tempProduit.setQuantity(ui->lineEdit_QP_MOD->text().toInt());
    tempProduit.setPrix(ui->lineEdit_PP_MOD->text().toInt());


    if(tempProduit.modifierp())
    {
        QMessageBox::information(nullptr, QObject::tr("modification produit"),
                                 QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempProduit.afficherp());
        ui->lineEdit_IDP_MOD->clear();
        ui->lineEdit_NP_MOD->clear();
        ui->lineEdit_QP_MOD->clear();
        ui->lineEdit_PP_MOD->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification produit"),
                                 QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_ps_clicked()
{
    int ide=ui->lineEdit_P_S->text().toInt();
    bool test=tempProduit.supprimerp(ide);
    if(test){
        QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempProduit.afficherp());
        ui->lineEdit_P_S->clear();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_P_RECHERCHE_clicked()
{
    QSqlQueryModel * model1 = new QSqlQueryModel();
    QSqlQuery query1;
    int ide=ui->lineEdit_P_R->text().toInt();
    query1.prepare("select * from produit where idp=:idp");
    QString idds=QString::number(ide);
    query1.bindValue(":idp",ide);
    query1.exec();
    model1->setQuery(query1);
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    ui->tableView_4->setModel(model1);
    ui->lineEdit_P_R->clear();
}
