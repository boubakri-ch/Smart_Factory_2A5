#ifndef FORMATEUR_H
#define FORMATEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class formateur
{
public:
    formateur();
    formateur(int,QString,QString);
        QString get_nom();
        QString get_prenom();
        int get_CIN();
        bool ajouter();
        QSqlQueryModel * afficher0();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher2();
        QSqlQueryModel * afficher3();
        bool supprimer(int);
        bool modifier(int,QString,QString);
        QSqlQueryModel * rechercher(const QString);
private:
        QString nom,prenom;
        int cin;
};

#endif // FORMATEUR_H
