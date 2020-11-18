#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formation.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(tmpFORMATION.afficher());
    ui->tableView->setModel(tmpFORMATEUR.afficher());
    ui->tableView_3->setModel(tmpFORMATION.afficher());
    ui->tableView_3->setModel(tmpFORMATION.rechercher(ch));
    ui->tableView_4->setModel(tmpFORMATEUR.afficher());
    ui->tableView_4->setModel(tmpFORMATEUR.rechercher(ch));
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AJOUTER_clicked()
{
    int code=ui->lineEdit_ideFRMTIONADD->text().toInt();
    QString nom=ui->lineEdit_NOMFRMTSADD->text();
    QString domaine=ui->lineEdit_DOMAINEADDFRMTS->text();
    QString departement=ui->lineEdit_depart_add->text();
    FORMATION f(code,nom,domaine,departement);
    bool test=f.ajouter();
    if(test)

    {
         ui->tableView_2->setModel(tmpFORMATION.afficher());
            ui->tableView_3->setModel(tmpFORMATION.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajout formations"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout formation"),
                                 QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_VALIDERMOD_clicked()
{
    int code=ui->lineEdit_IDMODFRMTS->text().toInt();
    QString nom=ui->lineEdit_NOUVNOMMOD->text();
    QString domaine=ui->lineEdit_NOUVDOMMOD->text();
    QString departement=ui->lineEdit_dep->text();
    FORMATION f(code,nom,domaine,departement);
    bool test=f.modifier(code,nom,domaine,departement);
    if(test)
    {
        ui->tableView_2->setModel(tmpFORMATION.afficher());
           ui->tableView_3->setModel(tmpFORMATION.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier formations"),
                                 QObject::tr("Modifier avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier formation"),
                                 QObject::tr("Modification échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_SUPPRIMERFRMTS_clicked()
{
    int code=ui->lineEdit_IDSUPP->text().toInt();
    bool test=f.supprimer(code);
    if(test)
    {
           ui->tableView_3->setModel(tmpFORMATION.afficher());
        ui->tableView_2->setModel(tmpFORMATION.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer formations"),
                                 QObject::tr("supprimer avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer formation"),
                                 QObject::tr("suppression échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_add_teurs_clicked()
{
    int cin=ui->lineEdit_ID_ADD_teurs->text().toInt();
    QString nom=ui->lineEdit_nom_add_teurs->text();
    QString domaine=ui->lineEdit_dom_add_teurs->text();
    FORMATEUR g(cin,nom,domaine);
    bool test=g.ajouter();
    if(test)

    {
         ui->tableView_4->setModel(tmpFORMATEUR.afficher());
         ui->tableView->setModel(tmpFORMATEUR.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajout formateurs"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout formateurs"),
                                 QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_mod_teurs_clicked()
{
    int cin=ui->lineEdit_id_mod_teur->text().toInt();
    QString nom=ui->lineEdit_nom_mod_teurs->text();
    QString domaine=ui->lineEdit_dom_mod_teurs->text();
    FORMATEUR g(cin,nom,domaine);
    bool test=g.modifier(cin,nom,domaine);
    if(test)
    {
         ui->tableView_4->setModel(tmpFORMATEUR.afficher());
        ui->tableView->setModel(tmpFORMATEUR.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier formateurs"),
                                 QObject::tr("Modifier avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier formateurs"),
                                 QObject::tr("Modification échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pushButton_supp_teur_clicked()
{
    int cin=ui->lineEdit_id_supp_teurs->text().toInt();
    bool test=g.supprimer(cin);
    if(test)
    {
         ui->tableView_4->setModel(tmpFORMATEUR.afficher());
        ui->tableView->setModel(tmpFORMATEUR.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer formateurs"),
                                 QObject::tr("supprimer avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer formateurs"),
                                 QObject::tr("suppression échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_rechercher_3_textChanged(const QString &ch)
{
    if (ch=="")
    ui->tableView_3->setModel(f.afficher());
    else
    this->ui->tableView_3->setModel(f.rechercher(ch));


}
void MainWindow::on_rechercher_2_textChanged(const QString &ch)
{
    if (ch=="")
    ui->tableView_4->setModel(g.afficher());
    else
    this->ui->tableView_4->setModel(g.rechercher(ch));

}
