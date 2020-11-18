#include "formateur.h"
#include <QDebug>

FORMATEUR::FORMATEUR()
{
    CIN=0;
    nom="";
    prenom="";
}

FORMATEUR::FORMATEUR(int CIN,QString nom,QString prenom)
{
  this->CIN=CIN;
  this->nom=nom;
  this->prenom=prenom;
}
    QString FORMATEUR::get_nom(){return  nom;}
    QString FORMATEUR::get_prenom() {return prenom;}
    int FORMATEUR ::get_CIN(){return  CIN;}


bool FORMATEUR::ajouter()
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("INSERT INTO formateur (CIN,NOM,PRENOM) "
                    "VALUES (:CIN,:nom,:prenom)");
query.bindValue(":CIN", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);

return    query.exec();
}

QSqlQueryModel * FORMATEUR::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formateur ORDER BY CIN");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prenom"));


    return model;

}

bool FORMATEUR::supprimer(int CIN)
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from formateur where CIN= :CIN");
query.bindValue(":CIN", res);
return    query.exec();
}

bool FORMATEUR::modifier(int CIN,QString nom,QString prenom)
{


     QSqlQuery query;
    QString res= QString::number(CIN);
    query.prepare("UPDATE formateur SET NOM=:nom ,Prenom=:prenom where CIN=:CIN");
    query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
     return    query.exec();
}
QSqlQueryModel * FORMATEUR :: rechercher(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from formateur where CIN like '"+ch+"%' or Nom like '"+ch+"%' or Prenom like '"+ch+"%'    ";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Prenom"));
    return model;
}

