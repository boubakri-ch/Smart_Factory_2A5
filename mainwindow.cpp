#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->tabclient->setModel(tmpclient.afficher_Client());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString Nom= ui->lineEdit_Nom->text();
    QString Prenom= ui->lineEdit_Prenom->text();
    QString Date= ui->lineEdit_Date->text();
    QString Livraison= ui->lineEdit_Livraison->text();
    QString CIN = ui->lineEdit_CIN->text();
    QString Produit= ui->lineEdit_Produit->text();

    Client c (Nom,Prenom,Date,Livraison,CIN,Produit);
    bool test=c.ajouter_Client();
    if(test)
    {
        ui->tabclient->setModel(tmpclient.afficher_Client());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Client"),
                                 QObject::tr("Client ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un Client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
    QString Prenom = ui->lineEdit_id_2->text();
    bool test=tmpclient.supprimer(Prenom);
    if(test)
    {ui->tabclient->setModel(tmpclient.afficher_Client());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Client"),
                                 QObject::tr("Client supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_Modifier_clicked()
{
    QString  CIN = ui->lineEdit_nomrech->text();
      QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select NOM, PRENOM, DATE1, LIVRAISON, PRODUIT from CLIENT where CIN='"+CIN+"'");
    QString Nom= ui->lineEdit_nomrech->text();
    QString Prenom= ui->lineEdit_prenomN->text();
    QString Livraison= ui->lineEdit_LivraisonCN->text();
    QString Date= ui->lineEdit_dateLN->text();
    QString Produit= ui->lineEdit_ProduitN->text();
    Client c(Nom,Prenom,Date,Livraison,CIN,Produit);
    bool l=c.modifier(CIN);
    if(l)
    {//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un Client"),
                                 QObject::tr("client Modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}



