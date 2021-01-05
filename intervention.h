#ifndef INTERVENTION_H
#define INTERVENTION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtSql/QSqlDatabase>

class intervention
{
public:
    intervention();
    intervention(QString,QString,QString,QString);
        // getters
        QString getNom(){return nom;}
        QString getide(){return id_employee;}
        QString getID(){return idm;}
        QString getdate(){return date;}
        //setters
        void setNom(QString n ){nom=n;}
        void setIde(QString d){id_employee=d;}
        void setId(QString idm){this->idm=idm;}
        void setDate(QString date){this->date=date;}
        //fonctions de base relative a l'entite intervention
        bool ajouter();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher_tri_nom();
        QSqlQueryModel * afficher_tri_nom_desc();
        QSqlQueryModel * rechercher_dynamique_intervention(QString);

        bool modifier();
        bool supprimer(QString);


private:
    QString nom ,id_employee,idm , date;
};

#endif // INTERVENTION_H
