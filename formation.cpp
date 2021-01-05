#include "formation.h"

formation::formation()
{
    CODE=0;
    nom="";
    domaine="";
    departement="";
}


formation::formation(int CODE,QString nom,QString domaine,QString departement)
{
  this->CODE=CODE;
  this->nom=nom;
  this->domaine=domaine;
  this->departement=departement;
}
    QString formation::get_nom(){return  nom;}
    QString formation::get_domaine() {return domaine;}
     QString formation::get_departement() {return departement;}
    int formation ::get_CODE(){return  CODE;}


bool formation::ajouter()
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

QSqlQueryModel * formation::afficher0()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}

QSqlQueryModel * formation::afficher_f_code()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation ORDER BY Nom desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}

QSqlQueryModel * formation::afficher2()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation ORDER BY Nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}
QSqlQueryModel * formation::afficher3()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation ORDER BY Domaine");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}
QSqlQueryModel * formation::afficher4()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from formation ORDER BY Departement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement"));



    return model;

}



bool formation::supprimer(int CODE)
{
QSqlQuery query;
QString res= QString::number(CODE);
query.prepare("Delete from formation where CODE= :CODE");
query.bindValue(":CODE", res);
return    query.exec();
}

bool formation::modifier(int CODE,QString nom,QString domaine,QString departement)
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
QSqlQueryModel * formation :: rechercher(QString ch)
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
