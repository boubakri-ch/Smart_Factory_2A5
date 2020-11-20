#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class etudiant
{
public:
    etudiant();
    etudiant(int,QString, QString);

    int getID(){return id;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    void setID(int id){this->id=id;}
    void setNOM(QString nom){this->nom=nom;}
    void setPrenom(QString prenom){this->prenom=prenom;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher_tri_alphabetique();
    QSqlQueryModel * afficher_tri_identifiant();



private:
    int id;
    QString nom, prenom;
};

#endif // ETUDIANT_H
