#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formation.h"
#include <QMessageBox>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("SMART FACTORY");
    setWindowIcon(QIcon(":/53378.png"));
    QPixmap bg(":/black.jpg");
    ui->label_20->setPixmap(bg);
    ui->tableView_2->setModel(tmpFORMATION.afficher());
     ui->tableView_2->setModel(tmpFORMATION.afficher2());
      ui->tableView_2->setModel(tmpFORMATION.afficher3());
       ui->tableView_2->setModel(tmpFORMATION.afficher4());
    ui->tableView->setModel(tmpFORMATEUR.afficher());
    ui->tableView->setModel(tmpFORMATEUR.afficher2());
    ui->tableView->setModel(tmpFORMATEUR.afficher3());
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
sound->play();
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
    sound->play();
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
    sound->play();
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
    sound->play();
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
    sound->play();
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
    sound->play();
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
    sound->play();
    if (ch=="")
    ui->tableView_3->setModel(f.afficher());
    else
    this->ui->tableView_3->setModel(f.rechercher(ch));


}
void MainWindow::on_rechercher_2_textChanged(const QString &ch)
{
    sound->play();
    if (ch=="")
    ui->tableView_4->setModel(g.afficher());
    else
    this->ui->tableView_4->setModel(g.rechercher(ch));

}
void MainWindow::on_radioButton_nom_clicked()
{
    sound->play();
    ui->tableView->setModel(tmpFORMATEUR.afficher2());

}
void MainWindow::on_radioButton_cin_clicked()
{
    sound->play();
     ui->tableView->setModel(tmpFORMATEUR.afficher());
}
void MainWindow::on_radioButton_pre_clicked()
{
    sound->play();
    ui->tableView->setModel(tmpFORMATEUR.afficher3());
}
void MainWindow::on_radioButton_CODE_clicked()
{
       ui->tableView_2->setModel(tmpFORMATION.afficher());
}
void MainWindow:: on_radioButton_NOM_clicked()
{
    sound->play();
     ui->tableView_2->setModel(tmpFORMATION.afficher2());
}
void MainWindow:: on_radioButton_DOMAINE_clicked()
{
    sound->play();
     ui->tableView_2->setModel(tmpFORMATION.afficher3());
}
void MainWindow:: on_radioButton_DEP_clicked()
{
    sound->play();
     ui->tableView_2->setModel(tmpFORMATION.afficher4());
}
void MainWindow:: on_pdf_tions_clicked()
{
    sound->play();
    QSqlQueryModel  *model = new QSqlQueryModel() ;

    QString linki = QFileDialog::getSaveFileName(this, tr("Export TXT"),"/FORMATION.txt", tr("Comma Separated Values (*.txt)"));


    fs=new (FORMATION);

        int x = 0;

        QString exportdata;

        model=fs->afficher();

        int counthidden = 0, jint = 0;

        while (jint < model->columnCount()) {

        counthidden+=ui->tableView_2->isColumnHidden(jint);

        jint++;
        }


        while (x < model->columnCount())
        {

        if (!ui->tableView_2->isColumnHidden(x))
        {

        exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());

        //msgbox(exportdata);

        if (model->columnCount() - x != counthidden)

        exportdata.append(";");

        else

        exportdata.append("\n");

        }
        x++;

        }

        int z = 0;

        exportdata.append("\n");

        while (z < model->rowCount()) {

        x = 0;

        while (x < model->columnCount()) {

        if (!ui->tableView_2->isColumnHidden(x)) {


        exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


        if (model->columnCount() - x != counthidden)
        {
            exportdata.append(";");

        }
        else
        {
        exportdata.append("\n");

        }
        }

        x++;

        }
        exportdata.append("\n");

        z++;
        }



           QFile file;

           if (!linki.isEmpty()) {

         file.setFileName(linki);

                if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

                    return;
        }
        QByteArray ttext;

        ttext.append(exportdata);

        file.write(ttext);
}
void MainWindow::on_pdf_teurs_clicked()
{
    sound->play();
    QSqlQueryModel  *model = new QSqlQueryModel() ;

    QString linki = QFileDialog::getSaveFileName(this, tr("Export TXT"),"/FORMATEUR.txt", tr("Comma Separated Values (*.txt)"));


    gs=new (FORMATEUR);

        int x = 0;

        QString exportdata;

        model=gs->afficher();

        int counthidden = 0, jint = 0;

        while (jint < model->columnCount()) {

        counthidden+=ui->tableView->isColumnHidden(jint);

        jint++;
        }


        while (x < model->columnCount())
        {

        if (!ui->tableView->isColumnHidden(x))
        {

        exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());

        //msgbox(exportdata);

        if (model->columnCount() - x != counthidden)

        exportdata.append(";");

        else

        exportdata.append("\n");

        }
        x++;

        }

        int z = 0;

        exportdata.append("\n");

        while (z < model->rowCount()) {

        x = 0;

        while (x < model->columnCount()) {

        if (!ui->tableView->isColumnHidden(x)) {


        exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


        if (model->columnCount() - x != counthidden)
        {
            exportdata.append(";");

        }
        else
        {
        exportdata.append("\n");

        }
        }

        x++;

        }
        exportdata.append("\n");

        z++;
        }



           QFile file;

           if (!linki.isEmpty()) {

         file.setFileName(linki);

                if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

                    return;
        }
        QByteArray ttext;

        ttext.append(exportdata);

        file.write(ttext);
}
