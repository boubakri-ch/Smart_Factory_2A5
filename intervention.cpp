#include "intervention.h"

intervention::intervention()
{

}
intervention::intervention(QString nom,QString id_employee,QString idm,QString date )
{
    this->nom=nom;
    this->id_employee=id_employee;
    this->idm=idm;
    this->date=date;
}
bool intervention::ajouter()
{
    QSqlQuery query;

     query.prepare("INSERT INTO intervention (IDM,DATE_I, NOM,ID) "
                        "VALUES (:idm, :date, :nom, :id_employee)");
    query.bindValue(":idm", idm);
    query.bindValue(":date", date);

    query.bindValue(":nom", nom);

    query.bindValue(":id_employee", id_employee);
    return    query.exec();
}



QSqlQueryModel * intervention::afficher()
{
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from intervention");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_employée"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_intervention"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));

        return model;
    }
}
QSqlQueryModel * intervention::afficher_tri_nom()
{
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from intervention order by nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_employée"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_intervention"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));

        return model;
    }
}
QSqlQueryModel * intervention::afficher_tri_nom_desc()
{
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from intervention order by nom desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_employée"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_intervention"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));

        return model;
    }
}
bool intervention::supprimer(QString res)
{

    QSqlQuery query;
    query.prepare("Delete from intervention where IDM = :idm ");
    query.bindValue(":idm", res);
    return    query.exec();
}

bool intervention::modifier( )
{
    QSqlQuery query;


    query.prepare("update intervention set date_i=:date,nom=:nom, id=:id_employee where idm=:idm");
    query.bindValue(":idm", idm);
    query.bindValue(":date",date );
    query.bindValue(":nom",nom);
    query.bindValue(":id_employee", id_employee);
    return query.exec();
}


QSqlQueryModel * intervention::rechercher_dynamique_intervention(QString p){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from intervention where nom like '"+p+"%' or idm like '"+p+"%' ");
    query->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_employée"));
    query->setHeaderData(1, Qt::Horizontal, QObject::tr("id_intervention"));
    query->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
    query->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
    return query;

}


