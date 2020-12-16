#ifndef FORMATION_H
#define FORMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class FORMATION
{
public:
    FORMATION();
    FORMATION(int,QString,QString,QString);
    QString get_nom();
    QString get_domaine();
    QString get_departement();
    int get_CODE();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    QSqlQueryModel * afficher3();
    QSqlQueryModel * afficher4();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString);
    QSqlQueryModel * rechercher(const QString);
    QSqlQueryModel * afficher_stat ();

private:
    QString nom,domaine,departement;
    int CODE;


};

#endif // FORMATION_H
