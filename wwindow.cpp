#include "wwindow.h"
#include "ui_wwindow.h"
#include <QDebug>
#include "client.h"
#include <QMessageBox>
#include "connection.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include "gestion_coli_courrier.h"




WWindow::WWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WWindow)
{
    ui->setupUi(this);
}

WWindow::~WWindow()
{
    delete ui;
}



void WWindow::on_pb_supprimer_2_clicked()
{
    QString Prenom = ui->lineEdit_id_3->text();
    bool test=tmpclient.supprimer(Prenom);
    if(test)
    {ui->tabclient_2->setModel(tmpclient.afficher_Client());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Client"),
                                 QObject::tr("Client supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void WWindow::on_pb_Modifier_2_clicked()
{
    QString  CIN = ui->lineEdit_nomrech_2->text();
          QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select NOM, PRENOM, DATE1, LIVRAISON, CIN, PRODUIT from CLIENT where CIN='"+CIN+"'");
        QString Nom= ui->lineEdit_nomrech_2->text();
        QString Prenom= ui->lineEdit_prenomN_2->text();
        QString Livraison= ui->lineEdit_LivraisonCN_2->text();
        QString Date= ui->lineEdit_dateLN_2->text();
        QString Produit= ui->lineEdit_ProduitN_2->text();
        Client c(Nom,Prenom,Date,Livraison,CIN,Produit);
        bool l=c.modifier(CIN);
        if(l)
        {//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un Client"),
                                     QObject::tr("client Modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un Client"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void WWindow::on_pushButton_clicked()
{
    QString Nom= ui->lineEdit_Nom_2->text();
    QString Prenom= ui->lineEdit_Prenom_2->text();
    QString Date= ui->lineEdit_Date_2->text();
    QString Livraison= ui->lineEdit_Livraison_2->text();
    QString CIN = ui->lineEdit_CIN_2->text();
    QString Produit= ui->lineEdit_Produit_2->text();

    Client c (Nom,Prenom,Date,Livraison,CIN,Produit);
    bool test=c.ajouter_Client();
    if(test)
    {
        ui->tabclient_2->setModel(tmpclient.afficher_Client());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Client"),
                                 QObject::tr("Client ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un Client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);



}







void WWindow::on_pushButton_4_clicked()
{
hide();
Gestion_coli_courrier =new Gestion_Coli_Courrier(this);
Gestion_coli_courrier->show();

}
