#ifndef COURRIER_H
#define COURRIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"
class courrier
{
    public:
    QString type,adresseem,adressedest,priorite,etat;
    QString prix;

    courrier();
    courrier(QString,QString,QString,QString,QString,QString,QString);
    QString get_idcourrier();
    QSqlQueryModel *afficherCourrier();
    bool ajouterCourrier();
    bool supprimerCourrier(QString idcourrier);
    bool modifierCourrier(QString idcourrier,QString etat);

    QSqlQueryModel * recherche (const QString &idcourrier);
    QSqlQueryModel * trier(const QString &critere,const QString &mode );
    QSqlQuery getQuery();

    private:
    QString idcourrier;
    connexion cnx;


};
#endif // COURRIER_H
