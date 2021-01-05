#include "login.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

login::login(QString identifiant,QString mdp)
{
    this->identifiant=identifiant;
    this->mdp=mdp;
}

QSqlQuery login::verifierutilisateur(QString mdp)
{
    QSqlQuery query;
    query.prepare("select * from login where mdp=:mdp");
    query.bindValue(":mdp",mdp);
    query.exec();
    return query;

}

bool login::ajouterutilisateur()
{
    QSqlQuery query;
    query.prepare("insert into login (mdp,identifiant)"
                  "values (:mdp,:identifiant)");
    query.bindValue(":mdp",mdp);
    query.bindValue(":identifiant",identifiant);
    return query.exec();
}
