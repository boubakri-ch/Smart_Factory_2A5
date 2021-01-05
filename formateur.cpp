#include "formateur.h"

formateur::formateur()
{
    cin=0;
    nom="";
    prenom="";
}
formateur::formateur(int cin,QString nom,QString prenom)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
}

QString formateur::get_nom(){return nom;}
QString formateur::get_prenom(){return prenom;}
int formateur::get_CIN(){return cin;}

bool formateur::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("insert into formateur(cin,nom,prenom) values (:cin,:nom,:prenom)");
    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    return query.exec();
}
QSqlQueryModel * formateur::afficher0()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from formateur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}

QSqlQueryModel * formateur::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from formateur ORDER BY cin");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}

QSqlQueryModel * formateur::afficher2()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from formateur ORDER BY nom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}

QSqlQueryModel * formateur::afficher3()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from formateur ORDER BY prenom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}

bool formateur::supprimer(int cin)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("delete from formateur where cin=:cin");
    query.bindValue(":cin",res);

    return query.exec();
}

bool formateur::modifier(int cin, QString nom, QString prenom)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("update formateur set nom=:nom ,prenom=:prenom where cin=:cin");
    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    return query.exec();
}

QSqlQueryModel * formateur::rechercher(const QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from formateur where cin like '"+ch+"%' or nom like '"+ch+"%' or prenom like '"+ch+"%' ";
    model->setQuery(str);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}
