#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client(int,QString, QString,QString);

    int getCin(){return cin_client;}
    QString getNomc(){return nom_client;}
    QString getPrenomc(){return prenom_client;}
    QString getlocalisation(){return localisation_client;}
    void setCin(int cin_client){this->cin_client=cin_client;}
    void setNOMc(QString nom_client){this->nom_client=nom_client;}
    void setPrenomc(QString prenom_client){this->prenom_client=prenom_client;}
    void setlocalisation(QString localisation_client){this->localisation_client=localisation_client;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher_tri_prenom();
    QSqlQueryModel * afficher_tri_cin();
    QSqlQueryModel * rechercher_dynamique(QString);
    QSqlQueryModel * afficher_tri_nom();
private:
    int cin_client;
    QString nom_client,prenom_client,localisation_client;
};

#endif // CLIENT_H
