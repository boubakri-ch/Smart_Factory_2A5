#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include "produit.h"
#include "fournisseur.h"
#include "matierepremiere.h"
#include "formateur.h"
#include<QDate>
#include<QDateTime>
#include<QDesktopServices>
#include<QSqlQuery>
#include <QMessageBox>
#include <QTabWidget>
#include <QString>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempEtudiant.afficher());
    ui->tableView_3->setModel(tempProduit.afficherp());
    ui->tableView_stat->setModel(tempProduit.afficherp_stat());
    ui->tableView_matierep->setModel(tempmatiereprem.afficher_matiere_premiere());
    ui->table_fournisseur->setModel(tempFournisseur.afficher_fournisseur());
    ui->lineEdit_ID->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_IDP->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Ajouter_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    int ide=ui->lineEdit_ID->text().toInt();
    QString nome=ui->lineEdit_Nom->text();
    QString prenome=ui->lineEdit_Prnom->text();
    etudiant e(ide,nome,prenome);
    bool test=e.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempEtudiant.afficher());
        ui->lineEdit_ID->clear();
        ui->lineEdit_Nom->clear();
        ui->lineEdit_Prnom->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

    query->prepare("select ID from categorie");
    query->exec();
    model->setQuery(*query);
    ui->comboBox_ajout->setModel(model);
    ui->comboBox_modifier->setModel(model);
}

void MainWindow::on_pushButton_Supprimer_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    int ide=ui->lineEdit_ID_Suppr->text().toInt();
    bool test=tempEtudiant.supprimer(ide);
    if(test){
        QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempEtudiant.afficher());
        ui->lineEdit_ID_Suppr->clear();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
    query->prepare("select ID from categorie");
    query->exec();
    model->setQuery(*query);
    ui->comboBox_ajout->setModel(model);
    ui->comboBox_modifier->setModel(model);
}

void MainWindow::on_pushButton_modifier_clicked()
{
    tempEtudiant.setID(ui->lineEdit_I_MOD->text().toInt());
    tempEtudiant.setNOM(ui->lineEdit_N_MOD->text());
    tempEtudiant.setPrenom(ui->lineEdit_P_MOD->text());

    if(tempEtudiant.modifier())
    {
        QMessageBox::information(nullptr, QObject::tr("modification etudiant"),
                                 QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempEtudiant.afficher());
        ui->lineEdit_I_MOD->clear();
        ui->lineEdit_N_MOD->clear();
        ui->lineEdit_P_MOD->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification etudiant"),
                                 QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_trier_clicked()
{
     ui->tableView->setModel(tempEtudiant.afficher_tri_alphabetique_categorie());
}

void MainWindow::on_pushButton_rechercher_clicked()
{


        /*QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery query1;
        int ide=ui->lineEdit_ID_rech->text().toInt();
        query1.prepare("select * from etudiant where id=:id");
        QString idds=QString::number(ide);
        query1.bindValue(":id",idds);
        query1.exec();
        model->setQuery(query1);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
        ui->tableView_2->setModel(model);
        ui->lineEdit_ID_rech->clear();
*/
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(tempEtudiant.afficher_tri_identifiant_categorie());
}

void MainWindow::on_pdf_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tableView->model()->rowCount();
                    const int columnCount =ui->tableView->model()->columnCount();

                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("CATEGORIE")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<img src='logo.png' width='100' height ='100'>\n"
                                "<h1>liste des categories </h1>"



                                "<table border=1 cellspacing=0 cellpadding=2>\n";


                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tableView->isColumnHidden(column)) {
                                       QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";

            QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);


              //  QTextDocument document;
               // document.setHtml(html);
                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("categorie.pdf");
                document->print(&printer);
                QDesktopServices::openUrl(QUrl::fromLocalFile("categorie.pdf"));


}

