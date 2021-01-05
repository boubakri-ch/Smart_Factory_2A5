#include "client.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

client::client()
{
    this->cin_client=0;
    this->nom_client="";
    this->prenom_client="";
    this->localisation_client="";
}

client::client(int cin_client, QString nom_client, QString prenom_client, QString localisation_client)
{
    this->cin_client=cin_client;
    this->nom_client=nom_client;
    this->prenom_client=prenom_client;
    this->localisation_client=localisation_client;
}

bool client::ajouter(){

    QSqlQuery query;

    query.prepare("insert into client (cin_client,nom_client,prenom_client,localisation_client)"
                  "values(:cin_client,:nom_client,:prenom_client,:localisation_client)");
    QString ids=QString::number(cin_client);
    query.bindValue(":cin_client",ids);
    query.bindValue(":nom_client",nom_client);
    query.bindValue(":prenom_client",prenom_client);
    query.bindValue(":localisation_client",localisation_client);

    return query.exec();
}

QSqlQueryModel * client::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from client");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_client"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_client"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_client"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Localisation_client"));
    return query;
}

bool client::supprimer(int idd)
{
    QSqlQuery query;

    query.prepare("Delete from client where cin_client=:id");
    QString idds=QString::number(idd);
    query.bindValue(":id",idds);
    return query.exec();
}

bool client::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE client set nom_client=:nom_client,prenom_client=:prenom_client,localisation_client=:localisation_client WHERE cin_client=:cin_client");
    query1.bindValue(":cin_client",cin_client);
    query1.bindValue(":nom_client",nom_client);
    query1.bindValue(":prenom_client",prenom_client);
    query1.bindValue(":localisation_client",localisation_client);

    return (query1.exec());
}

QSqlQueryModel * client::rechercher_dynamique(QString nom){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from client where nom_client like '"+nom+"%' or cin_client like '"+nom+"%' or prenom_client like '"+nom+"%' or localisation_client like '"+nom+"%' ");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_client"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_client"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_client"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Localisation_client"));
    return query;

}

QSqlQueryModel * client::afficher_tri_cin(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from client order by cin_client");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_client"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_client"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_client"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Localisation_client"));
    return query;
}
QSqlQueryModel * client::afficher_tri_nom(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from client order by nom_client");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_client"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_client"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_client"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Localisation_client"));
    return query;
}
QSqlQueryModel * client::afficher_tri_prenom(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from client order by prenom_client");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_client"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_client"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom_client"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Localisation_client"));
    return query;
}
