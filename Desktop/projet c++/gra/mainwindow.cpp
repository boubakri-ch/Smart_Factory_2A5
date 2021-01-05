#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fournisseur.h"
#include"produit.h"
#include"statistique.h"
#include <QMessageBox>
#include<QDate>
#include<QDateTime>
#include<QSqlQuery>
#include<QMediaPlayer>
#include<QFileDialog>
#include<QPrintDialog>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include<QSound>
#include <QRegExpValidator>
#include <QSystemTrayIcon>
#include<QDesktopServices>
#include<QUrl>
#include<QFile>
#include<QTextStream>
#include"arduino.h"
//git first commit
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    son=new QSound(":/son/son.wav");
    ui->setupUi(this);
    //**//
    mSystemTrayIcon= new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/photo/my.png"));
    mSystemTrayIcon->setVisible(true);
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

    QSqlQueryModel *model=new QSqlQueryModel();
       QSqlQuery qry;
       qry.prepare("select ID_FOURNISSEUR from FOURNISSEUR");
       qry.exec();
       model->setQuery(qry);
       ui->list_fournisseur->setModel(model);
       ui->list_fournisseur_2->setModel(model);
#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
       QRegExp rxNom(NOM_RX);
       QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
       ui->nom_fournisseur_2->setValidator(valiNom);//nomajoutproduit//
       ui->combo->setModel(tab_pro.afficher());

       mSocket=new QTcpSocket(this);
           mSocket->connectToHost("localhost",2000);
           if (mSocket->waitForConnected(3000))
           {
               ui->plainTextEdit->appendPlainText("se connecter correctement");
           }
           else
           {
               ui->plainTextEdit->appendPlainText("pas de connexion");
           }
           int ret=A.connect_arduino();
                      switch(ret)
                      {
                      case(0):qDebug()<<"arduino is available and connected to :"<<A.getarduino_port_name();
                          break;
                      case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
                          break;
                      case(-1):qDebug()<<"arduino is not available";
                      }
           connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(leer()));
}
void MainWindow::leer()
{
    temp=QString::fromStdString(A.read_from_arduino().toStdString());


        int masse=temp.toInt();
        qDebug()<<"masse="<<masse;
        QSqlQuery qry;
        qry.prepare("insert into mass values(sysdate,:masse)");
        qry.bindValue(":tempe",masse);

        qry.exec();

}



