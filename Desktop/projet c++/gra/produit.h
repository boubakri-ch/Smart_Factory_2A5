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
    bool supprimer(QString);
    bool modifier();
private:
    int id;
    QString nom;
    QString date;
    QString quantiter;
   int id_f;

};
#endif // PRODUIT_H
