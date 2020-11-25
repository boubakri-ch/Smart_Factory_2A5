#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include<QString>

#include<QSqlQueryModel>

class FOURNISSEUR
{
public:
    FOURNISSEUR();
    FOURNISSEUR(QString,QString,int,QString,QString);

    QString get_nom();
    QString get_prenom();

    int get_id();
    QString get_Num();
    QString getRIB();
    bool ajouter();
    QSqlQueryModel *afficher();
    QSqlQueryModel *affichertri();
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
