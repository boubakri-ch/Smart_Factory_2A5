#include"fournisseur.h"
#include<QMessageBox>
#include <QDebug>
#include<QSqlQuery>
#include<QVariant>


FOURNISSEUR::FOURNISSEUR()
{

   id=0;
    nom="";
    prenom="";
    Num="";
    RIB="";


}
FOURNISSEUR::FOURNISSEUR(QString nom,QString prenom,int id,QString Num,QString RIB)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->Num=Num;
    this->RIB=RIB;

}

QString FOURNISSEUR::get_nom()
{
    return nom;

}
QString FOURNISSEUR::get_prenom(){

    return prenom;

}

int FOURNISSEUR::get_id(){


    return id;
}
QString FOURNISSEUR::get_Num()
{
    return Num;

}
QString FOURNISSEUR::getRIB()
{

    return RIB;
}


bool FOURNISSEUR::ajouter(){
    QSqlQuery query;
    query.prepare("insert into FOURNISSEUR(id_fournisseur,date_fournisseur,nom_fournisseur,prenom_fournisseur,Num_Tel,RIB)values(:id,sysdate,:nom,:prenom,:Num,:RIB)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":Num",Num);
    query.bindValue(":RIB",RIB);


    return query.exec();
}
QSqlQueryModel *FOURNISSEUR::afficher(){

QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from FOURNISSEUR ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FOURNISSEUR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Num_tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("RIB"));


return model ;

}
QSqlQueryModel *FOURNISSEUR::affichertri(){

QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from FOURNISSEUR order by nom_FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FOURNISSEUR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Num_tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("RIB"));


return model ;

}
QSqlQueryModel *FOURNISSEUR::afficher_tri_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR order by id_FOURNISEEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FOURNISSEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Num_tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("RIB"));


    return model ;

}
QSqlQueryModel *FOURNISSEUR::afficher_tri_prenom(){

QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from FOURNISSEUR order by prenom_FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FOURNISSEUR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Num_tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("RIB"));


return model ;

}
bool FOURNISSEUR::supprimer(QString id) {
QSqlQuery query;
QString res=id;
query.prepare("delete from FOURNISSEUR where id_fournisseur ='"+res+"'");
return query.exec();

}
bool FOURNISSEUR::modifier(){
    QSqlQuery query;
    query.prepare("update FOURNISSEUR set id_fournisseur=:id,nom_fournisseur=:nom,prenom_fournisseur=:prenom,Num_Tel=:Num,RIB=:RIB where id_fournisseur=:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":Num",Num);
    query.bindValue(":RIB",RIB);

    return query.exec();


}
