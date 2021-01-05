#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class produit
{
public:
    produit();
    produit(int,QString,int,int,int);


        int getIDP(){return idp;}
        QString getNomP(){return nomp;}
        int getQuantity(){return quantity;}
        int getPrix(){return prix;}
        int getIDC(){return idc;}
        void setIDP(int idp){this->idp=idp;}
        void setNOMP(QString nomp){this->nomp=nomp;}
        void setQuantity(int quantity){this->quantity=quantity;}
        void setPrix(int prix){this->prix=prix;}
        void setIDC(int idc){this->idc=idc;}

        bool ajouterP();
        QSqlQueryModel * afficherp();
        bool supprimerp(int);
        bool modifierp();
        QSqlQueryModel * afficherp_tri_prix();
        QSqlQueryModel * afficherp_tri_identifiant();
        QSqlQueryModel * afficherp_tri_quantity();
        QSqlQueryModel * rechercher_dynamique_produit(QString);
        QSqlQueryModel * afficherp_stat();


    private:
        int idp;
        QString nomp;
        int quantity,prix;
        int idc;
};

#endif // PRODUIT_H
