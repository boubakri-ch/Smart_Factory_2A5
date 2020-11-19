#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class produit
{
public:
    produit();
    produit(int,QString,int,int);


    int getIDP(){return idp;}
    QString getNomP(){return nomp;}
    int getQuantity(){return quantity;}
    int getPrix(){return prix;}
    void setIDP(int idp){this->idp=idp;}
    void setNOMP(QString nomp){this->nomp=nomp;}
    void setQuantity(int quantity){this->quantity=quantity;}
    void setPrix(int prix){this->prix=prix;}


    bool ajouterP();
    QSqlQueryModel * afficherp();
    bool supprimerp(int);
    bool modifierp();
    QSqlQueryModel * afficherp_tri_alphabetique();
    QSqlQueryModel * afficherp_tri_identifiant();



private:
    int idp;
    QString nomp;
    int quantity,prix;
};

#endif // PRODUIT_H
