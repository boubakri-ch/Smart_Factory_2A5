#include "matierepremiere.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

matierepremiere::matierepremiere()
{

}

matierepremiere::matierepremiere(QString nom_matiere,QString date_matiere,QString quantity_matiere,int id_matiere,int id_f)
{
    this->id_matiere=id_matiere;
    this->nom_matiere=nom_matiere;
    this->date_matiere=date_matiere;
    this->quantity_matiere=quantity_matiere;
    this->id_f=id_f;
}

QString matierepremiere::get_nom()
{
    return nom_matiere;
}

QString matierepremiere::get_quantity()
{
    return quantity_matiere;
}

int matierepremiere::get_id()
{
    return id_matiere;
}

QString matierepremiere::get_date()
{
    return date_matiere;
}

int matierepremiere::get_id_f()
{
    return id_f;
}

bool matierepremiere::ajouter_matiere_premiere()
{
    QSqlQuery query;
    query.prepare("insert into matiere(id_matiere,nom_matiere,quantity_matiere,date_matiere,id_f) values (:id_matiere,:nom_matiere,:quantity_matiere,:date_matiere,:id_f)");

    query.bindValue(":id_matiere",id_matiere);
    query.bindValue(":nom_matiere",nom_matiere);
    query.bindValue(":quantity_matiere",quantity_matiere);
    query.bindValue(":date_matiere",date_matiere);
    query.bindValue(":id_f",id_f);
    return query.exec();
}

QSqlQueryModel * matierepremiere::afficher_matiere_premiere()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from matiere");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_matierep"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_matierep"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité_matierep"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_matierep"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("id_f"));
    return model;

}

bool matierepremiere::supprimer_matiere_premiere(QString id)
{
    QSqlQuery query;
    QString res=id;
    query.prepare("delete from matiere where id_matiere='"+res+"'");
    return query.exec();
}

bool matierepremiere::modifier_matiere_premiere()
{
    QSqlQuery query;
    query.prepare("update matiere set id_matiere=:id_matiere,nom_matiere=:nom_matiere,quantity_matiere=:quantity_matiere,date_matiere=:date_matiere where id_matiere=:id_matiere");
    query.bindValue(":id_matiere",id_matiere);
    query.bindValue(":nom_matiere",nom_matiere);
    query.bindValue(":quantity_matiere",quantity_matiere);
    query.bindValue(":date_matiere",date_matiere);
    return query.exec();
}

QSqlQueryModel * matierepremiere::tri_selon_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from matiere ORDER BY id_matiere");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_matierep"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_matierep"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité_matierep"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_matierep"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("id_f"));
    return model;

}
QSqlQueryModel * matierepremiere::tri_selon_quantity()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from matiere ORDER BY quantity_matiere desc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_matierep"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_matierep"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité_matierep"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_matierep"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("id_f"));
    return model;

}
QSqlQueryModel * matierepremiere::tri_selon_nom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from matiere ORDER BY nom_matiere");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_matierep"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_matierep"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité_matierep"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_matierep"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("id_f"));
    return model;

}

QSqlQueryModel * matierepremiere::rechercher_dynamique_id_matiere(QString r){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from matiere where nom_matiere like '"+r+"%' or id_matiere like '"+r+"%' or quantity_matiere like '"+r+"%' or id_f like '"+r+"%' ");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_matierep"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_matierep"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité_matierep"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("date_matierep"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("id_f"));
    return query;

}
