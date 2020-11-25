#include "connection.h"
#include<QSqlDatabase>
Connection::Connection()
{

}
bool Connection :: createConnection()
{

bool test=false;
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet1");
db.setUserName("chiheb");
db.setPassword("chiheb");
if(db.open())
    test=true;
return test;
}
