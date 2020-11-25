#include"departement.h"
Departement::Departement(int idD,QString nomD,int nbE,int salaire)
{
    this->idD=idD;
    this->nomD=nomD;
    this->nbE=nbE;
    this->salaire=salaire;

}
bool Departement::ajouter_Dep()
{
    QSqlQuery query;
    QString ress = QString::number(idD);
    query.prepare("INSERT INTO DEPARTEMENT (ID_DEPARTEMENT,NOM,NOMBRE_EMPLOYE,SALAIRE) "
                        "VALUES (:idD,:nomD,:nbE,:salaire)");
    query.bindValue(":idD", ress);
    query.bindValue(":nomD", nomD);
    query.bindValue(":nbE", nbE);
    query.bindValue(":salaire", salaire);
    return    query.exec();
}
QSqlQueryModel * Departement::afficher_Dep()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from DEPARTEMENT ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEPARTEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_D "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALAIRE"));


        return model;
}
QSqlQuery Departement::rechercher_idD(int idD)
{
    QSqlQuery query;
    query.prepare("SELECT * from DEPARTEMENT where ID_DEPARTEMENT = :idD");
    query.bindValue(":idD", idD);
    query.exec();

    return query;
}

bool Departement::supprimer_Dep(int idD)
{
    QSqlQuery query;
    QString res= QString::number(idD);
    query.prepare("Delete from DEPARTEMENT where ID_DEPARTEMENT = :idD");
    query.bindValue(":idD", res);
    return    query.exec();
}
bool Departement:: modifier_Dep(int idD, QString nomD, int nbE, int salaire)
{

    QSqlQuery qry;
        qry.prepare("UPDATE DEPARTEMENT set NOM=(?),NOMBRE_EMPLOYE=(?),SALAIRE=(?) where ID_DEPARTEMENT=(?) ");
        qry.addBindValue(nomD);
        qry.addBindValue(nbE);
        qry.addBindValue(salaire);
        qry.addBindValue(idD);
   return  qry.exec();
}
QSqlQueryModel * Departement::rechercher_Dep(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from DEPARTEMENT where ((ID_DEPARTEMENT || NOM || NOMBRE_EMPLOYE || SALAIRE ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEPARTEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_D "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALAIRE"));
    return model;
}
QSqlQueryModel *  Departement::trier_Dep(const QString &critere, const QString &mode)
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from DEPARTEMENT order by "+critere+" "+mode+"");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEPARTEMENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_D "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALAIRE"));
    return model;
}
