#include "stat_etat.h"
#include "ui_stat_etat.h"
#include <QDialog>
#include <QSqlQuery>

stat_etat::stat_etat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_etat)
{
    ui->setupUi(this);
    this->setWindowTitle("Statistiques");

    //***************************************************************
    QSqlQuery q1,q2,q3;
    qreal en_stock=0,en_cours=0,livre=0;
    QSqlQuery q4,q5,q6;
    qreal en_attente2=0,en_cours2=0,envoye2=0;

    q1.prepare("SELECT * FROM COLI WHERE ETAT='En stock'");
    q1.exec();
    q2.prepare("SELECT * FROM COLI WHERE ETAT='En cours' ");
    q2.exec();
    q3.prepare("SELECT * FROM COLI WHERE ETAT='Livre' ");
    q3.exec();

    while (q1.next()){en_stock++;}
    while (q2.next()){en_cours++;}
    while (q3.next()){livre++;}

    q4.prepare("SELECT * FROM COURRIER WHERE ETAT='En attente'");
    q4.exec();
    q5.prepare("SELECT * FROM COURRIER WHERE ETAT='En cours'");
    q5.exec();
    q6.prepare("SELECT * FROM COURRIER WHERE ETAT='Envoye'");
    q6.exec();

    while (q4.next()){en_attente2++;}
    while (q5.next()){en_cours2++;}
    while (q6.next()){envoye2++;}



}

stat_etat::~stat_etat()
{
    delete ui;
}