void MainWindow::on_print_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();
    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("DEPARTEMENT")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
                "<img src='C:/Users/Maher/Desktop/gestion stock/logo.png' width='100' height='100'>\n"
                "<h1>Liste des Departements </h1>"



                "<table border=1 cellspacing=0 cellpadding=2>\n";
    for(int column = 0;column < columnCount; column++)
        if(!ui->tableView->isColumnHidden(column))
            out <<QString("<td>%1</td>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
    for(int row = 0;row < rowCount; row++)
    {
        out <<"<tr>";
        for(int column = 0 ;column < columnCount ; column++)
        {
            if(!ui->tableView->isColumnHidden(column))
            {
                QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
    }
    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);
    QPrinter printer;
    QPrintDialog *daddy = new QPrintDialog(&printer , NULL);
    if(daddy->exec() == QDialog::Accepted){
        document->print(&printer);
    }
    delete document;

}

void MainWindow::on_pushButton_apply_clicked()
{

}

void MainWindow::on_pushButton_Ajout_P_clicked()
{
    int idp=ui->lineEdit_IDP->text().toInt();
    QString nomp=ui->lineEdit_NOMP->text();
    int quantity=ui->lineEdit_QP->text().toInt();
     int prix=ui->lineEdit_PP->text().toInt();
     int idc=ui->comboBox_ajout->currentText().toInt();

    produit p(idp,nomp,quantity,prix,idc);
    bool test=p.ajouterP();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempProduit.afficherp());
        ui->lineEdit_IDP->clear();
        ui->lineEdit_NOMP->clear();
        ui->lineEdit_QP->clear();
        ui->lineEdit_PP->clear();
    }
    //else
        QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_afficherp_clicked()
{
    ui->tableView_3->setModel(tempProduit.afficherp());
}

