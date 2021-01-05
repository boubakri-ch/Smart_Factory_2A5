#include "coli.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

coli::coli()
{
    this->idcoli=0;
    this->adresse_d="";
    this->type="";
    this->poids=0;
    this->prix=0;
    this->cinclient=0;
}

coli::coli(int idcoli, QString adresse_d,QString type, int poids,int prix,int cinclient){

    this->idcoli=idcoli;
    this->adresse_d=adresse_d;
    this->type=type;
    this->poids=poids;
    this->prix=prix;
    this->cinclient=cinclient;
}

bool coli::ajouterP(){

    QSqlQuery query;

    query.prepare("insert into coli (idcoli,adresse_d,type,poids,prix,cinclient)"
                  "values(:idcoli,:adresse_d,:type,:poids,:prix,:cinclient)");
    QString ids=QString::number(idcoli);
    QString poid=QString::number(poids);
    QString price=QString::number(prix);
    QString cclient=QString::number(cinclient);

    query.bindValue(":idcoli",ids);
    query.bindValue(":adresse_d",adresse_d);
    query.bindValue(":type",type);
    query.bindValue(":poids",poid);
    query.bindValue(":prix",price);
    query.bindValue(":cinclient",cclient);

    return query.exec();
}

QSqlQueryModel * coli::afficherp(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from coli");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Idcoli"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_d"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
    query->setHeaderData(5,Qt::Horizontal,QObject::tr("cinclient"));
    return query;
}

bool coli::supprimerp(int idp)
{
    QSqlQuery query;

    query.prepare("Delete from coli where idcoli=:idp");
    QString idds=QString::number(idp);
    query.bindValue(":idp",idds);
    return query.exec();
}

bool coli::modifierp(){
    QSqlQuery query1;
    query1.prepare("UPDATE coli set adresse_d=:adresse_d,type=:type,poids=:poids,prix=:prix,cinclient=:cinclient WHERE idcoli=:idcoli");
    query1.bindValue(":idcoli",idcoli);
    query1.bindValue(":adresse_d",adresse_d);
    query1.bindValue(":type",type);
    query1.bindValue(":poids",poids);
    query1.bindValue(":prix",prix);
    query1.bindValue(":cinclient",cinclient);

    return (query1.exec());
}

QSqlQueryModel * coli::rechercher_dynamique_produit(QString p){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from coli where idcoli like '"+p+"%' or adresse_d like '"+p+"%' or type like '"+p+"%' or poids like '"+p+"%' or prix like '"+p+"%' or cinclient like '"+p+"%' ");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Idcoli"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_d"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
    query->setHeaderData(5,Qt::Horizontal,QObject::tr("cinclient"));
    return query;
}

QSqlQueryModel * coli::afficherp_tri_prix(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from coli ORDER BY prix");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Idcoli"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_d"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
    query->setHeaderData(5,Qt::Horizontal,QObject::tr("cinclient"));
    return query;
}

QSqlQueryModel * coli::afficherp_tri_poids(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from coli ORDER BY poids");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Idcoli"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_d"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
    query->setHeaderData(5,Qt::Horizontal,QObject::tr("cinclient"));
    return query;
}

QSqlQueryModel * coli::afficherp_tri_type(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from coli ORDER BY type");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Idcoli"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_d"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
    query->setHeaderData(5,Qt::Horizontal,QObject::tr("cinclient"));
    return query;
}
