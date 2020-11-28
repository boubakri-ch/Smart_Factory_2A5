#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>

#include<QSqlQueryModel>


class PRODUIT
{


public:
    PRODUIT();
    PRODUIT(QString,QString,QString ,int,int);

    QString get_nom();
    QString get_date();
    int get_id_f();
 QString get_quantiter();
    int get_id();
    bool ajouter();
    QSqlQueryModel *afficher();
    QSqlQueryModel *afficher_tri_nom();
     QSqlQueryModel *afficher_tri_quantiter();
       QSqlQueryModel *afficher_tri_date();
    bool supprimer(QString);
    bool modifier();
     QSqlQueryModel * afficher_rechrerche(QString );
private:
    int id;
    QString nom;
    QString date;
    QString quantiter;
   int id_f;

};
#endif // PRODUIT_H
