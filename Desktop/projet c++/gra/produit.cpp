#include"produit.h"
#include<QMessageBox>
#include <QDebug>
#include<QSqlQuery>
PRODUIT::PRODUIT()
{
     id=0;;
     nom="";
    date="";
     quantiter="";
     id_f=0;
}
PRODUIT::PRODUIT(QString nom,QString date,QString quantiter,int id,int id_f)
{

    this->id=id;
    this->nom=nom;
    this->quantiter=quantiter;
    this->date=date;
    this->id_f=id_f;

}
QString PRODUIT::get_nom()
{
    return nom;

}
QString PRODUIT::get_quantiter(){

    return quantiter;

}

int PRODUIT::get_id(){


    return id;
}
QString PRODUIT::get_date()
{
    return date;
}
int PRODUIT::get_id_f()
{

    return id_f;
}
bool PRODUIT::ajouter(){
    QSqlQuery query;
    query.prepare("insert into PRODUIT(id_produit,date_produit,nom_produit,quantiter_produit,id_f)values(:id,:date,:nom,:quantiter,:id_f)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":quantiter",quantiter);
    query.bindValue(":date",date);
    query.bindValue(":id_f",id_f);


    return query.exec();
}
QSqlQueryModel *PRODUIT::afficher(){

QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from PRODUIT ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_PRODUIT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantiter_PRODUIT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_PRODUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
return model ;
}
QSqlQueryModel *PRODUIT::afficher_tri_nom()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from PRODUIT order by nom_PRODUIT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantiter_PRODUIT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_PRODUIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));

    return model ;

}
QSqlQueryModel *PRODUIT::afficher_tri_quantiter()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from PRODUIT order by quantiter_PRODUIT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantiter_PRODUIT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_PRODUIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));

    return model ;

}
QSqlQueryModel *PRODUIT::afficher_tri_date()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from PRODUIT order by date_PRODUIT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantiter_PRODUIT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_PRODUIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));

    return model ;

}
bool PRODUIT::supprimer(QString id) {
QSqlQuery query;
QString res=id;
query.prepare("delete from PRODUIT where id_produit ='"+res+"'");
return query.exec();

}
bool PRODUIT::modifier(){
    QSqlQuery query;
    query.prepare("update PRODUIT set id_produit=:id,nom_produit=:nom,date_produit=:date,quantiter_produit=:quantiter,id_f=:id_f where id_produit=:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":date",date);
    query.bindValue(":quantiter",quantiter);
     query.bindValue(":id_f",id_f);

    return query.exec();

}
QSqlQueryModel * PRODUIT::afficher_rechrerche(QString q){

    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from PRODUIT where nom_PRODUIT like '%"+q+"%' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantiter_PRODUIT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_PRODUIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));

 return model ;
}
