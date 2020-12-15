
#include "etudiant.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

etudiant::etudiant()
{
    this->id=0;
    this->nom="";
    this->prenom="";
}
etudiant::etudiant(int id, QString nom, QString prenom){

    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
}
bool etudiant::ajouter(){

    QSqlQuery query;

    query.prepare("insert into categorie (id,nom,type)"
                  "values(:id,:nom,:prenom)");
    QString ids=QString::number(id);
    query.bindValue(":id",ids);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    return query.exec();
}

QSqlQueryModel * etudiant::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}

bool etudiant::supprimer(int idd)
{
    QSqlQuery query;

    query.prepare("Delete from categorie where id=:id");
    QString idds=QString::number(idd);
    query.bindValue(":id",idds);
    return query.exec();

}

bool etudiant::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE categorie set type=:nom,nom=:prenom WHERE id=:id");
    query1.bindValue(":id",id);
    query1.bindValue(":nom",nom);
    query1.bindValue(":prenom",prenom);

    return (query1.exec());
}

QSqlQueryModel * etudiant::afficher_tri_alphabetique_categorie(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie ORDER BY nom");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}
QSqlQueryModel * etudiant::afficher_tri_identifiant_categorie(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie ORDER BY id");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}

QSqlQueryModel * etudiant::rechercher_dynamique(QString nom){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie where nom like '"+nom+"%' or id like '"+nom+"%' or type like '"+nom+"%' ");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}

QSqlQueryModel * etudiant::afficher_tri_descendant_categorie(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from categorie ORDER BY id DESC");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return query;

}
