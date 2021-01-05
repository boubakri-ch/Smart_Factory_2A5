#include "materiel.h"

materiel::materiel()
{

}
materiel::materiel(QString id,  int quantite_t ,int prix_u ,   int datefab, QString fournisseur  )
{
this->id=id;
    this->quantite_t=quantite_t;

    this->prix_u=prix_u;
    this->datefab=datefab;
    this->fournisseur=fournisseur;

}
bool materiel::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(prix_u);
    QString res1=QString::number(datefab);
    QString res2=QString::number(quantite_t);

    query.prepare("INSERT INTO materiel (id,QUANTITE_T, PRIX_U, DATEFAB,FOURNISSEUR) "
                        "VALUES (:id, :quantite_t, :prix_u, :datefab, :fournisseur)");
    query.bindValue(":prix_u", res);
    query.bindValue(":datefab", res1);
    query.bindValue(":quantite_t", res2);


    query.bindValue(":id", id);
    query.bindValue(":fournisseur", fournisseur);




    return    query.exec();

}


bool materiel::modifier(QString id , int quantite_t ,int prix_u , int datefab, QString fournisseur )
{
    QSqlQuery query;
    QString res= QString::number(prix_u);
    QString res1= QString::number(quantite_t);
    QString res2= QString::number(datefab);


    query.prepare("update materiel set quantite_t=:quantite_t,prix_u=:prix_u,datefab=:datefab, fournisseur=:fournisseur where id=:id");
    query.bindValue(":id",id);
    query.bindValue(":quantite_t",res1 );

    query.bindValue(":prix_u", res);
    query.bindValue(":datefab",res2);
    query.bindValue(":fournisseur", fournisseur);
    return query.exec();
}
bool materiel::supprimer(QString idd)
{

    QSqlQuery query;
    query.prepare("Delete from materiel where id = :id ");
    query.bindValue(":id", idd);
    return    query.exec();
}



QSqlQueryModel * materiel::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from materiel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("date de fabrication"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fournisseur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantité"));
        return model;

}

QSqlQueryModel * materiel::afficher_date_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from materiel order by fournisseur ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("date de fabrication"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fournisseur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantité"));
        return model;

}

QSqlQueryModel * materiel::afficher_id_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from materiel order by fournisseur desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("date de fabrication"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fournisseur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantité"));
        return model;

}

QSqlQueryModel * materiel::afficher_id_tri_desc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from materiel order by id desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("date de fabrication"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fournisseur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantité"));
        return model;

}

QSqlQueryModel * materiel::rechercher_dynamique_materiel(QString p){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from materiel where id like '"+p+"%' or fournisseur like '"+p+"%' or quantite_t like '"+p+"%' or prix_u like '"+p+"%'");
    query->setHeaderData(0, Qt::Horizontal, QObject::tr("date de fabrication"));
    query->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));

    query->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
    query->setHeaderData(3, Qt::Horizontal, QObject::tr("fournisseur"));
    query->setHeaderData(4, Qt::Horizontal, QObject::tr("quantité"));
    return query;

}
