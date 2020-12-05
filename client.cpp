#include "client.h"
#include <QDebug>
#include <QTextDocument>
#include <QTextStream>
#include "connection.h"






Client::Client() {}

Client::Client(QString Date,QString Livraison,QString Prenom,QString Nom,QString Produit,QString CIN){
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Date=Date;
    this->Livraison=Livraison;
    this->CIN=CIN;
    this->Produit=Produit;
    this->cnx = connexion();
    this->cnx.ouvrirconnexion();

}
bool Client::ajouter_Client()
{
    QSqlQuery query = this->getQuery();
    qDebug() << "ahla";
    bool inserted = false;

    if (this->cnx.mydb.open()){
        query.prepare("INSERT INTO CLIENT (Nom,Prenom,Date1,Livraison,CIN,Produit) "
                      "VALUES (:Nom, :Prenom, :Date1,:Livraison, :CIN, :Produit)");

        query.bindValue(":Nom", Nom);
        query.bindValue(":Prenom", Prenom);
        query.bindValue(":Date1", Date);
        query.bindValue(":Livraison", Livraison);
        query.bindValue(":CIN",CIN);
        query.bindValue(":Produit", Produit);

        if (query.exec()){
            inserted = true;
        }
        else qDebug () << "failed";
    }
    else {
        qDebug() << "is not opened";
    }
    return inserted;
}
QSqlQueryModel * Client::afficher_Client()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Livraison"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

bool Client::supprimer(QString Prenom)
{

    QSqlQuery query(this->cnx.mydb.database());
    QString res= Prenom;
    query.prepare("Delete from CLIENT where Prenom = :Prenom ");
    query.bindValue(":Prenom",Prenom );
    return    query.exec();
}
bool Client::modifier(QString CIN)
{
    QSqlQuery query(this->cnx.mydb.database());

    query.prepare("update CLIENT set Nom=:Nom, Prenom=:Prenom, Livraison=:Livraison, Date1=:Date1, Produit=:Produit where CIN=:CIN");
    query.bindValue (":Nom",Nom);
    query.bindValue (":Prenom",Prenom);
    query.bindValue(":Date1",Date);
    query.bindValue(":Livraison",Livraison);
    query.bindValue(":CIN",CIN);
    query.bindValue(":Produit",Produit);
    return  query.exec();

}

QSqlQuery Client::getQuery() {
    return QSqlQuery(this->cnx.mydb.database());
}

/*QSqlQueryModel * Client :: rec(QString CIN)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select CIN,Nom,PreNom,Livraison,DATE_,Produit from Client where CIN='"+CIN+"'");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PreNom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Livraison"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Produit"));

    return model;
}*/



QSqlQueryModel * Client :: recherche_Clienta(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();


    QSqlQuery query = this->getQuery();
    qDebug() << "ahla";

        if (this->cnx.mydb.open()){

    query.prepare("SELECT * FROM CLIENT WHERE CIN LIKE :valeur order by CIN");


    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    if (query.exec()){

    }
    else qDebug () << "failed";
}
else {
    qDebug() << "is not opened";


}
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PreNom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Livraison"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Produit"));

    return model;

}

QSqlQueryModel * Client :: recherche_Clientd(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
  query.prepare("SELECT * FROM CLIENT WHERE CIN LIKE :valeur order by CIN desc");
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PreNom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Livraison"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Produit"));
    return model;

}


Client::~Client(){};

