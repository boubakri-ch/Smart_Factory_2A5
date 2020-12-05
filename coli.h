#ifndef COLI_H
#define COLI_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"

class coli
{
    public:
    QString adresseem,adressedest,priorite,etat;
    QString poids,prix;
    int avecliv;


    coli();
    coli(QString,QString,QString,QString,QString,QString,QString,int);
    QString get_idcoli();
    QSqlQueryModel * afficherColi();
    bool ajouterColi();
    bool supprimerColi(QString idcoli);
    bool modifierColi(QString idcoli,QString etat,QString avecliv);

    QSqlQueryModel * recherche(const QString &idcoli);
    QSqlQueryModel * trier(const QString &critere,const QString &mode );
    QSqlQueryModel *afficheridcoli();
    QSqlQuery getQuery();


private:
QString idcoli;
connexion cnx;
};
#endif // COLI_H
