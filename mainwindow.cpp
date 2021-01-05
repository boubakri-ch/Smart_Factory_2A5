#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDate>
#include<QDateTime>
#include<QDesktopServices>
#include<QSqlQuery>
#include <QMessageBox>
#include <QTabWidget>
#include <QString>
#include <QTextDocument>
#include <QPainter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>
#include<QPropertyAnimation>
#include<QEasingCurve>
#include<QParallelAnimationGroup>
#include<QGraphicsOpacityEffect>
#include <QRegExpValidator>
#include <QSystemTrayIcon>
#include <QDesktopServices>
#include <QUrl>
#include <QSound>
#include <QtMultimedia>
#include <QWidget>
#include <QMediaPlayer>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSystemTrayIcon= new QSystemTrayIcon(this);
       //mSystemTrayIcon->setIcon(QIcon(":/photo/my.png"));
       mSystemTrayIcon->setVisible(true);
    ui->tableView_categorie_aff->setModel(tempCategorie.afficher());
    ui->tableView_produit_aff->setModel(tempProduit.afficherp());
    ui->tableView_fournisseur_aff->setModel(tempFournisseur.afficher_fournisseur());
    ui->tableView_matiere_aff->setModel(tempMatierep.afficher_matiere_premiere());
    ui->tableView_formateur_aff->setModel(tempFormateur.afficher0());
    ui->tableView_formation_aff->setModel(tempFormation.afficher0());
    ui->tableView_materiel_aff->setModel(tempMateriel.afficher());
    ui->tableView_intervention_aff->setModel(tempIntervention.afficher());
    ui->tableView_client_aff->setModel(tempClient.afficher());
    ui->tableView_coli_aff->setModel(tempColi.afficherp());
    ui->tableView_employe_aff->setModel(tempEmploye.afficher());
    ui->tableView_departement_aff->setModel(tempDep.afficher_Dep());
    ui->id_categorie_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->id_produit_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->id_fournisseur_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->id_matiere_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->code_formation_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->cin_formateur_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->id_intervention_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->id_materiel_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->id_coli_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->cin_client_ajout->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_Acin->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_AIDD->setValidator(new QIntValidator(0,99999999,this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rh_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notification"),tr("vous etes dans le service de ressource humaines "));
        QMediaPlayer *player = new QMediaPlayer;
                player->setMedia(QUrl::fromLocalFile("C:/Users/Maher/Desktop/Smart_Factory_2A5/button-09.mp3"));
                player->setVolume(50);
                player->play();
    ui->stackedWidget->setCurrentIndex(0);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);



}

void MainWindow::on_employe_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget_4->setCurrentIndex(0);

}




void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_3->setCurrentIndex(0);

}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);


}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);


}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(3);


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

void MainWindow::on_pushButton_3_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notification"),tr("vous etes dans le service de gestion de stock "));
        QMediaPlayer *player = new QMediaPlayer;
                player->setMedia(QUrl::fromLocalFile("C:/Users/Maher/Desktop/Smart_Factory_2A5/button-09.mp3"));
                player->setVolume(50);
                player->play();
    ui->stackedWidget->setCurrentIndex(2);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);


}

void MainWindow::on_employe_2_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
    ui->stackedWidget_6->setCurrentIndex(0);

}

void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(1);
    ui->stackedWidget_7->setCurrentIndex(0);

}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(1);


}

void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);


}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(3);



}

void MainWindow::on_pushButton_38_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(1);


}

void MainWindow::on_pushButton_37_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(2);

}

void MainWindow::on_pushButton_39_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(3);


}

void MainWindow::on_employe_3_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
    ui->stackedWidget_10->setCurrentIndex(0);

}

void MainWindow::on_pushButton_46_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(0);
    ui->stackedWidget_9->setCurrentIndex(0);

}

void MainWindow::on_pushButton_57_clicked()
{
    ui->stackedWidget_10->setCurrentIndex(1);


}

void MainWindow::on_pushButton_56_clicked()
{
    ui->stackedWidget_10->setCurrentIndex(2);

}

void MainWindow::on_pushButton_58_clicked()
{
    ui->stackedWidget_10->setCurrentIndex(3);



}

void MainWindow::on_pushButton_47_clicked()
{
    ui->stackedWidget_9->setCurrentIndex(1);



}

void MainWindow::on_pushButton_48_clicked()
{
    ui->stackedWidget_9->setCurrentIndex(2);



}

void MainWindow::on_pushButton_49_clicked()
{
    ui->stackedWidget_9->setCurrentIndex(3);



}

void MainWindow::on_pushButton_2_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notification"),tr("vous etes dans le service de fournisseurs et matiéres premiéres "));
        QMediaPlayer *player = new QMediaPlayer;
                player->setMedia(QUrl::fromLocalFile("C:/Users/Maher/Desktop/Smart_Factory_2A5/button-09.mp3"));
                player->setVolume(50);
                player->play();
    ui->stackedWidget->setCurrentIndex(3);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);


}

void MainWindow::on_employe_4_clicked()
{
  ui->stackedWidget_11->setCurrentIndex(0);
  ui->stackedWidget_12->setCurrentIndex(0);

}

void MainWindow::on_pushButton_65_clicked()
{
    ui->stackedWidget_11->setCurrentIndex(1);
    ui->stackedWidget_13->setCurrentIndex(0);


}

void MainWindow::on_pushButton_66_clicked()
{
    ui->stackedWidget_12->setCurrentIndex(1);


}

void MainWindow::on_pushButton_67_clicked()
{
    ui->stackedWidget_12->setCurrentIndex(2);



}

void MainWindow::on_pushButton_68_clicked()
{
    ui->stackedWidget_12->setCurrentIndex(3);


}

void MainWindow::on_pushButton_76_clicked()
{
    ui->stackedWidget_13->setCurrentIndex(1);


}

void MainWindow::on_pushButton_75_clicked()
{
    ui->stackedWidget_13->setCurrentIndex(2);


}

void MainWindow::on_pushButton_77_clicked()
{
    ui->stackedWidget_13->setCurrentIndex(3);


}

void MainWindow::on_pushButton_4_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notification"),tr("vous etes dans le service de gestion de formations "));
        QMediaPlayer *player = new QMediaPlayer;
                player->setMedia(QUrl::fromLocalFile("C:/Users/Maher/Desktop/Smart_Factory_2A5/button-09.mp3"));
                player->setVolume(50);
                player->play();
    ui->stackedWidget->setCurrentIndex(4);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);


}

void MainWindow::on_employe_5_clicked()
{
    ui->stackedWidget_14->setCurrentIndex(0);
    ui->stackedWidget_15->setCurrentIndex(0);

}

void MainWindow::on_pushButton_84_clicked()
{
    ui->stackedWidget_14->setCurrentIndex(1);
    ui->stackedWidget_16->setCurrentIndex(0);

}

void MainWindow::on_pushButton_85_clicked()
{
    ui->stackedWidget_15->setCurrentIndex(1);


}

void MainWindow::on_pushButton_86_clicked()
{
    ui->stackedWidget_15->setCurrentIndex(2);


}

void MainWindow::on_pushButton_87_clicked()
{
    ui->stackedWidget_15->setCurrentIndex(3);

}

void MainWindow::on_pushButton_95_clicked()
{
    ui->stackedWidget_16->setCurrentIndex(1);

}

void MainWindow::on_pushButton_94_clicked()
{
    ui->stackedWidget_16->setCurrentIndex(2);



}

void MainWindow::on_pushButton_96_clicked()
{
    ui->stackedWidget_16->setCurrentIndex(3);


}

void MainWindow::on_pushButton_5_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notification"),tr("vous etes dans le service de gestion des equipements et interventions "));
        QMediaPlayer *player = new QMediaPlayer;
                player->setMedia(QUrl::fromLocalFile("C:/Users/Maher/Desktop/Smart_Factory_2A5/button-09.mp3"));
                player->setVolume(50);
                player->play();
    ui->stackedWidget->setCurrentIndex(5);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);


}

