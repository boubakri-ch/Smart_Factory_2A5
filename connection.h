#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{
public:
    connexion();
    void fermerconnexion();
    bool ouvrirconnexion();
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QODBC");

};

#endif // CONNECTION_H
