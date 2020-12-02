#include "formation.h"
#include <QDebug>

FORMATION::FORMATION()
{
    CODE=0;
    nom="";
    domaine="";

}

FORMATION::FORMATION(int CODE,QString nom,QString domaine,QString departement)
{
  this->CODE=CODE;
  this->nom=nom;
  this->domaine=domaine;
  this->departement=departement;
}
    QString FORMATION::get_nom(){return  nom;}
    QString FORMATION::get_domaine() {return domaine;}
     QString FORMATION::get_departement() {return departement;}
    int FORMATION ::get_CODE(){return  CODE;}


bool FORMATION::ajouter()
{
QSqlQuery query;
QString res= QString::number(CODE);
query.prepare("INSERT INTO formation (CODE,NOM,DOMAINE,DEPARTEMENT) "
                    "VALUES (:CODE,:nom,:domaine,:departement)");
query.bindValue(":CODE", res);
query.bindValue(":nom", nom);
query.bindValue(":domaine", domaine);
query.bindValue(":departement", departement);

return    query.exec();
}

QSqlQueryModel * FORMATION::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation ORDER BY CODE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}

QSqlQueryModel * FORMATION::afficher2()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation ORDER BY Nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}
QSqlQueryModel * FORMATION::afficher3()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation ORDER BY Domaine");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}
QSqlQueryModel * FORMATION::afficher4()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation ORDER BY Departement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}



bool FORMATION::supprimer(int CODE)
{
QSqlQuery query;
QString res= QString::number(CODE);
query.prepare("Delete from formation where CODE= :CODE");
query.bindValue(":CODE", res);
return    query.exec();
}

bool FORMATION::modifier(int CODE,QString nom,QString domaine,QString departement)
{


     QSqlQuery query;
    QString res= QString::number(CODE);
    query.prepare("UPDATE formation SET NOM=:nom ,DOMAINE=:domaine,DEPARTEMENT=:departement where CODE=:CODE");
    query.bindValue(":CODE", res);
    query.bindValue(":nom", nom);
    query.bindValue(":domaine", domaine);
    query.bindValue(":departement", departement);
     return    query.exec();
}
QSqlQueryModel * FORMATION :: rechercher(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from formation where CODE like '"+ch+"%'  or Nom like '"+ch+"%' or Domaine like '"+ch+"%' or Departement like '"+ch+"%'";

    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));

    return model;
}
