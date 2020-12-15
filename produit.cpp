#include "produit.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

produit::produit()
{
    this->idp=0;
    this->nomp="";
    this->quantity=0;
    this->prix=0;
    this->idc=0;
}

produit::produit(int idp, QString nomp, int quantity,int prix,int idc){

    this->idp=idp;
    this->nomp=nomp;
    this->quantity=quantity;
    this->prix=prix;
    this->idc=idc;
}

bool produit::ajouterP(){

    QSqlQuery query;

    query.prepare("insert into produit (idp,nomp,quantité,prix,idc)"
                  "values(:idp,:nomp,:quantity,:prix,:idc)");
    QString ids=QString::number(idp);

    query.bindValue(":idp",ids);
    query.bindValue(":nomp",nomp);
    query.bindValue(":quantity",quantity);
    query.bindValue(":prix",prix);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * produit::afficherp(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from produit");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("IdentifiantP"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("NomP"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));
    return query;
}

bool produit::modifierp(){
    QSqlQuery query1;
    query1.prepare("UPDATE produit set nomp=:nomp,quantité=:quantity,prix=:prix WHERE idp=:idp");
    query1.bindValue(":idp",idp);
    query1.bindValue(":nomp",nomp);
    query1.bindValue(":quantity",quantity);
    query1.bindValue(":prix",prix);
    query1.bindValue(":idc",idc);

    return (query1.exec());
}

bool produit::supprimerp(int idp)
{
    QSqlQuery query;

    query.prepare("Delete from produit where idp=:idp");
    QString idds=QString::number(idp);
    query.bindValue(":idp",idds);
    return query.exec();

}

QSqlQueryModel * produit::afficherp_tri_prix(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from produit ORDER BY prix");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("IdentifiantP"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("NomP"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));
    return query;
}

QSqlQueryModel * produit::afficherp_stat(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select SUM(prix) from produit");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("prix total"));

    return query;
}
