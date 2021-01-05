#include "fournisseur.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QVariant>

fournisseur::fournisseur()
{

}
fournisseur::fournisseur(QString nom,QString prenom,int id,QString Num,QString RIB)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->Num=Num;
    this->RIB=RIB;

}

QString fournisseur::get_nom()
{
    return nom;

}
QString fournisseur::get_prenom(){

    return prenom;

}

int fournisseur::get_id(){


    return id;
}
QString fournisseur::get_Num()
{
    return Num;

}
QString fournisseur::getRIB()
{

    return RIB;
}


bool fournisseur::ajouter(){
    QSqlQuery query;
    query.prepare("insert into FOURNISSEUR(id_fournisseur,date_fournisseur,nom_fournisseur,prenom_fournisseur,Num_Tel,RIB)values(:id,sysdate,:nom,:prenom,:Num,:RIB)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":Num",Num);
    query.bindValue(":RIB",RIB);


    return query.exec();
}

QSqlQueryModel *fournisseur::afficher_fournisseur(){

QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from FOURNISSEUR ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_tel"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("RIB"));
return model ;

}

QSqlQueryModel *fournisseur::tri_fournisseur(){

QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from FOURNISSEUR ORDER BY id_fournisseur ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_tel"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("RIB"));
return model ;

}

QSqlQueryModel *fournisseur::tri_fournisseur_RIB_desc(){

QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from FOURNISSEUR ORDER BY RIB DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_tel"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("RIB"));
return model ;

}
QSqlQueryModel *fournisseur::tri_fournisseur_nom(){

QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from FOURNISSEUR ORDER BY nom_fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_tel"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("RIB"));
return model ;

}

bool fournisseur::supprimer(QString id) {
QSqlQuery query;
QString res=id;
query.prepare("delete from FOURNISSEUR where id_fournisseur ='"+res+"'");
return query.exec();

}
bool fournisseur::modifier(){
    QSqlQuery query;
    query.prepare("update FOURNISSEUR set id_fournisseur=:id,nom_fournisseur=:nom,prenom_fournisseur=:prenom,Num_Tel=:Num,RIB=:RIB where id_fournisseur=:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":Num",Num);
    query.bindValue(":RIB",RIB);

    return query.exec();
}

QSqlQueryModel * fournisseur::rechercher_dynamique_fournisseur(QString f){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from fournisseur where id_fournisseur like '"+f+"%' or nom_fournisseur like '"+f+"%' or prenom_fournisseur like '"+f+"%' or Num_Tel like '"+f+"%' or RIB like '"+f+"%' ");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("IdentifiantP"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("NomP"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));
    return query;

}
