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
}

produit::produit(int idp, QString nomp, int quantity,int prix){

    this->idp=idp;
    this->nomp=nomp;
    this->quantity=quantity;
    this->prix=prix;
}

bool produit::ajouterP(){

    QSqlQuery query;

    query.prepare("insert into produit (idp,nomp,quantity,prix)"
                  "values(:idp,:nomp,:quantity,:prix)");
    QString ids=QString::number(idp);

    query.bindValue(":idp",ids);
    query.bindValue(":nomp",nomp);
    query.bindValue(":quantity",quantity);
    query.bindValue(":prix",prix);

    return query.exec();
}

QSqlQueryModel * produit::afficherp(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from produit");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("IdentifiantP"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("NomP"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    return query;
}

bool produit::modifierp(){
    QSqlQuery query1;
    query1.prepare("UPDATE produit set nomp=:nomp,quantity=:quantity,prix=:prix WHERE idp=:idp");
    query1.bindValue(":idp",idp);
    query1.bindValue(":nomp",nomp);
    query1.bindValue(":quantity",quantity);
    query1.bindValue(":prix",prix);

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
