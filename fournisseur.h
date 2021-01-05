#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>

#include <QSqlQueryModel>
class fournisseur
{
public:
    fournisseur();
    fournisseur(QString,QString,int,QString,QString);

    QString get_nom();
    QString get_prenom();

    int get_id();
       QString get_Num();
       QString getRIB();
       bool ajouter();
       QSqlQueryModel *afficher_fournisseur();
       QSqlQueryModel *tri_fournisseur();
       QSqlQueryModel *tri_fournisseur_RIB_desc();
       QSqlQueryModel *tri_fournisseur_nom();
       QSqlQueryModel * rechercher_dynamique_fournisseur(QString);
       bool supprimer(QString);
       bool modifier();
   private:
       int id;
       QString nom;
       QString prenom;
       QString Num;
       QString RIB;
};


#endif // FOURNISSEUR_H

