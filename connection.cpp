#include "connection.h"
#include<QDebug>
//First Commit
connexion::connexion()
{

}
bool connexion::ouvrirconnexion()
{
    mydb.setDatabaseName("terter_projet");
    mydb.setUserName("tatar");
    mydb.setPassword("tatar");
    if (mydb.open())
    {
        qDebug () <<"connect .. ";
        return(true);

    }

    return false ;}
void connexion ::fermerconnexion()

{
    mydb.close();
}



