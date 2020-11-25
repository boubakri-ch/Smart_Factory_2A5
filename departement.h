#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include<QString>
#include <QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Departement
{
private:
    QString nomD;
    int idD,nbE,salaire;
public :
    Departement(){}
    Departement(int,QString,int,int);
    QString getNom(){return nomD;}
    int getId(){return idD;}
    int getNbe(){return nbE;}
    int getSalaire(){return salaire;}
    void setNom(QString nd){nomD=nd;}
    void setId(int idd){this->idD=idd;}
    void setNbe(int nb){this->nbE=nb;}
    void setSalaire(int s){this->salaire=s;}
    bool ajouter_Dep();
    QSqlQueryModel * afficher_Dep();
    bool supprimer_Dep(int);
    bool modifier_Dep(int,QString,int,int);
    QSqlQuery rechercher_idD(int idB);
    QSqlQueryModel * rechercher_Dep (const QString &aux);
    QSqlQueryModel *  trier_Dep(const QString &critere, const QString &mode );

};
#endif // DEPARTEMENT_H
