#include"employe.h"

Employe::Employe(int id,QString nom,QString prenom,QString departement,QDate dateNaissance,int numero)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->departement=departement;
    this->dateNaissance=dateNaissance;
    this->numero=numero;

}
bool Employe::ajouter()
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
QSqlQueryModel * Employe::afficher()
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

bool Employe::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from EMPLOYÉ where CIN = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool Employe:: modifier(int id,QString nom,QString prenom,QString departement,QDate dateNaissance,int numero)
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
QSqlQuery Employe::rechercher_id(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * from EMPLOYÉ  where CIN = :id");
    query.bindValue(":id", id);
    query.exec();

    return query;
}
QSqlQueryModel * Employe::rechercher (const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from EMPLOYÉ where ((CIN || NOM || PRENOM ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateNaissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_departement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero"));

    return model;
}
QSqlQueryModel *  Employe::trier(const QString &critere, const QString &mode )
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
