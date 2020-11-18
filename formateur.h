#ifndef FORMATEUR_H
#define FORMATEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class FORMATEUR
{
public:
    FORMATEUR();
    FORMATEUR(int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_CIN();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString);
    QSqlQueryModel * rechercher(const QString);
private:
    QString nom,prenom;
    int CIN;


};
#endif // FORMATEUR_H