void MainWindow::on_employe_6_clicked()
{
    ui->stackedWidget_17->setCurrentIndex(0);
    ui->stackedWidget_18->setCurrentIndex(0);

}

void MainWindow::on_pushButton_103_clicked()
{
    ui->stackedWidget_17->setCurrentIndex(1);
    ui->stackedWidget_19->setCurrentIndex(0);

}

void MainWindow::on_pushButton_104_clicked()
{
    ui->stackedWidget_18->setCurrentIndex(1);

}

void MainWindow::on_pushButton_105_clicked()
{
    ui->stackedWidget_18->setCurrentIndex(2);


}

void MainWindow::on_pushButton_106_clicked()
{
    ui->stackedWidget_18->setCurrentIndex(3);



}

void MainWindow::on_pushButton_114_clicked()
{
    ui->stackedWidget_19->setCurrentIndex(1);


}

void MainWindow::on_pushButton_113_clicked()
{
    ui->stackedWidget_19->setCurrentIndex(2);



}

void MainWindow::on_pushButton_115_clicked()
{
    ui->stackedWidget_19->setCurrentIndex(3);


}

void MainWindow::on_pushButton_6_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notification"),tr("vous etes dans le service de client"));
        QMediaPlayer *player = new QMediaPlayer;
                player->setMedia(QUrl::fromLocalFile("C:/Users/Maher/Desktop/Smart_Factory_2A5/button-09.mp3"));
                player->setVolume(50);
                player->play();
    ui->stackedWidget->setCurrentIndex(6);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);


}

void MainWindow::on_pushButton_122_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);


}

void MainWindow::on_pushButton_123_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);

}

void MainWindow::on_pushButton_124_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);

}

void MainWindow::on_pushButton_125_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);

}

void MainWindow::on_pushButton_126_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);

}

void MainWindow::on_pushButton_127_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(350);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);

}




