#include "employe.h"

employe::employe()
{


}
employe::employe(int id,QString nom,QString prenom,QString departement,QString dateNaissance,int numero)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->departement=departement;
    this->dateNaissance=dateNaissance;
    this->numero=numero;

}
bool employe::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("INSERT INTO EMPLOYÉ (CIN,NOM,PRENOM,ID_DEPARTEMENT,DATENAISSANCE,NUMERO) "
                        "VALUES (:id,:nom,:prenom,:departement,:dateNaissance,:numero)");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":departement", departement);
    query.bindValue(":dateNaissance", dateNaissance);
    query.bindValue(":numero",numero);
    return    query.exec();
}
QSqlQueryModel * employe::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EMPLOYÉ ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateNaissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_departement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero"));


        return model;
}

bool employe::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from EMPLOYÉ where CIN = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool employe:: modifier(int id,QString nom,QString prenom,QString departement,QString dateNaissance,int numero)
{

    QSqlQuery qry;
        qry.prepare("UPDATE EMPLOYÉ set NOM=(?),PRENOM=(?),NUMERO=(?),ID_DEPARTEMENT=(?) ,DATENAISSANCE=(?) where CIN=(?) ");
        qry.addBindValue(nom);
        qry.addBindValue(prenom);
        qry.addBindValue(numero);
        qry.addBindValue(departement);
        qry.addBindValue(dateNaissance);
        qry.addBindValue(id);
   return  qry.exec();
}
QSqlQuery employe::rechercher_id(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * from EMPLOYÉ  where CIN = :id");
    query.bindValue(":id", id);
    query.exec();

    return query;
}
QSqlQueryModel * employe::rechercher (const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from EMPLOYÉ where ((CIN || NOM || PRENOM || ID_DEPARTEMENT || NUMERO ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateNaissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_departement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero"));

    return model;
}
QSqlQueryModel *  employe::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EMPLOYÉ order by "+critere+" "+mode+"");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateNaissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_departement"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero"));
    return model;
}
