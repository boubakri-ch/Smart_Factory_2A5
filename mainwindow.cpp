#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "employe.h"
#include <QDebug>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include "departement.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Emp.afficher());
    ui->tableView_2->setModel(Dep.afficher_Dep());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{

    int id = ui->lineEdit_Acin->text().toInt();
    QString nom = ui->lineEdit_Anom->text();
    QDate dateNaissance =ui->dateEdit_A->date();

    QString prenom = ui->lineEdit_Aprenom->text();
    QString departement = ui->lineEdit_Adep->text();
    int numero = ui->lineEdit_Anumero->text().toInt();
    Employe e(id,nom,prenom,departement,dateNaissance,numero);
    bool test=e.ajouter();
    if(test)
    {
        ui->tableView->setModel(Emp.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                      QObject::tr("Employe ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget_2->setCurrentIndex(0);


    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_7_clicked()
{
    int id= ui->lineEdit_Modcin->text().toInt();
    QSqlQuery query=Emp.rechercher_id(id);
    QString nom = ui->lineEdit_Modnom->text();
    QDate dateNaissance =ui->dateEdit_M->date();
    QString prenom = ui->lineEdit_Modprenom->text();
    QString departement = ui->lineEdit_Moddep->text();
    int numero = ui->lineEdit_Modnumero->text().toInt();

     if (query.next())
 {

        bool test =Emp.modifier(id,nom,prenom,departement,dateNaissance,numero);


          if(test)
          {
                ui->tableView->setModel(Emp.afficher());//refresh
          QMessageBox::information(nullptr, QObject::tr("Modifier Employé"),
                            QObject::tr("Employé modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
          ui->stackedWidget_2->setCurrentIndex(0);


          }
         }

            else
                QMessageBox::critical(nullptr, QObject::tr("Modifier Employé"),
                            QObject::tr("Employé n'exite pas !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_8_clicked()
{   int id= ui->lineEdit_SuppCin->text().toInt();
    QSqlQuery query=Emp.rechercher_id(id);

    if (query.next())
   {
       bool test=Emp.supprimer(id);

    if(test)
    {
        ui->tableView->setModel(Emp.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                      QObject::tr("Employe supprimé.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget_2->setCurrentIndex(0);


    }
   }
      else
          QMessageBox::critical(nullptr, QObject::tr("not ok"),
                      QObject::tr("Employé n'existe pas !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_lineEdit_textChanged()
{

    if(ui->lineEdit->text()== "")
    {
        ui->tableView->setModel(Emp.afficher());
    }
    else
    {
        ui->tableView->setModel(Emp.rechercher(ui->lineEdit->text()));
    }
}

void MainWindow::on_pushButton_9_clicked()
{   QString critere=ui->comboBox->currentText();
    QString mode;
     if (ui->checkBox->checkState()==false)
{
         mode="DESC";
}
     else if(ui->checkBox_2->checkState()==false)
     {
         mode="ASC";
     }
  ui->tableView->setModel(Emp.trier(critere,mode));

}

void MainWindow::on_pushButton_10_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView->model()->rowCount();
                const int columnCount =ui->tableView->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("EMPLOYÉ")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                            "<img src='C:/Users/Maher/Desktop/resourceHumaine/logo.png' width='100' height='100'>\n"
                            "<h1>Liste des Employe </h1>"



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
            printer.setOutputFileName("employe.pdf");
            document->print(&printer);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_3->setCurrentIndex(0);

}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);

}

void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(2);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(3);
}

void MainWindow::on_pushButton_14_clicked()
{

    int idD = ui->lineEdit_AIDD->text().toInt();
    QString nomD = ui->lineEdit_AnomD->text();
    int nbE= ui->lineEdit_ANE->text().toInt();
    int salaire= ui->lineEdit_Asalaire->text().toInt();
    Departement d(idD,nomD,nbE,salaire);
    bool test=d.ajouter_Dep();
    if(test)
    {
           ui->tableView_2->setModel(Dep.afficher_Dep());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un departement"),
                      QObject::tr("Departement ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    ui->stackedWidget_3->setCurrentIndex(0);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un Departement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_16_clicked()
{
    int idD= ui->lineEdit_SuppIDD->text().toInt();
        QSqlQuery query=Dep.rechercher_idD(idD);

        if (query.next())
       {
           bool test=Dep.supprimer_Dep(idD);

        if(test)
        {
            ui->tableView_2->setModel(Dep.afficher_Dep());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("Departement supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget_3->setCurrentIndex(0);


        }
       }
          else
              QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("Departement n'existe pas !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_15_clicked()
{
    int idD= ui->lineEdit_Midep->text().toInt();
    QSqlQuery query=Dep.rechercher_idD(idD);
    QString nomD = ui->lineEdit_MnomD->text();
    int nbE = ui->lineEdit_MnbE->text().toInt();
    int salaire = ui->lineEdit_Msalaire->text().toInt();

     if (query.next())
 {

        bool test =Dep.modifier_Dep(idD,nomD,nbE,salaire);


          if(test)
          {
                ui->tableView_2->setModel(Dep.afficher_Dep());//refresh
          QMessageBox::information(nullptr, QObject::tr("Modifier Departement"),
                            QObject::tr("Departement modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
          ui->stackedWidget_3->setCurrentIndex(0);


          }
         }

            else
                QMessageBox::critical(nullptr, QObject::tr("Modifier Departement"),
                            QObject::tr("Departement n'exite pas !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_rechdep_textChanged()
{

    if(ui->lineEdit_rechdep->text()== "")
    {
        ui->tableView_2->setModel(Dep.afficher_Dep());
    }
    else
    {
        ui->tableView_2->setModel(Dep.rechercher_Dep(ui->lineEdit_rechdep->text()));
    }
}



void MainWindow::on_pushButton_19_clicked()
{  QString critere=ui->comboBox_3->currentText();
    QString mode;
     if (ui->checkBox_5->checkState()==false)
{
         mode="DESC";
}
     else if(ui->checkBox_6->checkState()==false)
     {
         mode="ASC";
     }
  ui->tableView->setModel(Dep.trier_Dep(critere,mode));

}


void MainWindow::on_pushButton_20_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView_2->model()->rowCount();
                const int columnCount =ui->tableView_2->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("DEPARTEMENT")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                            "<img src='C:/Users/Maher/Desktop/resourceHumaine/logo.png' width='100' height='100'>\n"
                            "<h1>Liste des Departements </h1>"



                            "<table border=1 cellspacing=0 cellpadding=2>\n";


                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_2->isColumnHidden(column)) {
                                   QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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
            printer.setOutputFileName("departement.pdf");
            document->print(&printer);
}

void MainWindow::on_pushButton_21_clicked()
{
    int row=ui->tableView->selectionModel()->currentIndex().row();
           QString id=ui->tableView->model()->index(row,0).data().toString();
           QString nom=ui->tableView->model()->index(row,1).data().toString();
           QString prenom=ui->tableView->model()->index(row,2).data().toString();
           QDate dateNaissance=ui->tableView->model()->index(row,3).data().toDate();
           QString departement=ui->tableView->model()->index(row,4).data().toString();
           QString numero=ui->tableView->model()->index(row,5).data().toString();
           if(row==-1)
           {
               QMessageBox ::information(nullptr,QObject::tr("modifier un employé"),
                                                 QObject::tr("aucune selection.\n"
                                                     "click ok to exit"),QMessageBox::Ok);
           }
           else
           {
               ui->lineEdit_Modcin->setText(id);
               ui->lineEdit_Modnom->setText(nom);
               ui->lineEdit_Modprenom->setText(prenom);
               ui->lineEdit_Modnumero->setText(numero);
               ui->lineEdit_Moddep->setText(departement);
               ui->dateEdit_M->setDate(dateNaissance);


           }

}

void MainWindow::on_pushButton_22_clicked()
{
    int row=ui->tableView_2->selectionModel()->currentIndex().row();
           QString idD=ui->tableView_2->model()->index(row,0).data().toString();
           QString nomD=ui->tableView_2->model()->index(row,1).data().toString();
           QString nbE=ui->tableView_2->model()->index(row,2).data().toString();
           QString salaire=ui->tableView_2->model()->index(row,3).data().toString();
           if(row==-1)
           {
               QMessageBox ::information(nullptr,QObject::tr("modifier un département"),
                                                 QObject::tr("aucune selection.\n"
                                                     "click ok to exit"),QMessageBox::Ok);
           }
           else
           {
               ui->lineEdit_Midep->setText(idD);
               ui->lineEdit_MnomD->setText(nomD);
               ui->lineEdit_MnbE->setText(nbE);
               ui->lineEdit_Msalaire->setText(salaire);


           }

}
