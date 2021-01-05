#ifndef MATERIEL_H
#define MATERIEL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class materiel
{
public:
    materiel();
    materiel(QString,int,int,int,QString);
        // getters
        QString getid(){return id;}
        QString getFournisseur(){return fournisseur;}
        int getPrix_u(){return prix_u;}
        int getDatefab(){return datefab;}
        int getQuantite_t(){return quantite_t;}
        //setters
        void setid(QString n ){id=n;}
        void setFournisseur(QString p){fournisseur=p;}
        void setPrix_u(int d){prix_u=d;}
        void setDatefab(int id){datefab=id;}
        void setQuantite_t(int salaire){quantite_t=salaire;}
        //fonctions de base relative a l'entite materiel
        bool ajouter();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher_date_tri();
        QSqlQueryModel * afficher_id_tri();
        QSqlQueryModel * afficher_id_tri_desc();
        QSqlQueryModel * rechercher_dynamique_materiel(QString);
        bool modifier(QString,int,int,int,QString);
        bool supprimer(QString);
private:
    QString id, fournisseur;
    int prix_u , datefab,quantite_t;
};

#endif // MATERIEL_H