MainWindow::~MainWindow()
{


    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
son->play();
    int id=ui->id->text().toInt();
     QString nom=ui->nom_fournisseur_2->text();
     QString prenom=ui->prenom_fournisseur->text();
     QString Num=ui->Num_fournisseur->text();
      QString RIB=ui->RIB_fournisseur->text();
      histo.save("id:"+ui->id->text(),"nom :"+ui->nom_fournisseur_2->text());
     FOURNISSEUR F(nom,prenom,id,Num,RIB);
     bool test=F.ajouter();
if(ui->nom_fournisseur_2->text().isEmpty()||ui->Num_fournisseur->text().isEmpty()||ui->RIB_fournisseur->text().isEmpty()||ui->prenom_fournisseur->text().isEmpty()||ui->id->text().contains(QRegExp("^[1-9]"))==0){
 mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout echoue"));
    QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                           QObject::tr("ERREUR.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}
else{
     if(test)
     {//**//
        mSystemTrayIcon->showMessage(tr("Notification"),tr("fournisseur ajouté"));
 ui->table_four->setModel(tab_four.afficher());
         QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                                QObject::tr("fournisseur ajoutée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }


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
    son->play();
    QString id=ui->id_sup->text();
    bool test=tab_four.supprimer(id);
    if(ui->id->text().contains(QRegExp("^[1-9]"))==0){
     mSystemTrayIcon->showMessage(tr("Notification"),tr("ID n'existe pas"));
        QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                               QObject::tr("ERREUR.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}
    else{
    if(test)
    {
        mSystemTrayIcon->showMessage(tr("Notification"),tr("suppression validée "));
        ui->table_four->setModel(tab_four.afficher());
                QMessageBox::information(nullptr, QObject::tr("suprrimer un fournisseur"),
                                       QObject::tr("fournisseur supprimer.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                QSqlQueryModel *model= new QSqlQueryModel();
                QSqlQuery *query=new QSqlQuery();
                query->prepare("select ID_FOURNISSEUR from fournisseur");
                query->exec();
                model->setQuery(*query);
                ui->list_fournisseur->setModel(model);
                 ui->list_fournisseur_2->setModel(model);
    }
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    son->play();
    int id=ui->id_modifier->text().toInt();
    QString nom=ui->nom_modifier->text();
     QString prenom=ui->prenom_modifier->text();
    QString RIB=ui->RIB_modifier->text();
     QString Num=ui->Num_modifier->text();
     FOURNISSEUR F(nom,prenom,id,Num,RIB);
     bool test=F.modifier();
     if(ui->nom_modifier->text().isEmpty()||ui->Num_modifier->text().isEmpty()||ui->RIB_modifier->text().isEmpty()||ui->prenom_modifier->text().isEmpty()||ui->id_modifier->text().contains(QRegExp("^[1-9]"))==0){
      mSystemTrayIcon->showMessage(tr("Notification"),tr("ID n'existe pas"));
         QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                                QObject::tr("ERREUR.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else{
     if(test)
     {
         mSystemTrayIcon->showMessage(tr("Notification"),tr("Modification validée"));
 ui->table_four->setModel(tab_four.afficher());
         QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                                QObject::tr("fournisseur modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }
     }
}

void MainWindow::on_pushButton_4_clicked()
{
son->play();
    QString id=ui->id_4->text();
    bool test=tab_pro.supprimer(id);
    if(ui->id_4->text().contains(QRegExp("^[1-9]"))==0)
    {
        mSystemTrayIcon->showMessage(tr("Notification"),tr("Invalid"));
                QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                       QObject::tr("Erreur.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    if(test)
    {
        mSystemTrayIcon->showMessage(tr("Notification"),tr("suppression validée "));
        ui->tab_pro->setModel(tab_pro.afficher());
                QMessageBox::information(nullptr, QObject::tr("suprrimer un produit"),
                                       QObject::tr("produit supprimer.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }

}

void MainWindow::on_pushButton_6_clicked()
{
son->play();
    int id=ui->id_ajouter->text().toInt();
     int id_f=ui->list_fournisseur->currentText().toInt();
    QString quantiter=ui->quantiter_ajouter->text();
    QString nom=ui->nom_ajouter->text();
     QString date=ui->date_ajouter->date().toString("dd-MM-yyyy");
     histo.save("id:"+ui->id_ajouter->text(),"nom_ajouter :"+ui->nom_ajouter->text());
     PRODUIT P(nom,date,quantiter,id,id_f);
     bool test=P.ajouter();
     if(ui->nom_ajouter->text().isEmpty()||ui->quantiter_ajouter->text().isEmpty()||ui->id_ajouter->text().contains(QRegExp("^[1-9]"))==0)
     {
         mSystemTrayIcon->showMessage(tr("Notification"),tr("Invalid"));
                 QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                        QObject::tr("Erreur.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else{
     if(test)
     {
         mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout validée "));
          ui->combo->setModel(P.afficher());
      ui->tab_pro->setModel(tab_pro.afficher());
         QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                                QObject::tr("produit ajoutée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }

}
}

void MainWindow::on_pushButton_5_clicked()
{
son->play();
    int id=ui->id_modifier_2->text().toInt();
    int id_f=ui->list_fournisseur_2->currentText().toInt();
    QString date=ui->date_modifier_2->text();
    QString nom=ui->nom_modifier_2->text();
     QString quantiter=ui->quantiter_modifier->text();
     PRODUIT P(nom,date,quantiter,id,id_f);
     bool test=P.modifier();
     if(ui->nom_modifier_2->text().isEmpty()||ui->quantiter_modifier->text().isEmpty()||ui->id_modifier_2->text().contains(QRegExp("^[1-9]"))==0)
     {
         mSystemTrayIcon->showMessage(tr("Notification"),tr("Invalid"));
                 QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                        QObject::tr("Erreur.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else{
     if(test)
     {
         mSystemTrayIcon->showMessage(tr("Notification"),tr("modification validée "));
 ui->tab_pro->setModel(tab_pro.afficher());
         QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                                QObject::tr("produit modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }
     }

}

void MainWindow::on_pushButton_7_clicked()
{
    son->play();
      ui->table_four->setModel(tab_four.affichertri());
}



void MainWindow::on_apporter_clicked()
{
   son->play();
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

    son->play();
    mMediaPlayer->play();
}

void MainWindow::on_pause_clicked()
{
    son->play();
   mMediaPlayer->pause();
}

void MainWindow::on_stop_clicked()
{
    son->play();
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
    son->play();
      mMediaPlayer->setVolume(value);
}

void MainWindow::on_pushButton_9_clicked()
{
    son->play();
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->table_four->model()->rowCount();
    const int columnCount =ui->table_four->model()->columnCount();

                               out <<  "<html>\n"
                                       "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                       <<  QString("<title>%1</title>\n").arg("fournisseur")
                                       <<  "</head>\n"
                                       "<body bgcolor=#ffffff link=#5000A0>\n"
                                           "<img src='C:/Users/Pavillion/Desktop/E-HEALTH/photo/logo' width='100' height='100'>\n"
                                           "<h1>FOURNISSEUR </h1>"



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
                                      QTextDocument * document = new  QTextDocument ();

                           document->setHtml(strStream);



                           QPrinter printer(QPrinter::PrinterResolution);

                                                       document-> setHtml (strStream);

                                                       QPrinter QPrinter;

                                                       QPrintDialog * dialog = new  QPrintDialog (& QPrinter, NULL );
                                                       if (dialog-> exec () == QDialog::Accepted) {
                                                           document-> print (& QPrinter);}
    }


void MainWindow::on_pushButton_10_clicked()
{
    son->play();
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tab_pro->model()->rowCount();
                       const int columnCount =ui->tab_pro->model()->columnCount();

                               out <<  "<html>\n"
                                       "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                       <<  QString("<title>%1</title>\n").arg("produit")
                                       <<  "</head>\n"
                                       "<body bgcolor=#ffffff link=#5000A0>\n"
                                           "<img src='C:/Users/Pavillion/Desktop/E-HEALTH/photo/logo' width='100' height='100'>\n"
                                           "<h1>PRODUIT </h1>"



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
                                      QTextDocument * document = new  QTextDocument ();

                           document->setHtml(strStream);



                           QPrinter printer(QPrinter::PrinterResolution);

                                                       document-> setHtml (strStream);

                                                       QPrinter QPrinter;

                                                       QPrintDialog * dialog = new  QPrintDialog (& QPrinter, NULL );
                                                       if (dialog-> exec () == QDialog::Accepted) {
                                                           document-> print (& QPrinter);}

}

void MainWindow::on_pushButton_11_clicked()
{
    son->play();
     ui->table_four->setModel(tab_four.afficher_tri_id());
}

void MainWindow::on_pushButton_12_clicked()
{
    son->play();
    ui->table_four->setModel(tab_four.afficher_tri_prenom());
}

void MainWindow::on_pushButton_13_clicked()
{
    son->play();
    ui->tab_pro->setModel(tab_pro.afficher_tri_quantiter());
}

void MainWindow::on_pushButton_14_clicked()
{
    son->play();
   ui->tab_pro->setModel(tab_pro.afficher_tri_date());
}

void MainWindow::on_pushButton_15_clicked()
{
    son->play();
    ui->tab_pro->setModel(tab_pro.afficher_tri_nom());
}

void MainWindow::on_lineEdit_r_f_textChanged(const QString &arg1)
{
    QString q = arg1;

            if (q=="")
            {
                ui->table_four->setModel(tab_four.afficher());
            }
            else {
              ui->table_four->setModel(tab_four.afficher_rechrerche(q)) ;


            }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString q = arg1;

            if (q=="")
            {
                ui->tab_pro->setModel(tab_pro.afficher());
            }
            else {
              ui->tab_pro->setModel(tab_pro.afficher_rechrerche(q)) ;


            }
}

void MainWindow::on_pushButton_8_clicked()
{
    son->play();
    QTableView *table;
                table = ui->table_four;

                QString filters("CSV files (.csv);;All files (.*)");
                QString defaultFilter("CSV files (*.csv)");
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

void MainWindow::on_pushButton_16_clicked()
{
    son->play();
    QTableView *table;
                table = ui->tab_pro;

                QString filters("CSV files (.csv);;All files (.*)");
                QString defaultFilter("CSV files (*.csv)");
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

void MainWindow::on_pushButton_17_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notification"),tr("statistique ouvert "));
    son->play();
    stat=new statistique(this);
    stat->show();
}

void MainWindow::on_combo_currentTextChanged(const QString &arg1)
{
    QSqlQuery qry;
    QString ch=arg1;
    qry.prepare("select* from PRODUIT where ID_PRODUIT ='"+ch+"'");

    if(qry.exec()){
    while(qry.next()){
    ui->nom_modifier_2->setText(qry.value(1).toString());
    ui->quantiter_modifier->setText(qry.value(2).toString());


    }
    }
}

void MainWindow::on_pushButton_18_clicked()
{
   QString link="http://www.google.com";
   QDesktopServices::openUrl(QUrl(link));


}

void MainWindow::on_pushButton_19_clicked()
{
    mSocket->write(ui->lineEdit_2->text().toLatin1().data(),ui->lineEdit_2->text().size());
        ui->plainTextEdit->appendPlainText(ui->lineEdit_2->text());
        ui->lineEdit_2->clear();
}


