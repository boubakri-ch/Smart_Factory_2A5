#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>


class login
{
public:
    login(){}
    login(QString,QString);
    QSqlQuery verifierutilisateur(QString);
    bool ajouterutilisateur();
private:
    QString mdp,identifiant;
};

#endif // LOGIN_H

