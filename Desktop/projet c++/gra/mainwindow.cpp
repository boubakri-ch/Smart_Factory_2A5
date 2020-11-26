#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fournisseur.h"
#include"produit.h"
#include <QMessageBox>
#include<QDate>
#include<QDateTime>
#include<QSqlQuery>
#include<QMediaPlayer>
#include<QFileDialog>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPrintDialog>

//git first commit
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_four->setModel(tab_four.afficher());
    ui->tab_pro->setModel(tab_pro.afficher());
    mMediaPlayer = new QMediaPlayer(this);
    connect(mMediaPlayer,& QMediaPlayer::positionChanged,[&](qint64 pos){
        ui->avance->setValue(pos);
    });
    connect(mMediaPlayer,& QMediaPlayer::durationChanged,[&] (quint64 dur)
    {
        ui->avance->setMaximum(dur);
    });




}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->id->text().toInt();
     QString nom=ui->nom_fournisseur_2->text();
     QString prenom=ui->prenom_fournisseur->text();
     QString Num=ui->Num_fournisseur->text();
      QString RIB=ui->RIB_fournisseur->text();
     FOURNISSEUR F(nom,prenom,id,Num,RIB);
     bool test=F.ajouter();


     if(test)
     {
 ui->table_four->setModel(tab_four.afficher());
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
      ui->list_fournisseur_2->setModel(model);
}



void MainWindow::on_pushButton_clicked()
{
    QString id=ui->id_sup->text();
    bool test=tab_four.supprimer(id);
    if(test)
    {
        ui->table_four->setModel(tab_four.afficher());
                QMessageBox::information(nullptr, QObject::tr("suprrimer un fournisseur"),
                                       QObject::tr("fournisseur supprimer.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->id_modifier->text().toInt();
    QString nom=ui->nom_modifier->text();
     QString prenom=ui->prenom_modifier->text();
    QString RIB=ui->RIB_modifier->text();
     QString Num=ui->Num_modifier->text();
     FOURNISSEUR F(nom,prenom,id,Num,RIB);
     bool test=F.modifier();
     if(test)
     {
 ui->table_four->setModel(tab_four.afficher());
         QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                                QObject::tr("fournisseur modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }
}

void MainWindow::on_pushButton_4_clicked()
{

    QString id=ui->id_4->text();
    bool test=tab_pro.supprimer(id);
    if(test)
    {
        ui->tab_pro->setModel(tab_pro.afficher());
                QMessageBox::information(nullptr, QObject::tr("suprrimer un produit"),
                                       QObject::tr("produit supprimer.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_6_clicked()
{

    int id=ui->id_ajouter->text().toInt();
     int id_f=ui->list_fournisseur->currentText().toInt();
    QString quantiter=ui->quantiter_ajouter->text();
    QString nom=ui->nom_ajouter->text();
     QString date=ui->date_ajouter->date().toString("dd-MM-yyyy");
     PRODUIT P(nom,date,quantiter,id,id_f);
     bool test=P.ajouter();
     if(test)
     {
 ui->tab_pro->setModel(tab_pro.afficher());
         QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                                QObject::tr("produit ajoutée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }


}

void MainWindow::on_pushButton_5_clicked()
{

    int id=ui->id_modifier_2->text().toInt();
int id_f=ui->list_fournisseur_2->currentText().toInt();
      QString date=ui->date_modifier_2->text();
    QString nom=ui->nom_modifier_2->text();
     QString quantiter=ui->quantiter_modifier->text();
     PRODUIT P(nom,date,quantiter,id,id_f);
     bool test=P.modifier();
     if(test)
     {
 ui->tab_pro->setModel(tab_pro.afficher());
         QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                                QObject::tr("produit modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }

}

void MainWindow::on_pushButton_7_clicked()
{
      ui->table_four->setModel(tab_four.affichertri());
}
//recherche simple
void MainWindow::on_pushButton_8_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query1;
    int ide=ui->lineEdit_r_f->text().toInt();
    query1.prepare("select * from FOURNISSEUR where id_fournisseur=:id");
    QString idds=QString::number(ide);
    query1.bindValue(":id",idds);
    query1.exec();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_FOURNISSEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_FOURNISSEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FOURNISSEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Num_tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("RIB"));
    ui->table_four->setModel(model);
    ui->lineEdit_r_f->clear();
}

void MainWindow::on_apporter_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"apporter");
    if(filename.isEmpty()){
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mMediaPlayer->setVolume(ui->volume->value());
            on_play_clicked();
}

void MainWindow::on_play_clicked()
{
    mMediaPlayer->play();
}

void MainWindow::on_pause_clicked()
{
   mMediaPlayer->pause();
}

void MainWindow::on_stop_clicked()
{
    mMediaPlayer->stop();
}

void MainWindow::on_mute_clicked()
{
    if(ui->mute->text()=="mute")
    {
        mMediaPlayer->setMuted(true);
        ui->mute->setText("unMute");
    }
    mMediaPlayer->setMuted(false);
    ui->mute->setText("Mute");
}

void MainWindow::on_volume_valueChanged(int value)
{
      mMediaPlayer->setVolume(value);
}

void MainWindow::on_pushButton_9_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->table_four->model()->rowCount();
                    const int columnCount =ui->table_four->model()->columnCount();

                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("FOURNISSEUR")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<img src='C:/logo.png' width='100' height='100'>\n"
                                "<h1>Liste des fournisseur </h1>"



                                "<table border=1 cellspacing=0 cellpadding=2>\n";


                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->table_four->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->table_four->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->table_four->isColumnHidden(column)) {
                                       QString data = ui->table_four->model()->data(ui->table_four->model()->index(row, column)).toString().simplified();
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
                printer.setOutputFileName("fournissseur.pdf");
                document->print(&printer);
    }


void MainWindow::on_pushButton_10_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tab_pro->model()->rowCount();
                    const int columnCount =ui->tab_pro->model()->columnCount();

                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("PRODUIT")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<img src='C:/logo.png' width='100' height='100'>\n"
                                "<h1>Liste des produit </h1>"



                                "<table border=1 cellspacing=0 cellpadding=2>\n";


                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tab_pro->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tab_pro->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tab_pro->isColumnHidden(column)) {
                                       QString data = ui->tab_pro->model()->data(ui->tab_pro->model()->index(row, column)).toString().simplified();
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
                printer.setOutputFileName("produit.pdf");
                document->print(&printer);

}

void MainWindow::on_pushButton_11_clicked()
{
     ui->table_four->setModel(tab_four.afficher_tri_id());
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->table_four->setModel(tab_four.afficher_tri_prenom());
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->tab_pro->setModel(tab_pro.afficher_tri_quantiter());
}

void MainWindow::on_pushButton_14_clicked()
{
   ui->tab_pro->setModel(tab_pro.afficher_tri_date());
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->tab_pro->setModel(tab_pro.afficher_tri_nom());
}