void MainWindow::on_pushButton_produit_mod_clicked()
{
    tempProduit.setIDP(ui->lineEdit_IDP_MOD->text().toInt());
    tempProduit.setNOMP(ui->lineEdit_NP_MOD->text());
    tempProduit.setQuantity(ui->lineEdit_QP_MOD->text().toInt());
    tempProduit.setPrix(ui->lineEdit_PP_MOD->text().toInt());
    tempProduit.setIDC(ui->comboBox_modifier->currentText().toInt());


    if(tempProduit.modifierp())
    {
        QMessageBox::information(nullptr, QObject::tr("modification produit"),
                                 QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempProduit.afficherp());
        ui->lineEdit_IDP_MOD->clear();
        ui->lineEdit_NP_MOD->clear();
        ui->lineEdit_QP_MOD->clear();
        ui->lineEdit_PP_MOD->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification produit"),
                                 QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_ps_clicked()
{
    int ide=ui->lineEdit_P_S->text().toInt();
    bool test=tempProduit.supprimerp(ide);
    if(test){
        QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempProduit.afficherp());
        ui->lineEdit_P_S->clear();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_P_RECHERCHE_clicked()
{
    QSqlQueryModel * model1 = new QSqlQueryModel();
    QSqlQuery query1;
    int ide=ui->lineEdit_P_R->text().toInt();
    query1.prepare("select * from produit where idp=:idp");
    QString idds=QString::number(ide);
    query1.bindValue(":idp",ide);
    query1.exec();
    model1->setQuery(query1);
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    ui->tableView_3->setModel(model1);
    ui->lineEdit_P_R->clear();
}

void MainWindow::on_lineEdit_r_d_textChanged(const QString &arg1)
{
    QString nom = ui->lineEdit_r_d->text();
    ui->tableView->setModel(tempEtudiant.rechercher_dynamique(nom));

}

void MainWindow::on_ajouter_fournisseur_clicked()
{
    int id=ui->id_fournisseur->text().toInt();
        QString Num=ui->num_tel_fournisseur->text();
         QString RIB=ui->RIB_fournisseur->text();
       QString nom=ui->nom_fournisseur->text();
        QString prenom=ui->prenom_fournisseur->text();
        fournisseur F(nom,prenom,id,Num,RIB);
        bool test=F.ajouter();


        if(test)
        {
         ui->table_fournisseur->setModel(tempFournisseur.afficher_fournisseur());
            QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                                   QObject::tr("fournisseur ajoutée.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
        QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery *query=new QSqlQuery();
        query->prepare("select ID_FOURNISSEUR from fournisseur");
        query->exec();
        model->setQuery(*query);
        ui->list_fournisseur->setModel(model);
         ui->liste_fournisseur_2->setModel(model);
}

void MainWindow::on_modifier_fournisseur_clicked()
{
    int id=ui->id_modifier->text().toInt();
        QString nom=ui->nom_modifier->text();
         QString prenom=ui->prenom_modifier->text();
        QString RIB=ui->RIB_modifier->text();
         QString Num=ui->Num_modifier->text();
         fournisseur F(nom,prenom,id,Num,RIB);
         bool test=F.modifier();
         if(test)
         {
     ui->table_fournisseur->setModel(tempFournisseur.afficher_fournisseur());
             QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                                    QObject::tr("fournisseur modifier.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void MainWindow::on_tri_id_fournisseur_clicked()
{
    ui->table_fournisseur->setModel(tempFournisseur.tri_fournisseur());
}

void MainWindow::on_supprimer_fournisseur_clicked()
{
    QString id=ui->id_f_supp->text();
        bool test=tempFournisseur.supprimer(id);
        if(test)
        {
            ui->table_fournisseur->setModel(tempFournisseur.afficher_fournisseur());
                    QMessageBox::information(nullptr, QObject::tr("suprrimer un fournisseur"),
                                           QObject::tr("fournisseur supprimer.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
        }
}


void MainWindow::on_pushButton_recherchef_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query1;
    int ide=ui->lineEdit_f_rech->text().toInt();
    query1.prepare("select * from FOURNISSEUR where id_fournisseur=:id");
    QString idds=QString::number(ide);
    query1.bindValue(":id",idds);
    query1.exec();
    model->setQuery(query1);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("RIB"));
    ui->table_fournisseur->setModel(model);
    ui->lineEdit_f_rech->clear();

}

void MainWindow::on_pushButton_p_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
 ui->tableView->setModel(tempEtudiant.afficher_tri_descendant_categorie() );
}


void MainWindow::on_comboBox_modifier_activated(int index)
{

}

void MainWindow::on_pushButton_p_prix_clicked()
{
    ui->tableView_3->setModel(tempProduit.afficherp_tri_prix() );
}

void MainWindow::on_pushButton_excel_clicked()
{
    QTableView *table;
               table = ui->tableView;

               QString filters("xlsx files (.xls);;All files (.*)");
               QString defaultFilter("xlsx files (*.xls)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                             QObject::tr("Export avec succes .\n"
                                                         "Click OK to exit."), QMessageBox::Ok);
               }
}

void MainWindow::on_ajout_matierep_clicked()
{
    int id=ui->id_matierep_ajout->text().toInt();
    int id_f=ui->list_fournisseur->currentText().toInt();
    QString quantity=ui->quantite_matierep_ajout->text();
    QString nom=ui->nom_matierep_ajout->text();
    QString date=ui->date_matierep_ajout->date().toString("dd-MM-yyyy");
    matierepremiere m(nom,date,quantity,id,id_f);
    bool test=m.ajouter_matiere_premiere();
    if(test)
    {
        ui->tableView_matierep->setModel(tempmatiereprem.afficher_matiere_premiere());
        QMessageBox::information(nullptr, QObject::tr("ajout matiere premiere"),
                                  QObject::tr("ajout avec succes .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("ajout matiere premiere"),
                                  QObject::tr("echec .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimer_matierep_clicked()
{
    QString id=ui->id_matierep_supp->text();
    bool test=tempmatiereprem.supprimer_matiere_premiere(id);
    if(test)
    {
        ui->tableView_matierep->setModel(tempmatiereprem.afficher_matiere_premiere());
    }

}

void MainWindow::on_modification_matierep_clicked()
{
    int id=ui->id_matierep_mod->text().toInt();
    int id_f=ui->liste_fournisseur_2->currentText().toInt();
    QString date=ui->date_matierp_mod->text();
    QString nom=ui->nom_matierep_mod->text();
    QString quantiter=ui->quantite_matierep_mod->text();
    matierepremiere p(nom,date,quantiter,id,id_f);
    bool test=p.modifier_matiere_premiere();
    if(test)
    {
        ui->tableView_matierep->setModel(tempmatiereprem.afficher_matiere_premiere());
    }
}

void MainWindow::on_tri_id_clicked()
{
    ui->tableView_matierep->setModel(tempmatiereprem.tri_selon_id());

}

void MainWindow::on_rechercher_id_matierep_textChanged(const QString &arg1)
{
    QString r = ui->rechercher_id_matierep->text();
    ui->tableView_matierep->setModel(tempmatiereprem.rechercher_dynamique_id_matiere(r));
}

void MainWindow::on_pdf_matiere_premiere_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tableView_matierep->model()->rowCount();
                    const int columnCount =ui->tableView_matierep->model()->columnCount();

                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("matiere premiere")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<img src='logo.png' width='100' height ='100'>\n"
                                "<h1>liste des matieres premieres </h1>"



                                "<table border=1 cellspacing=0 cellpadding=2>\n";


                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView_matierep->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableView_matierep->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tableView_matierep->isColumnHidden(column)) {
                                       QString data = ui->tableView_matierep->model()->data(ui->tableView_matierep->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";

            QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);


              //  QTextDocument document;
               // document.setHtml(html);
                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("matierep.pdf");
                document->print(&printer);
                QDesktopServices::openUrl(QUrl::fromLocalFile("matierep.pdf"));

}

void MainWindow::on_ajout_formateur_clicked()
{
    int cin=ui->cin_formateur_ajout->text().toInt();
    QString nom=ui->nom_formateur_ajout->text();
    QString domaine=ui->prenom_formateur_ajout->text();
    formateur g(cin,nom,domaine);
    bool test=g.ajouter();
    if(test)
    {
        ui->tableView_formateur->setModel(tempformateur.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout formateur"),
                                  QObject::tr("ajout avec succes .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("ajout formateur"),
                                  QObject::tr("echec  .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_formateur_clicked()
{
    int cin=ui->id_formateur_supprimer->text().toInt();
    bool test=tempformateur.supprimer(cin);
    if(test)
    {
        ui->tableView_formateur->setModel(tempformateur.afficher());
    }

}

void MainWindow::on_modifier_formateur_clicked()
{
    int cin=ui->id_formateur_mod->text().toInt();
    QString nom=ui->nom_formateur_mod->text();
    QString domaine=ui->prenom_formateur_mod->text();
    formateur g(cin,nom,domaine);
    bool test=g.modifier(cin,nom,domaine);
    if(test)
    {
        ui->tableView_formateur->setModel(tempformateur.afficher());
        QMessageBox::information(nullptr, QObject::tr("modification formateur"),
                                  QObject::tr("modification avec succes .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("modification formateur"),
                                  QObject::tr("echec .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_radioButton_CIN_clicked()
{
    ui->tableView_formateur->setModel(tempformateur.afficher());
}

void MainWindow::on_radioButton_nom_clicked()
{
    ui->tableView_formateur->setModel(tempformateur.afficher2());
}

void MainWindow::on_radioButton_prenom_clicked()
{
    ui->tableView_formateur->setModel(tempformateur.afficher3());
}

void MainWindow::on_genere_liste_formateur_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tableView_formateur->model()->rowCount();
                    const int columnCount =ui->tableView_formateur->model()->columnCount();

                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("formateur")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<img src='logo.png' width='100' height ='100'>\n"
                                "<h1>liste des formateurs </h1>"



                                "<table border=1 cellspacing=0 cellpadding=2>\n";


                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView_formateur->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableView_formateur->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tableView_formateur->isColumnHidden(column)) {
                                       QString data = ui->tableView_formateur->model()->data(ui->tableView_formateur->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";

            QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);


              //  QTextDocument document;
               // document.setHtml(html);
                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("formateur.pdf");
                document->print(&printer);
                QDesktopServices::openUrl(QUrl::fromLocalFile("formateur.pdf"));
}
