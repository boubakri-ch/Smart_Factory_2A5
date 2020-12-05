#include "commande.h"
#include "connection.h"

Commande::Commande()
{
     DESIGNATION="" ;
     PRIX_P=0 ;
     QUANTITE_P =0;
     IDCOMMANDE=0;
}

Commande::Commande(int IDCOMMANDE ,QString DESIGNATION,float PRIX_P,int QUANTITE_P  )
{
    this->DESIGNATION=DESIGNATION;
    this->PRIX_P=PRIX_P ;
    this->QUANTITE_P =QUANTITE_P;
    this->IDCOMMANDE =IDCOMMANDE;
}

QString Commande::get_Designation()
{
    return (DESIGNATION);
}
float Commande::get_prix()
{
    return (PRIX_P);
}
int Commande::get_quantite()
{
    return(QUANTITE_P);
}
bool Commande::ajouter_C ()
{
    QSqlQuery qry ;//requete mtaa el base de donnees

    QString res1=QString::number(QUANTITE_P);
    QString res2=QString::number(PRIX_P);
     QString res=QString::number(IDCOMMANDE);


  qry.prepare("INSERT INTO COMMANDE (IDCOMMANDE,DESIGNATION,QUANTITE_P,PRIX_P) "
              "VALUES (:IDCOMMANDE,:DESIGNATION,:QUANTITE_P,:PRIX_P)");//
  qry.bindValue(":DESIGNATION",DESIGNATION);//securite aal sql injeection
  qry.bindValue(":QUANTITE_P",res1);
  qry.bindValue(":PRIX_P",res2);
    qry.bindValue(":IDCOMMANDE",res);


  return qry.exec();
}



QSqlTableModel* Commande::supprimer()
{


QSqlTableModel *mmodel = new QSqlTableModel();
 mmodel->setTable("COMMANDE");
 mmodel->select();
 return mmodel;
}
QSqlTableModel *Commande::afficher2()//modifier
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("COMMANDE");
    mmodel->select();
    return mmodel;

}



void Commande:: rechercher_C(QTableView * table ,int  IDCOMMANDE )
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from COMMANDE where regexp_like(IDCOMMANDE,:IDCOMMANDE);");
    query->bindValue(":IDCOMMANDE",IDCOMMANDE);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void Commande::cleartable_C(QTableView * table)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->clear();
    table->setModel(model);

}

QSqlTableModel *Commande::tri_C(int num )
{

   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("COMMANDE");

   mmodel->setSort(num,Qt::DescendingOrder);
   mmodel->select();
   return mmodel;
}
