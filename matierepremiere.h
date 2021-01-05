#ifndef MATIEREPREMIERE_H
#define MATIEREPREMIERE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class matierepremiere
{
public:
    matierepremiere();
    matierepremiere(QString,QString,QString,int,int);

        QString get_nom();
        QString get_date();
        int get_id_f();
        QString get_quantity();
        int get_id();
        bool ajouter_matiere_premiere();
        QSqlQueryModel *afficher_matiere_premiere();
        QSqlQueryModel *tri_selon_id();
        QSqlQueryModel *tri_selon_quantity();
        QSqlQueryModel *tri_selon_nom();
        QSqlQueryModel * rechercher_dynamique_id_matiere(QString);
        bool supprimer_matiere_premiere(QString);
        bool modifier_matiere_premiere();
private:
    int id_matiere;
    QString nom_matiere;
    QString date_matiere;
    QString quantity_matiere;
    int id_f;
};

#endif // MATIEREPREMIERE_H
