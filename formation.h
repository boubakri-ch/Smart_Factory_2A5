#ifndef FORMATION_H
#define FORMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class formation
{
public:
    formation();
    formation(int,QString,QString,QString);
        QString get_nom();
        QString get_domaine();
        QString get_departement();
        int get_CODE();
        bool ajouter();
        QSqlQueryModel * afficher0();
        QSqlQueryModel * afficher_f_code();
        QSqlQueryModel * afficher2();
        QSqlQueryModel * afficher3();
        QSqlQueryModel * afficher4();
        bool supprimer(int);
        bool modifier(int,QString,QString,QString);
        QSqlQueryModel * rechercher(const QString);

    private:
        QString nom,domaine,departement;
        int CODE;
};

#endif // FORMATION_H

