#include "categorie.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

categorie::categorie()
{
    this->id=0;
    this->nom="";
    this->type="";
}

categorie::categorie(int id, QString nom, QString type)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
}

bool categorie::ajouter(){

    QSqlQuery query;

    query.prepare("insert into categorie (id,nom,type)"
                  "values(:id,:nom,:type)");
    QString ids=QString::number(id);
    query.bindValue(":id",ids);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);

    return query.exec();
}

QSqlQueryModel * categorie::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;
}

bool categorie::supprimer(int idd)
{
    QSqlQuery query;

    query.prepare("Delete from categorie where id=:id");
    QString idds=QString::number(idd);
    query.bindValue(":id",idds);
    return query.exec();
}

bool categorie::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE categorie set nom=:nom,type=:type WHERE id=:id");
    query1.bindValue(":id",id);
    query1.bindValue(":nom",nom);
    query1.bindValue(":type",type);

    return (query1.exec());
}

QSqlQueryModel * categorie::afficher_tri_alphabetique_categorie(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie ORDER BY nom");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}
QSqlQueryModel * categorie::afficher_tri_identifiant_categorie(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie ORDER BY id");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}

QSqlQueryModel * categorie::rechercher_dynamique(QString nom){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie where nom like '"+nom+"%' or id like '"+nom+"%' or type like '"+nom+"%' ");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}

QSqlQueryModel * categorie::afficher_tri_descendant_categorie(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie ORDER BY id DESC");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}