void MainWindow::on_pushButton_connecter_clicked()
{
    QString identifiant=ui->lineEdit_identifiant_c->text();
    QString mdp=ui->lineEdit_motdepasse_c->text();
    QSqlQuery query=l.verifierutilisateur(mdp);
    if(query.next())
    {
        QMessageBox::information(nullptr, QObject::tr("verifier existance"),
                                 QObject::tr("ça existe.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_identifiant_c->clear();
        ui->lineEdit_motdepasse_c->clear();
        ui->stackedWidget->setCurrentIndex(1);
    }
        else
            QMessageBox::critical(nullptr, QObject::tr("verifier existance"),
                                     QObject::tr("verifiez votre mot de passe ou votre identifiant.\n""Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_comfirmer_clicked()
{
    QString identifiant=ui->lineEdit_identifiant_cc->text();
    QString mdp=ui->lineEdit_motdepasse_cc->text();
    login e(identifiant,mdp);
    bool test=e.ajouterutilisateur();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_identifiant_cc->clear();
        ui->lineEdit_motdepasse_cc->clear();
    }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                     QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_sinscrire_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_ajout_categorie_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *query=new QSqlQuery();
        int ide=ui->id_categorie_ajout->text().toInt();
        QString nome=ui->nom_categorie_ajout->text();
        QString type=ui->type_categorie_ajout->text();
        h.save("id de la categorie : "+ui->id_categorie_ajout->text(),"nom de la categorie :"+ui->nom_categorie_ajout->text());
        categorie e(ide,nome,type);
        bool test=e.ajouter();
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                     QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
            mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout de la categorie avec success "));
            ui->tableView_categorie_aff->setModel(tempCategorie.afficher());
            ui->id_categorie_ajout->clear();
            ui->nom_categorie_ajout->clear();
            ui->type_categorie_ajout->clear();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                     QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

        query->prepare("select ID from categorie");
        query->exec();
        model->setQuery(*query);
        ui->liste_produit_a->setModel(model);
        ui->liste_produit_m->setModel(model);
}


void MainWindow::on_suppression_categorie_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *query=new QSqlQuery();
        int ide=ui->id_categorie_supprim->text().toInt();
        bool test=tempCategorie.supprimer(ide);
        if(test){
            QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                     QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_categorie_aff->setModel(tempCategorie.afficher());
            ui->id_categorie_supprim->clear();

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                     QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
        query->prepare("select ID from categorie");
        query->exec();
        model->setQuery(*query);
        ui->liste_produit_a->setModel(model);
        ui->liste_produit_m->setModel(model);
}

void MainWindow::on_modification_categorie_clicked()
{
    tempCategorie.setID(ui->id_categorie_mod->text().toInt());
            tempCategorie.setNOM(ui->nom_categorie_mod->text());
            tempCategorie.setType(ui->type_categorie_mod->text());

            if(tempCategorie.modifier())
            {
                QMessageBox::information(nullptr, QObject::tr("modification etudiant"),
                                         QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_categorie_aff->setModel(tempCategorie.afficher());
                ui->id_categorie_mod->clear();
                ui->nom_categorie_mod->clear();
                ui->type_categorie_mod->clear();
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("modification etudiant"),
                                         QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherche_categorie_textChanged(const QString &arg1)
{
    QString c = ui->recherche_categorie->text();
            ui->tableView_categorie_aff->setModel(tempCategorie.rechercher_dynamique(c));
}

void MainWindow::on_tri_alphabetique_categorie_clicked()
{

    ui->tableView_categorie_aff->setModel(tempCategorie.afficher_tri_alphabetique_categorie());
}

void MainWindow::on_tri_desc_id_categorie_clicked()
{

    ui->tableView_categorie_aff->setModel(tempCategorie.afficher_tri_descendant_categorie());
}

void MainWindow::on_tri_asc_id_categorie_clicked()
{
    ui->tableView_categorie_aff->setModel(tempCategorie.afficher_tri_identifiant_categorie());
}

void MainWindow::on_pdf_categorie_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_categorie_aff->model()->rowCount();
                            const int columnCount =ui->tableView_categorie_aff->model()->columnCount();

                            out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("CATEGORIE")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                        "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                        "<h1>liste des categories </h1>"



                                        "<table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                                out << "<thead><tr bgcolor=#f0f0f0>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView_categorie_aff->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_categorie_aff->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";
                                // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_categorie_aff->isColumnHidden(column)) {
                                               QString data = ui->tableView_categorie_aff->model()->data(ui->tableView_categorie_aff->model()->index(row, column)).toString().simplified();
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
                        printer.setOutputFileName("categories.pdf");
                        document->print(&printer);
                        QDesktopServices::openUrl(QUrl::fromLocalFile("categories.pdf"));
}

void MainWindow::on_ajouter_produit_clicked()
{
    int idp=ui->id_produit_ajout->text().toInt();
           QString nomp=ui->nom_produit_ajout->text();
           int quantity=ui->quantity_produit_ajout->text().toInt();
            int prix=ui->prix_produit_ajout->text().toInt();
            int idc=ui->liste_produit_a->currentText().toInt();
            h.save("id du produit : "+ui->id_produit_ajout->text(),"nom du produit :"+ui->nom_produit_ajout->text());

           produit p(idp,nomp,quantity,prix,idc);
           bool test=p.ajouterP();
           if(test)
           {
               QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                        QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
               mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout du produit avec success "));
               ui->tableView_produit_aff->setModel(tempProduit.afficherp());
               ui->id_produit_ajout->clear();
               ui->nom_produit_ajout->clear();
               ui->quantity_produit_ajout->clear();
               ui->prix_produit_ajout->clear();
           }
           //else
               QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                        QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supp_produit_clicked()
{
    int ide=ui->id_produit_supp->text().toInt();
           bool test=tempProduit.supprimerp(ide);
           if(test){
               QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                        QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
               ui->tableView_produit_aff->setModel(tempProduit.afficherp());
               ui->id_produit_supp->clear();

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                        QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_modifier_produit_clicked()
{
    tempProduit.setIDP(ui->id_produit_mod->text().toInt());
            tempProduit.setNOMP(ui->nom_produit_mod->text());
            tempProduit.setQuantity(ui->quantity_produit_mod->text().toInt());
            tempProduit.setPrix(ui->prix_produit_mod->text().toInt());
            tempProduit.setIDC(ui->liste_produit_m->currentText().toInt());


            if(tempProduit.modifierp())
            {
                QMessageBox::information(nullptr, QObject::tr("modification produit"),
                                         QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_produit_aff->setModel(tempProduit.afficherp());
                ui->id_produit_mod->clear();
                ui->nom_produit_mod->clear();
                ui->quantity_produit_mod->clear();
                ui->prix_produit_mod->clear();
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("modification produit"),
                                         QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_produit_rech_dynamique_textChanged(const QString &arg1)
{
    QString c = ui->produit_rech_dynamique->text();
           ui->tableView_produit_aff->setModel(tempProduit.rechercher_dynamique_produit(c));
}


void MainWindow::on_tri_produit_prix_clicked()
{
    ui->tableView_produit_aff->setModel(tempProduit.afficherp_tri_prix());
}

void MainWindow::on_tri_produit_identifiant_clicked()
{
    ui->tableView_produit_aff->setModel(tempProduit.afficherp_tri_identifiant());
}

void MainWindow::on_tri_produit_quantity_clicked()
{
    ui->tableView_produit_aff->setModel(tempProduit.afficherp_tri_quantity());
}


void MainWindow::on_pdf_produit_clicked()
{ QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView_produit_aff->model()->rowCount();
    const int columnCount =ui->tableView_produit_aff->model()->columnCount();

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("PRODUIT")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
                "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                "<h1>liste des produits </h1>"



                "<table border=1 cellspacing=0 cellpadding=2>\n";


    // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_produit_aff->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_produit_aff->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
           for (int row = 0; row < rowCount; row++) {
               out << "<tr>";
               for (int column = 0; column < columnCount; column++) {
                   if (!ui->tableView_produit_aff->isColumnHidden(column)) {
                       QString data = ui->tableView_produit_aff->model()->data(ui->tableView_produit_aff->model()->index(row, column)).toString().simplified();
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
printer.setOutputFileName("produits.pdf");
document->print(&printer);
QDesktopServices::openUrl(QUrl::fromLocalFile("produits.pdf"));

}

void MainWindow::on_statcp_clicked()
{
    stata=new statadem(this);
            stata->show();
}

void MainWindow::on_ajout_fournisseur_clicked()
{
    int id=ui->id_fournisseur_ajout->text().toInt();
                QString Num=ui->numtel_fournisseur_ajout->text();
                 QString RIB=ui->RIB_fournisseur_ajout->text();
               QString nom=ui->nom_fournisseur_ajout->text();
                QString prenom=ui->prenom_fournisseur_ajout->text();
                hf.savef("id du fournisseur :"+ui->id_fournisseur_ajout->text(),"nom du fournisseur :"+ui->nom_fournisseur_ajout->text());
                fournisseur F(nom,prenom,id,Num,RIB);
                bool test=F.ajouter();


                if(test)
                {
                 ui->tableView_fournisseur_aff->setModel(tempFournisseur.afficher_fournisseur());
                    QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                                           QObject::tr("fournisseur ajoutée.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
                    mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout fournisseur avec success "));
                    ui->id_fournisseur_ajout->clear();
                    ui->numtel_fournisseur_ajout->clear();
                    ui->RIB_fournisseur_ajout->clear();
                    ui->nom_fournisseur_ajout->clear();
                    ui->prenom_fournisseur_ajout->clear();
                }
                QSqlQueryModel *model= new QSqlQueryModel();
                QSqlQuery *query=new QSqlQuery();
                query->prepare("select ID_FOURNISSEUR from fournisseur");
                query->exec();
                model->setQuery(*query);
                ui->list_fournisseur_1->setModel(model);
                ui->list_fournisseur_2->setModel(model);
}

void MainWindow::on_modifier_fournisseur_clicked()
{
    int id=ui->id_fournisseur_mod->text().toInt();
               QString nom=ui->nom_fournisseur_mod->text();
                QString prenom=ui->prenom_fournisseur_mod->text();
               QString RIB=ui->RIB_fournisseur_mod->text();
                QString Num=ui->numtel_fournisseur_mod->text();
                fournisseur F(nom,prenom,id,Num,RIB);
                bool test=F.modifier();
                if(test)
                {
            ui->tableView_fournisseur_aff->setModel(tempFournisseur.afficher_fournisseur());
                    QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                                           QObject::tr("fournisseur modifier.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
                }
}

void MainWindow::on_fournisseur_supp_clicked()
{
    QString id=ui->id_fournisseur_supp->text();
               bool test=tempFournisseur.supprimer(id);
               if(test)
               {
                   ui->tableView_fournisseur_aff->setModel(tempFournisseur.afficher_fournisseur());
                           QMessageBox::information(nullptr, QObject::tr("suprrimer un fournisseur"),
                                                  QObject::tr("fournisseur supprimer.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);
                   ui->id_fournisseur_supp->clear();
               }
}


void MainWindow::on_tri_id_fournisseur_clicked()
{
    ui->tableView_fournisseur_aff->setModel(tempFournisseur.tri_fournisseur());
}

void MainWindow::on_tri_rib_desc_clicked()
{
    ui->tableView_fournisseur_aff->setModel(tempFournisseur.tri_fournisseur_RIB_desc());
}

void MainWindow::on_tri_nom_fournisseur_clicked()
{
    ui->tableView_fournisseur_aff->setModel(tempFournisseur.tri_fournisseur_nom());
}

void MainWindow::on_pdf_fournisseur_clicked()
{

    QString strStream;
                        QTextStream out(&strStream);
                        const int rowCount = ui->tableView_fournisseur_aff->model()->rowCount();
                        const int columnCount =ui->tableView_fournisseur_aff->model()->columnCount();

                        out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                <<  "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                    "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                    "<h1>liste des fournisseurs </h1>"



                                    "<table border=1 cellspacing=0 cellpadding=2>\n";


                        // headers
                            out << "<thead><tr bgcolor=#f0f0f0>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView_fournisseur_aff->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView_fournisseur_aff->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";
                            // data table
                               for (int row = 0; row < rowCount; row++) {
                                   out << "<tr>";
                                   for (int column = 0; column < columnCount; column++) {
                                       if (!ui->tableView_fournisseur_aff->isColumnHidden(column)) {
                                           QString data = ui->tableView_fournisseur_aff->model()->data(ui->tableView_fournisseur_aff->model()->index(row, column)).toString().simplified();
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
                    printer.setOutputFileName("fournisseurs.pdf");
                    document->print(&printer);
                    QDesktopServices::openUrl(QUrl::fromLocalFile("fournisseurs.pdf"));
}


void MainWindow::on_lineEdit_rechereche_fournisseur_textChanged(const QString &arg1)
{
    QString c = ui->lineEdit_rechereche_fournisseur->text();
            ui->tableView_fournisseur_aff->setModel(tempFournisseur.rechercher_dynamique_fournisseur(c));
}


void MainWindow::on_matiere_ajout_clicked()
{
    int id=ui->id_matiere_ajout->text().toInt();
            int id_f=ui->list_fournisseur_1->currentText().toInt();
            QString quantity=ui->quantity_matiere_ajout->text();
            QString nom=ui->nom_matiere_ajout->text();
            QString date=ui->dateEdit_3->date().toString("dd-MM-yyyy");
            hf.savef("id de la matiere premiere :"+ui->id_matiere_ajout->text(),"nom de la matiere :"+ui->nom_matiere_ajout->text());
            matierepremiere m(nom,date,quantity,id,id_f);
            bool test=m.ajouter_matiere_premiere();
            if(test)
            {
                ui->tableView_matiere_aff->setModel(tempMatierep.afficher_matiere_premiere());
                QMessageBox::information(nullptr, QObject::tr("ajout matiere premiere"),
                                          QObject::tr("ajout avec succes .\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout matiere premiere avec success "));
            }
            else
                QMessageBox::information(nullptr, QObject::tr("ajout matiere premiere"),
                                          QObject::tr("echec .\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_matierep_clicked()
{
    QString id=ui->id_matierep_supp->text();
            bool test=tempMatierep.supprimer_matiere_premiere(id);
            if(test)
            {
                ui->tableView_matiere_aff->setModel(tempMatierep.afficher_matiere_premiere());
            }
}


void MainWindow::on_modifier_matierep_clicked()
{
    int id=ui->id_matiere_mod->text().toInt();
            int id_f=ui->list_fournisseur_2->currentText().toInt();
            QString date=ui->dateEdit_4->text();
            QString nom=ui->nom_matiere_mod->text();
            QString quantiter=ui->quantity_matiere_mod->text();
            matierepremiere p(nom,date,quantiter,id,id_f);
            bool test=p.modifier_matiere_premiere();
            if(test)
            {
                ui->tableView_matiere_aff->setModel(tempMatierep.afficher_matiere_premiere());
            }
}


void MainWindow::on_tri_matierep_id_clicked()
{
     ui->tableView_matiere_aff->setModel(tempMatierep.tri_selon_id());
}


void MainWindow::on_tri_matierep_quantit_clicked()
{
    ui->tableView_matiere_aff->setModel(tempMatierep.tri_selon_quantity());
}

void MainWindow::on_trimp_clicked()
{
    ui->tableView_matiere_aff->setModel(tempMatierep.tri_selon_nom());
}


void MainWindow::on_pdf_matierep_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_matiere_aff->model()->rowCount();
                            const int columnCount =ui->tableView_matiere_aff->model()->columnCount();

                            out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                        "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                        "<h1>liste des matieres premieres </h1>"



                                        "<table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                                out << "<thead><tr bgcolor=#f0f0f0>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView_matiere_aff->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_matiere_aff->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";
                                // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_matiere_aff->isColumnHidden(column)) {
                                               QString data = ui->tableView_matiere_aff->model()->data(ui->tableView_matiere_aff->model()->index(row, column)).toString().simplified();
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
                        printer.setOutputFileName("matieres premieres.pdf");
                        document->print(&printer);
                        QDesktopServices::openUrl(QUrl::fromLocalFile("matieres premieres.pdf"));
}

void MainWindow::on_recherche_matierep_textChanged(const QString &arg1)
{
    QString c = ui->recherche_matierep->text();
           ui->tableView_matiere_aff->setModel(tempMatierep.rechercher_dynamique_id_matiere(c));
}

void MainWindow::on_stat_chiheb_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notification"),tr("statistique ouvert "));
        stat=new statistique(this);
            stat->show();
}

void MainWindow::on_google_clicked()
{QString link="http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));

}

void MainWindow::on_excel_matiere_prem_clicked()
{
    /*QTableView *table;
                        table = ui->tableView_matiere_aff;

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
                        }*/
        QTableView *table;

                        table = ui->tableView_matiere_aff;


                        QString filters("Excel Files (.xls)");

                        QString defaultFilter("Excel Files (*.xls)");

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

void MainWindow::on_saida_clicked()
{
    QString link="http://www.saida-group.com/";
           QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_excel_fournisseur_clicked()
{
    QTableView *table;

                        table = ui->tableView_fournisseur_aff;


                        QString filters("Excel Files (.xls)");

                        QString defaultFilter("Excel Files (*.xls)");

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


void MainWindow::on_excel_produit_clicked()
{
    QTableView *table;

                        table = ui->tableView_produit_aff;


                        QString filters("Excel Files (.xls)");

                        QString defaultFilter("Excel Files (*.xls)");

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

void MainWindow::on_pushButton_excel_adem_clicked()
{
    QTableView *table;

                        table = ui->tableView_categorie_aff;


                        QString filters("Excel Files (.xls)");

                        QString defaultFilter("Excel Files (*.xls)");

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


void MainWindow::on_ajout_formateur_clicked()
{
    int cin=ui->cin_formateur_ajout->text().toInt();
            QString nom=ui->nom_formateur_ajout->text();
            QString domaine=ui->prenom_formateur_ajout->text();
            hm.savemalhus("cin du formateur :"+ui->cin_formateur_ajout->text(),"nom du formateur :"+ui->nom_formateur_ajout->text());
            formateur g(cin,nom,domaine);
            bool test=g.ajouter();
            if(test)
            {
                ui->tableView_formateur_aff->setModel(tempFormateur.afficher());
                QMessageBox::information(nullptr, QObject::tr("ajout formateur"),
                                          QObject::tr("ajout avec succes .\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout formateur avec success "));
                ui->cin_formateur_ajout->clear();
                ui->nom_formateur_ajout->clear();
                ui->prenom_formateur_ajout->clear();
            }
            else
                QMessageBox::information(nullptr, QObject::tr("ajout formateur"),
                                          QObject::tr("echec  .\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_modification_formateur_clicked()
{
    int cin=ui->cin_formateur_mod->text().toInt();
            QString nom=ui->nom_formateur_mod->text();
            QString domaine=ui->prenom_formateur_mod->text();
            formateur g(cin,nom,domaine);
            bool test=g.modifier(cin,nom,domaine);
            if(test)
            {
                ui->tableView_formateur_aff->setModel(tempFormateur.afficher0());
                QMessageBox::information(nullptr, QObject::tr("modification formateur"),
                                          QObject::tr("modification avec succes .\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                ui->cin_formateur_mod->clear();
                ui->nom_formateur_mod->clear();
                ui->prenom_formateur_mod->clear();
            }
            else
                QMessageBox::information(nullptr, QObject::tr("modification formateur"),
                                          QObject::tr("echec .\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_supprimer_formateur_clicked()
{
    int cin=ui->cin_formateur_supp->text().toInt();
            bool test=tempFormateur.supprimer(cin);
            if(test)
            {
                ui->tableView_formateur_aff->setModel(tempFormateur.afficher0());
                ui->cin_formateur_supp->clear();
            }
}


void MainWindow::on_tri_cin_formateur_clicked()
{
    ui->tableView_formateur_aff->setModel(tempFormateur.afficher());
}


void MainWindow::on_tri_nom_formateur_clicked()
{

    ui->tableView_formateur_aff->setModel(tempFormateur.afficher2());
}


void MainWindow::on_rei_prenom_formateur_clicked()
{
    ui->tableView_formateur_aff->setModel(tempFormateur.afficher3());
}

void MainWindow::on_recherche_formateur_textChanged(const QString &arg1)
{
    QString c = ui->recherche_formateur->text();
            ui->tableView_formateur_aff->setModel(tempFormateur.rechercher(c));
}

void MainWindow::on_generer_liste_formateur_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_formateur_aff->model()->rowCount();
                            const int columnCount =ui->tableView_formateur_aff->model()->columnCount();

                            out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                        "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                        "<h1>liste des formateurs </h1>"



                                        "<table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                                out << "<thead><tr bgcolor=#f0f0f0>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView_formateur_aff->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_formateur_aff->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";
                                // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_formateur_aff->isColumnHidden(column)) {
                                               QString data = ui->tableView_formateur_aff->model()->data(ui->tableView_formateur_aff->model()->index(row, column)).toString().simplified();
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
                        printer.setOutputFileName("formateurs.pdf");
                        document->print(&printer);
                        QDesktopServices::openUrl(QUrl::fromLocalFile("formateurs.pdf"));
}


void MainWindow::on_ajout_formation_clicked()
{
    int code=ui->code_formation_ajout->text().toInt();
            QString nom=ui->nom_formation_ajout->text();
            QString domaine=ui->domaine_formation_ajout->text();
            QString departement=ui->departement_formation_ajout->text();
            hm.savemalhus("code de la formation :"+ui->code_formation_ajout->text(),"nom de la formation :"+ui->nom_formation_ajout->text());
            formation f(code,nom,domaine,departement);
            bool test=f.ajouter();
            if(test)

            {
                 ui->tableView_formation_aff->setModel(tempFormation.afficher0());;
                QMessageBox::information(nullptr, QObject::tr("Ajout formations"),
                                         QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
                mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout formation avec success "));
                ui->code_formation_ajout->clear();
                ui->nom_formation_ajout->clear();
                ui->domaine_formation_ajout->clear();
                ui->departement_formation_ajout->clear();
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Ajout formation"),
                                         QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_supprimer_formation_clicked()
{
    int code=ui->code_formation_supp->text().toInt();
           bool test=tempFormation.supprimer(code);
           if(test)
           {
               ui->tableView_formation_aff->setModel(tempFormation.afficher0());
               ui->code_formation_supp->clear();
           }
}


void MainWindow::on_modifier_formation_clicked()
{
    int code=ui->code_formatio_mod->text().toInt();
            QString nom=ui->nom_formation_mod->text();
            QString domaine=ui->domaine_formation_mod->text();
            QString departement=ui->departement_formation_mod->text();
            formation f(code,nom,domaine,departement);
            bool test=f.modifier(code,nom,domaine,departement);
            if(test)
            {
                ui->tableView_formation_aff->setModel(tempFormation.afficher0());
                QMessageBox::information(nullptr, QObject::tr("Modifier formations"),
                                         QObject::tr("Modifier avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Modifier formation"),
                                         QObject::tr("Modification échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_recherche_formation_textChanged(const QString &arg1)
{
    QString c = ui->recherche_formation->text();
           ui->tableView_formation_aff->setModel(tempFormation.rechercher(c));
}


void MainWindow::on_tri_code_formation_clicked()
{
     ui->tableView_formation_aff->setModel(tempFormation.afficher_f_code());
}


void MainWindow::on_tri_nom_formation_clicked()
{
    ui->tableView_formation_aff->setModel(tempFormation.afficher2());
}

void MainWindow::on_tri_domaine_formation_clicked()
{
    ui->tableView_formation_aff->setModel(tempFormation.afficher3());
}

void MainWindow::on_tri_department_formation_clicked()
{
     ui->tableView_formation_aff->setModel(tempFormation.afficher4());
}

void MainWindow::on_genere_liste_formation_clicked()
{
    QString strStream;
                           QTextStream out(&strStream);
                           const int rowCount = ui->tableView_formation_aff->model()->rowCount();
                           const int columnCount =ui->tableView_formation_aff->model()->columnCount();

                           out <<  "<html>\n"
                                   "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                   <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                   <<  "</head>\n"
                                   "<body bgcolor=#ffffff link=#5000A0>\n"
                                       "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                       "<h1>liste des formations </h1>"



                                       "<table border=1 cellspacing=0 cellpadding=2>\n";


                           // headers
                               out << "<thead><tr bgcolor=#f0f0f0>";
                               for (int column = 0; column < columnCount; column++)
                                   if (!ui->tableView_formation_aff->isColumnHidden(column))
                                       out << QString("<th>%1</th>").arg(ui->tableView_formation_aff->model()->headerData(column, Qt::Horizontal).toString());
                               out << "</tr></thead>\n";
                               // data table
                                  for (int row = 0; row < rowCount; row++) {
                                      out << "<tr>";
                                      for (int column = 0; column < columnCount; column++) {
                                          if (!ui->tableView_formation_aff->isColumnHidden(column)) {
                                              QString data = ui->tableView_formation_aff->model()->data(ui->tableView_formation_aff->model()->index(row, column)).toString().simplified();
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
                       printer.setOutputFileName("formations.pdf");
                       document->print(&printer);
                       QDesktopServices::openUrl(QUrl::fromLocalFile("formations.pdf"));
}


void MainWindow::on_stat_malthus_clicked()
{
    statmalth=new statmalthus(this);
            statmalth->show();
}


void MainWindow::on_excel_ff_clicked()
{
    QTableView *table;

                        table = ui->tableView_formation_aff;


                        QString filters("Excel Files (.xls)");

                        QString defaultFilter("Excel Files (*.xls)");

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

void MainWindow::on_excel_formateur_clicked()
{
    QTableView *table;

                    table = ui->tableView_formateur_aff;


                    QString filters("Excel Files (.xls)");

                    QString defaultFilter("Excel Files (*.xls)");

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

void MainWindow::on_ajout_materiel_clicked()
{
    QString id=ui->id_materiel_ajout->text();
    int quantite_t=ui->quantity_materiel_ajout->text().toInt();

    int prix_u=ui->prix_materiel_ajout->text().toInt();
    int datefab=ui->date_materiel_ajout->text().toInt();
    QString fournisseur=ui->fournisseur_materiel_ajout->text();
hy.saveyass("id du materiel :"+ui->id_materiel_ajout->text(),"quantité du materiel :"+ui->quantity_materiel_ajout->text());

materiel E(id,quantite_t , prix_u,datefab,fournisseur);
bool test=E.ajouter();
if(test)
{
    ui->tableView_materiel_aff->setModel(tempMateriel.afficher());
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
    mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout materiel avec success "));

}
}

void MainWindow::on_modifier_materiel_clicked()
{
    materiel m;



            QString id = ui->id_materiel_mod->text();
            int quantite_t= ui->quantity_materiel_mod->text().toInt();
            int prix_u = ui->prix_materiel_mod->text().toInt();
            int datefab= ui->date_materiel_mod->text().toInt();



            QString fournisseur = ui->fournisseur_materiel_mod->text();



                materiel  (id, prix_u,quantite_t,datefab,fournisseur) ;
                bool test =m.modifier(id ,quantite_t ,prix_u,datefab,fournisseur);
                if(test)
                {ui->tableView_materiel_aff->setModel(m.afficher());
                    QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                             QObject::tr("employe  modifié.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);}
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                          QObject::tr("Erreur !.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_supprimer_materiel_clicked()
{
    QString id=ui->id_materiel_supp->text();
           bool test=tempMateriel.supprimer(id);
           if(test)
           {
               ui->tableView_materiel_aff->setModel(tempMateriel.afficher());
               ui->id_materiel_supp->clear();
           }
}

void MainWindow::on_tri_materiel_prix_clicked()
{
    ui->tableView_materiel_aff->setModel(tempMateriel.afficher_date_tri());

}

void MainWindow::on_tri_id_desc_clicked()
{
    ui->tableView_materiel_aff->setModel(tempMateriel.afficher_id_tri_desc());
}

void MainWindow::on_tri_selon_id_clicked()
{
    ui->tableView_materiel_aff->setModel(tempMateriel.afficher_id_tri());
}

void MainWindow::on_recherche_materiel_textChanged(const QString &arg1)
{
    QString c = ui->recherche_materiel->text();
            ui->tableView_materiel_aff->setModel(tempMateriel.rechercher_dynamique_materiel(c));
}


void MainWindow::on_pdf_materiel_clicked()
{
    QString strStream;
                           QTextStream out(&strStream);
                           const int rowCount = ui->tableView_materiel_aff->model()->rowCount();
                           const int columnCount =ui->tableView_materiel_aff->model()->columnCount();

                           out <<  "<html>\n"
                                   "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                   <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                   <<  "</head>\n"
                                   "<body bgcolor=#ffffff link=#5000A0>\n"
                                       "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                       "<h1>liste des materiels </h1>"



                                       "<table border=1 cellspacing=0 cellpadding=2>\n";


                           // headers
                               out << "<thead><tr bgcolor=#f0f0f0>";
                               for (int column = 0; column < columnCount; column++)
                                   if (!ui->tableView_materiel_aff->isColumnHidden(column))
                                       out << QString("<th>%1</th>").arg(ui->tableView_materiel_aff->model()->headerData(column, Qt::Horizontal).toString());
                               out << "</tr></thead>\n";
                               // data table
                                  for (int row = 0; row < rowCount; row++) {
                                      out << "<tr>";
                                      for (int column = 0; column < columnCount; column++) {
                                          if (!ui->tableView_materiel_aff->isColumnHidden(column)) {
                                              QString data = ui->tableView_materiel_aff->model()->data(ui->tableView_materiel_aff->model()->index(row, column)).toString().simplified();
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
                       printer.setOutputFileName("materiels.pdf");
                       document->print(&printer);
                       QDesktopServices::openUrl(QUrl::fromLocalFile("materiels.pdf"));
}

void MainWindow::on_ajout_intervention_clicked()
{
    QString id=ui->id_intervention_ajout->text();
           QString nom=ui->nom_intervention_ajout->text();
           QString id_employee=ui->liste_employee_intervention1->currentText();
           QString date=ui->date_intervention_ajout->text();
       hy.saveyass("id intervention :"+ui->id_intervention_ajout->text(),"nom intervention :"+ui->nom_intervention_ajout->text());

       intervention E(nom,id_employee,id,date);
       bool test=E.ajouter();
       if(test)
       {
           ui->tableView_intervention_aff->setModel(tempIntervention.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
       }
}


void MainWindow::on_modifier_intervention_clicked()
{
    tempIntervention.setNom(ui->nom_intervention_mod->text());
       tempIntervention.setIde(ui->liste_employees_intervention2->currentText());
       tempIntervention.setId(ui->id_intervention_mod->text());
       tempIntervention.setDate(ui->date_intervention_mod->text());


       if(tempIntervention.modifier())
       {
           QMessageBox::information(nullptr, QObject::tr("modification produit"),
                                    QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_intervention_aff->setModel(tempIntervention.afficher());
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("modification produit"),
                                    QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_intervention_suppression_clicked()
{
    QString ide=ui->id_intervention_supp->text();
            bool test=tempIntervention.supprimer(ide);
            if(test){
                QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                         QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_intervention_aff->setModel(tempIntervention.afficher());
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                         QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherche_intervention_textChanged(const QString &arg1)
{
    QString c = ui->recherche_intervention->text();
            ui->tableView_intervention_aff->setModel(tempIntervention.rechercher_dynamique_intervention(c));
}


void MainWindow::on_pdf_intervention_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_intervention_aff->model()->rowCount();
                            const int columnCount =ui->tableView_intervention_aff->model()->columnCount();

                            out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                        "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                        "<h1>liste des interventions </h1>"



                                        "<table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                                out << "<thead><tr bgcolor=#f0f0f0>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView_intervention_aff->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_intervention_aff->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";
                                // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_intervention_aff->isColumnHidden(column)) {
                                               QString data = ui->tableView_materiel_aff->model()->data(ui->tableView_intervention_aff->model()->index(row, column)).toString().simplified();
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
                        printer.setOutputFileName("interventions.pdf");
                        document->print(&printer);
                        QDesktopServices::openUrl(QUrl::fromLocalFile("interventions.pdf"));
}


void MainWindow::on_tri_nom_clicked()
{
    ui->tableView_intervention_aff->setModel(tempIntervention.afficher_tri_nom());
}


void MainWindow::on_tri_nom_desc_clicked()
{
     ui->tableView_intervention_aff->setModel(tempIntervention.afficher_tri_nom_desc());
}


void MainWindow::on_stat_yassine_clicked()
{
    statyass=new statyassine(this);
            statyass->show();
}


void MainWindow::on_excel_intervention_clicked()
{
    QTableView *table;

                        table = ui->tableView_intervention_aff;


                        QString filters("Excel Files (.xls)");

                        QString defaultFilter("Excel Files (*.xls)");

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


void MainWindow::on_excel_materiel_clicked()
{
    QTableView *table;

                       table = ui->tableView_materiel_aff;


                       QString filters("Excel Files (.xls)");

                       QString defaultFilter("Excel Files (*.xls)");

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

void MainWindow::on_ajout_client_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
            QSqlQuery *query=new QSqlQuery();
            int ide=ui->cin_client_ajout->text().toInt();
            QString nome=ui->nom_client_ajout->text();
            QString prenom=ui->prenom_client_ajout->text();
            QString localisation=ui->localisation_client_ajout->text();
            hyou.saveyou("cin du client :"+ui->cin_client_ajout->text(),"nom du client :"+ui->nom_client_ajout->text());
            client e(ide,nome,prenom,localisation);
            bool test=e.ajouter();
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                         QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_client_aff->setModel(tempClient.afficher());
                ui->cin_client_ajout->clear();
                ui->nom_client_ajout->clear();
                ui->prenom_client_ajout->clear();
                ui->localisation_client_ajout->clear();
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                         QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

            query->prepare("select cin_client from client");
            query->exec();
            model->setQuery(*query);
            ui->liste_client1->setModel(model);
            ui->list_cliient_mod->setModel(model);
}


void MainWindow::on_supprimer_client_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
            QSqlQuery *query=new QSqlQuery();
            int ide=ui->cin_client_supp->text().toInt();
            bool test=tempClient.supprimer(ide);
            if(test){
                QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                         QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_client_aff->setModel(tempClient.afficher());
                ui->cin_client_supp->clear();

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                         QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
            query->prepare("select cin_client from client");
            query->exec();
            model->setQuery(*query);
            ui->liste_client1->setModel(model);
            ui->list_cliient_mod->setModel(model);
}


void MainWindow::on_modifier_client_clicked()
{
    tempClient.setCin(ui->cin_client_mod->text().toInt());
            tempClient.setNOMc(ui->nom_client_mod->text());
            tempClient.setPrenomc(ui->prenom_client_mod->text());
            tempClient.setlocalisation(ui->localisation_client_mod->text());

            if(tempClient.modifier())
            {
                QMessageBox::information(nullptr, QObject::tr("modification etudiant"),
                                         QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_client_aff->setModel(tempClient.afficher());
                ui->cin_client_mod->clear();
                ui->nom_client_mod->clear();
                ui->prenom_client_mod->clear();
                ui->localisation_client_mod->clear();
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("modification etudiant"),
                                         QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_recherche_client_textChanged(const QString &arg1)
{
    QString c = ui->recherche_client->text();
           ui->tableView_client_aff->setModel(tempClient.rechercher_dynamique(c));
}


void MainWindow::on_client_pdf_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_client_aff->model()->rowCount();
                            const int columnCount =ui->tableView_client_aff->model()->columnCount();

                            out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                        "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                        "<h1>liste des clients </h1>"



                                        "<table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                                out << "<thead><tr bgcolor=#f0f0f0>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView_client_aff->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_client_aff->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";
                                // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_client_aff->isColumnHidden(column)) {
                                               QString data = ui->tableView_client_aff->model()->data(ui->tableView_client_aff->model()->index(row, column)).toString().simplified();
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
                        printer.setOutputFileName("clients.pdf");
                        document->print(&printer);
                        QDesktopServices::openUrl(QUrl::fromLocalFile("clients.pdf"));
}


void MainWindow::on_tri_client_cin_clicked()
{
    ui->tableView_client_aff->setModel(tempClient.afficher_tri_cin());
}


void MainWindow::on_tri_client_nom_clicked()
{
    ui->tableView_client_aff->setModel(tempClient.afficher_tri_nom());
}


void MainWindow::on_tri_client_prenom_clicked()
{
    ui->tableView_client_aff->setModel(tempClient.afficher_tri_prenom());
}

void MainWindow::on_ajouter_coli_clicked()
{
    int idcoli=ui->id_coli_ajout->text().toInt();
         QString adresse=ui->adresse_coli_ajout->text();
         QString type=ui->type_coli_ajout->text();
         int poids=ui->poids_coli_ajout->text().toInt();
          int prix=ui->prix_coli_ajout->text().toInt();
          int idc=ui->liste_client1->currentText().toInt();
         hyou.saveyou("id du coli :"+ui->id_coli_ajout->text(),"type du coli :"+ui->type_coli_ajout->text());
         coli p(idcoli,adresse,type,poids,prix,idc);
         bool test=p.ajouterP();
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("Ajout etudiant"),
                                      QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
             ui->tableView_coli_aff->setModel(tempColi.afficherp());

         }
         //else
             QMessageBox::critical(nullptr, QObject::tr("Ajout etudiant"),
                                      QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_coli_supp_clicked()
{
    int ide=ui->id_coli_supp->text().toInt();
           bool test=tempColi.supprimerp(ide);
           if(test){
               QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                        QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
               ui->tableView_coli_aff->setModel(tempColi.afficherp());
               ui->id_coli_supp->clear();

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                        QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_modifier_coli_clicked()
{
    tempColi.setIDCOLI(ui->id_coli_mod->text().toInt());
        tempColi.setAdressed(ui->adresse_coli_mod->text());
        tempColi.setTYPE(ui->type_coli_mod->text());
        tempColi.setPOIDS(ui->poids_coli_mod->text().toInt());
        tempColi.setPrix(ui->prix_coli_mod->text().toInt());
        tempColi.setCINCLIENT(ui->list_cliient_mod->currentText().toInt());

        if(tempColi.modifierp())
        {
            QMessageBox::information(nullptr, QObject::tr("modification produit"),
                                     QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_coli_aff->setModel(tempColi.afficherp());

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modification produit"),
                                     QObject::tr("modification échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_recherche_coli_textChanged(const QString &arg1)
{
    QString c = ui->recherche_coli->text();
           ui->tableView_coli_aff->setModel(tempColi.rechercher_dynamique_produit(c));
}


void MainWindow::on_pdf_coli_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_coli_aff->model()->rowCount();
                            const int columnCount =ui->tableView_coli_aff->model()->columnCount();

                            out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                        "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                        "<h1>liste des colis </h1>"



                                        "<table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                                out << "<thead><tr bgcolor=#f0f0f0>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView_coli_aff->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_coli_aff->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";
                                // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_coli_aff->isColumnHidden(column)) {
                                               QString data = ui->tableView_coli_aff->model()->data(ui->tableView_coli_aff->model()->index(row, column)).toString().simplified();
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
                        printer.setOutputFileName("colis.pdf");
                        document->print(&printer);
                        QDesktopServices::openUrl(QUrl::fromLocalFile("colis.pdf"));
}


void MainWindow::on_tri_prix_coli_clicked()
{
    ui->tableView_coli_aff->setModel(tempColi.afficherp_tri_prix());
}

void MainWindow::on_tri_coli_poids_clicked()
{
    ui->tableView_coli_aff->setModel(tempColi.afficherp_tri_poids());
}


void MainWindow::on_tri_colitype_clicked()
{
    ui->tableView_coli_aff->setModel(tempColi.afficherp_tri_type());
}


void MainWindow::on_stat_tatar_clicked()
{
    statt=new stattatar(this);
           statt->show();
}

void MainWindow::on_pushButton_excel_coli_clicked()
{
    QTableView *table;

                        table = ui->tableView_coli_aff;


                        QString filters("Excel Files (.xls)");

                        QString defaultFilter("Excel Files (*.xls)");

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

                                        strList.append("\"   " + model->data(model->index(i, j)).toString() + "\"");

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


void MainWindow::on_excel_client_clicked()
{

    QTableView *table;

                    table = ui->tableView_client_aff;


                    QString filters("Excel Files (.xls)");

                    QString defaultFilter("Excel Files (*.xls)");

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


void MainWindow::on_ajout_un_employ_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          QSqlQuery *query=new QSqlQuery();
      int id = ui->lineEdit_Acin->text().toInt();
          QString nom = ui->lineEdit_Anom->text();
          QString dateNaissance =ui->dateEdit_A->text();

          QString prenom = ui->lineEdit_Aprenom->text();
          QString departement = ui->lineEdit_Adep->text();
          int numero = ui->lineEdit_Anumero->text().toInt();
          hmaher.savemaher("cin employe :"+ui->lineEdit_Acin->text(),"nom employe :"+ui->lineEdit_Anom->text());
          employe e(id,nom,prenom,departement,dateNaissance,numero);
          bool test=e.ajouter();
          if(test)
          {
              ui->tableView_employe_aff->setModel(tempEmploye.afficher());
          QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                            QObject::tr("Employe ajouté.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
          ui->stackedWidget_4->setCurrentIndex(0);
          }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
          query->prepare("select CIN from EMPLOYÉ");
          query->exec();
          model->setQuery(*query);
          ui->liste_employees_intervention2->setModel(model);
          ui->liste_employee_intervention1->setModel(model);
}


void MainWindow::on_mod_employe_clicked()
{
    int id= ui->lineEdit_Modcin->text().toInt();
            QSqlQuery query=tempEmploye.rechercher_id(id);
            QString nom = ui->lineEdit_Modnom->text();
            QString dateNaissance =ui->dateEdit_M->text();
            QString prenom = ui->lineEdit_Modprenom->text();
            QString departement = ui->lineEdit_Moddep->text();
            int numero = ui->lineEdit_Modnumero->text().toInt();

             if (query.next())
         {

                bool test =tempEmploye.modifier(id,nom,prenom,departement,dateNaissance,numero);


                  if(test)
                  {
                        ui->tableView_employe_aff->setModel(tempEmploye.afficher());//refresh
                  QMessageBox::information(nullptr, QObject::tr("Modifier Employé"),
                                    QObject::tr("Employé modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                  ui->stackedWidget_4->setCurrentIndex(0);


                  }
                 }

                    else
                        QMessageBox::critical(nullptr, QObject::tr("Modifier Employé"),
                                    QObject::tr("Employé n'exite pas !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_supp_emp_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
           QSqlQuery *query1=new QSqlQuery();
       int id= ui->lineEdit_SuppCin->text().toInt();
           QSqlQuery query=tempEmploye.rechercher_id(id);

           if (query.next())
          {
              bool test=tempEmploye.supprimer(id);

           if(test)
           {
               ui->tableView_employe_aff->setModel(tempEmploye.afficher());
           QMessageBox::information(nullptr, QObject::tr("ok"),
                             QObject::tr("Employe supprimé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
           ui->stackedWidget_4->setCurrentIndex(0);


           }
          }
             else
                 QMessageBox::critical(nullptr, QObject::tr("not ok"),
                             QObject::tr("Employé n'existe pas !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
           query1->prepare("select CIN from EMPLOYÉ");
           query1->exec();
           model->setQuery(*query1);
           ui->liste_employees_intervention2->setModel(model);
           ui->liste_employee_intervention1->setModel(model);
}


void MainWindow::on_trier_employe_clicked()
{
    QString critere=ui->comboBox->currentText();
            QString mode;
             if (ui->checkBox->checkState()==false)
        {
                 mode="DESC";
        }
             else if(ui->checkBox_2->checkState()==false)
             {
                 mode="ASC";
             }
          ui->tableView_employe_aff->setModel(tempEmploye.trier(critere,mode));
}


void MainWindow::on_pdf_employe_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_employe_aff->model()->rowCount();
                            const int columnCount =ui->tableView_employe_aff->model()->columnCount();

                            out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                        "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                        "<h1>liste des employees </h1>"



                                        "<table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                                out << "<thead><tr bgcolor=#f0f0f0>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView_employe_aff->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_employe_aff->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";
                                // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_employe_aff->isColumnHidden(column)) {
                                               QString data = ui->tableView_employe_aff->model()->data(ui->tableView_employe_aff->model()->index(row, column)).toString().simplified();
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
                        printer.setOutputFileName("employés.pdf");
                        document->print(&printer);
                        QDesktopServices::openUrl(QUrl::fromLocalFile("employés.pdf"));
}


void MainWindow::on_select_employe_clicked()
{
    int row=ui->tableView_employe_aff->selectionModel()->currentIndex().row();
                   QString id=ui->tableView_employe_aff->model()->index(row,0).data().toString();
                   QString nom=ui->tableView_employe_aff->model()->index(row,1).data().toString();
                   QString prenom=ui->tableView_employe_aff->model()->index(row,2).data().toString();
                   QDate dateNaissance=ui->tableView_employe_aff->model()->index(row,3).data().toDate();
                   QString departement=ui->tableView_employe_aff->model()->index(row,4).data().toString();
                   QString numero=ui->tableView_employe_aff->model()->index(row,5).data().toString();
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


void MainWindow::on_lineEdit_rech_employe_textChanged(const QString &arg1)
{
    if(ui->lineEdit_rech_employe->text()== "")
           {
               ui->tableView_employe_aff->setModel(tempEmploye.afficher());
           }
           else
           {
               ui->tableView_employe_aff->setModel(tempEmploye.rechercher(ui->lineEdit_rech_employe->text()));
           }
}


void MainWindow::on_ajout_departement_clicked()
{
    int idD = ui->lineEdit_AIDD->text().toInt();
            QString nomD = ui->lineEdit_AnomD->text();
            int nbE= ui->lineEdit_ANE->text().toInt();
            int salaire= ui->lineEdit_Asalaire->text().toInt();
            hmaher.savemaher("id departement :"+ui->lineEdit_AIDD->text(),"nom departement :"+ui->lineEdit_AnomD->text());
            Departement d(idD,nomD,nbE,salaire);
            bool test=d.ajouter_Dep();
            if(test)
            {
                   ui->tableView_departement_aff->setModel(tempDep.afficher_Dep());
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


void MainWindow::on_mod_departement_clicked()
{
    int idD= ui->lineEdit_Midep->text().toInt();
           QSqlQuery query=tempDep.rechercher_idD(idD);
           QString nomD = ui->lineEdit_MnomD->text();
           int nbE = ui->lineEdit_MnbE->text().toInt();
           int salaire = ui->lineEdit_Msalaire->text().toInt();

            if (query.next())
        {

               bool test =tempDep.modifier_Dep(idD,nomD,nbE,salaire);


                 if(test)
                 {
                       ui->tableView_departement_aff->setModel(tempDep.afficher_Dep());//refresh
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


void MainWindow::on_supp_departement_clicked()
{
    int idD= ui->lineEdit_SuppIDD->text().toInt();
                QSqlQuery query=tempDep.rechercher_idD(idD);

                if (query.next())
               {
                   bool test=tempDep.supprimer_Dep(idD);

                if(test)
                {
                    ui->tableView_departement_aff->setModel(tempDep.afficher_Dep());
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


void MainWindow::on_tri_departement_clicked()
{
    QString critere=ui->comboBox_3->currentText();
            QString mode;
             if (ui->checkBox_5->checkState()==false)
        {
                 mode="DESC";
        }
             else if(ui->checkBox_6->checkState()==false)
             {
                 mode="ASC";
             }
          ui->tableView_departement_aff->setModel(tempDep.trier_Dep(critere,mode));
}


void MainWindow::on_pdf_departement_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_departement_aff->model()->rowCount();
                            const int columnCount =ui->tableView_departement_aff->model()->columnCount();

                            out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("PRODUIT")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                        "<img src='C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/logo.png' width='100' height ='100'>\n"
                                        "<h1>liste des departements </h1>"



                                        "<table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                                out << "<thead><tr bgcolor=#f0f0f0>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView_departement_aff->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_departement_aff->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";
                                // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_departement_aff->isColumnHidden(column)) {
                                               QString data = ui->tableView_departement_aff->model()->data(ui->tableView_departement_aff->model()->index(row, column)).toString().simplified();
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
                        printer.setOutputFileName("departements.pdf");
                        document->print(&printer);
                        QDesktopServices::openUrl(QUrl::fromLocalFile("departements.pdf"));
}


void MainWindow::on_select_dep_clicked()

    {
        int row=ui->tableView_departement_aff->selectionModel()->currentIndex().row();
                   QString idD=ui->tableView_departement_aff->model()->index(row,0).data().toString();
                   QString nomD=ui->tableView_departement_aff->model()->index(row,1).data().toString();
                   QString nbE=ui->tableView_departement_aff->model()->index(row,2).data().toString();
                   QString salaire=ui->tableView_departement_aff->model()->index(row,3).data().toString();
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



void MainWindow::on_lineEdit_rechdep_textChanged(const QString &arg1)
{
    if(ui->lineEdit_rechdep->text()== "")
          {
              ui->tableView_departement_aff->setModel(tempDep.afficher_Dep());
          }
          else
          {
              ui->tableView_departement_aff->setModel(tempDep.rechercher_Dep(ui->lineEdit_rechdep->text()));
          }
}


void MainWindow::on_stat_maher_clicked()
{
    statm=new statmaher(this);
            statm->show();
}


void MainWindow::on_excel_departement_clicked()
{
    QTableView *table;

                       table = ui->tableView_departement_aff;


                       QString filters("Excel Files (.xls)");

                       QString defaultFilter("Excel Files (*.xls)");

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


void MainWindow::on_excel_employe_clicked()
{
    QTableView *table;

                        table = ui->tableView_employe_aff;


                        QString filters("Excel Files (.xls)");

                        QString defaultFilter("Excel Files (*.xls)");

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

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_comfirmer_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_comfirmer_3_clicked()
{
    QFile file("C:/Users/uxser/Desktop/Smart_Factory_2A5/Smart_Factory_2A5/ConsoleStyle.qss");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        ui->stackedWidget->setStyleSheet(styleSheet);
        ui->pushButton_comfirmer_2->setStyleSheet(styleSheet);
        ui->rh->setStyleSheet(styleSheet);
        ui->pushButton_2->setStyleSheet(styleSheet);
        ui->pushButton_3->setStyleSheet(styleSheet);
        ui->pushButton_4->setStyleSheet(styleSheet);
        ui->pushButton_5->setStyleSheet(styleSheet);
        ui->pushButton_6->setStyleSheet(styleSheet);
        ui->pushButton_7->setStyleSheet(styleSheet);
        ui->pushButton_comfirmer_2->setStyleSheet(styleSheet);
        ui->pushButton_comfirmer_3->setStyleSheet(styleSheet);
        ui->frame->setStyleSheet(styleSheet);
        ui->frame_2->setStyleSheet(styleSheet);
        ui->frame_3->setStyleSheet(styleSheet);
        ui->frame_4->setStyleSheet(styleSheet);
        ui->frame_5->setStyleSheet(styleSheet);
        ui->frame_6->setStyleSheet(styleSheet);
}

void MainWindow::on_pushButton_131_clicked()
{
    ademard=new arduinoadem(this);
            ademard->show();
}
