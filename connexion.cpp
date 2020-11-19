#include "connexion.h"

//test tutoriel git


Connexion::Connexion()
{

}
bool Connexion::ouvrirConnexion()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("adem");
    db.setPassword("adem");


    if(db.open())
        return true;
    return false;

}
void Connexion::fermerConnexion()
{db.close();}
