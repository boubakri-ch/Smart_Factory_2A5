#ifndef COLI_H
#define COLI_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class coli
{
public:
    coli();
    coli(int,QString,QString,int,int,int);


        int getIDCOLI(){return idcoli;}
        QString getadressed(){return adresse_d;}
        QString getType(){return type;}
        int getPoids(){return poids;}
        int getPrix(){return prix;}
        int getCINClient(){return cinclient;}

        void setIDCOLI(int idcoli){this->idcoli=idcoli;}
        void setAdressed(QString adresse_d){this->adresse_d=adresse_d;}
        void setTYPE(QString type){this->type=type;}
        void setPOIDS(int poids){this->poids=poids;}
        void setPrix(int prix){this->prix=prix;}
        void setCINCLIENT(int cinclient){this->cinclient=cinclient;}

        bool ajouterP();
        QSqlQueryModel * afficherp();
        bool supprimerp(int);
        bool modifierp();
        QSqlQueryModel * afficherp_tri_prix();
        QSqlQueryModel * afficherp_tri_poids();
        QSqlQueryModel * afficherp_tri_type();
        QSqlQueryModel * rechercher_dynamique_produit(QString);
        QSqlQueryModel * afficherp_stat();
private:
    int idcoli;
    QString adresse_d,type;
    int poids,prix,cinclient;
};

#endif // COLI_H
