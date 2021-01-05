#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class categorie
{
public:
    categorie();
    categorie(int,QString, QString);

    int getID(){return id;}
    QString getNom(){return nom;}
    QString getType(){return type;}
    void setID(int id){this->id=id;}
    void setNOM(QString nom){this->nom=nom;}
    void setType(QString type){this->type=type;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher_tri_alphabetique_categorie();
    QSqlQueryModel * afficher_tri_identifiant_categorie();
    QSqlQueryModel * rechercher_dynamique(QString);
    QSqlQueryModel * afficher_tri_descendant_categorie();

private:
    int id;
    QString nom, type;


};

#endif // CATEGORIE_H
