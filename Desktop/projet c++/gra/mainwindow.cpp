#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fournisseur.h"
#include"produit.h"
#include <QMessageBox>
#include<QDate>
#include<QDateTime>
#include<QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_four->setModel(tab_four.afficher());
    ui->tab_pro->setModel(tab_pro.afficher());




}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->id->text().toInt();
     QString nom=ui->nom_fournisseur_2->text();
     QString prenom=ui->prenom_fournisseur->text();
     QString Num=ui->Num_fournisseur->text();
      QString RIB=ui->RIB_fournisseur->text();
     FOURNISSEUR F(nom,prenom,id,Num,RIB);
     bool test=F.ajouter();


     if(test)
     {
 ui->table_four->setModel(tab_four.afficher());
         QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                                QObject::tr("fournisseur ajoutée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }
     QSqlQueryModel *model= new QSqlQueryModel();
     QSqlQuery *query=new QSqlQuery();
     query->prepare("select ID_FOURNISSEUR from fournisseur");
     query->exec();
     model->setQuery(*query);
     ui->list_fournisseur->setModel(model);
      ui->list_fournisseur_2->setModel(model);
}



void MainWindow::on_pushButton_clicked()
{
    QString id=ui->id_sup->text();
    bool test=tab_four.supprimer(id);
    if(test)
    {
        ui->table_four->setModel(tab_four.afficher());
                QMessageBox::information(nullptr, QObject::tr("suprrimer un fournisseur"),
                                       QObject::tr("fournisseur supprimer.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->id_modifier->text().toInt();
    QString nom=ui->nom_modifier->text();
     QString prenom=ui->prenom_modifier->text();
    QString RIB=ui->RIB_modifier->text();
     QString Num=ui->Num_modifier->text();
     FOURNISSEUR F(nom,prenom,id,Num,RIB);
     bool test=F.modifier();
     if(test)
     {
 ui->table_four->setModel(tab_four.afficher());
         QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                                QObject::tr("fournisseur modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }
}

void MainWindow::on_pushButton_4_clicked()
{

    QString id=ui->id_4->text();
    bool test=tab_pro.supprimer(id);
    if(test)
    {
        ui->tab_pro->setModel(tab_pro.afficher());
                QMessageBox::information(nullptr, QObject::tr("suprrimer un produit"),
                                       QObject::tr("produit supprimer.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_6_clicked()
{

    int id=ui->id_ajouter->text().toInt();
     int id_f=ui->list_fournisseur->currentText().toInt();
    QString quantiter=ui->quantiter_ajouter->text();
    QString nom=ui->nom_ajouter->text();
     QString date=ui->date_ajouter->date().toString("dd-MM-yyyy");
     PRODUIT P(nom,date,quantiter,id,id_f);
     bool test=P.ajouter();
     if(test)
     {
 ui->tab_pro->setModel(tab_pro.afficher());
         QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                                QObject::tr("produit ajoutée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }


}

void MainWindow::on_pushButton_5_clicked()
{

    int id=ui->id_modifier_2->text().toInt();
int id_f=ui->list_fournisseur_2->currentText().toInt();
      QString date=ui->date_modifier_2->text();
    QString nom=ui->nom_modifier_2->text();
     QString quantiter=ui->quantiter_modifier->text();
     PRODUIT P(nom,date,quantiter,id,id_f);
     bool test=P.modifier();
     if(test)
     {
 ui->tab_pro->setModel(tab_pro.afficher());
         QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                                QObject::tr("produit modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }

}

void MainWindow::on_pushButton_7_clicked()
{
      ui->table_four->setModel(tab_four.affichertri());
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query1;
    int ide=ui->lineEdit_r_f->text().toInt();
    query1.prepare("select * from FOURNISSEUR where id_fournisseur=:id");
    QString idds=QString::number(ide);
    query1.bindValue(":id",idds);
    query1.exec();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FOURNISSEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Num_tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("RIB"));
    ui->table_four->setModel(model);
    ui->lineEdit_r_f->clear();
}
