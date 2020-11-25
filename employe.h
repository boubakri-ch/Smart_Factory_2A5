#ifndef EMPLOYE_H
#define EMPLOYE_H

#include<QString>
#include <QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Employe
{
private :

    QString nom,prenom,departement;
    int id,numero;
    QDate dateNaissance;
public :

    Employe(){}
    Employe(int,QString,QString,QString,QDate,int);
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getDepartement(){return departement;}
    int getId(){return id;}
    QDate getDate(){return dateNaissance;}
    int getNumero(){return numero;}
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setId(int id){this->id=id;}
    void setDepartement(QString dp){departement=dp;}
    void setDate(QDate d){dateNaissance=d;}
    void setNumero(int nu){numero=nu;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QDate,int);
    QSqlQuery rechercher_id(int id);
    QSqlQueryModel * rechercher (const QString &aux);
    QSqlQueryModel *  trier(const QString &critere, const QString &mode );

};
#endif // EMPLOYE_H
