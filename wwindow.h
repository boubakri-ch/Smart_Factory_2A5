#ifndef WWINDOW_H
#define WWINDOW_H
#include"client.h"
#include <QDialog>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "gestion_coli_courrier.h"


namespace Ui {
class WWindow;
}

class WWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WWindow(QWidget *parent = nullptr);
    ~WWindow();
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_CIN;
    QLineEdit *lineEdit_Date;
    QLineEdit *lineEdit_Livraison;
    QPushButton *pb_ajouter;
    QLineEdit *lineEdit_Produit;
    QLabel *label_5;
    QLineEdit *lineEdit_Prenom;
    QLineEdit *lineEdit_Nom;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *tab_2;
    QTableView *tabclient;
    QWidget *tab_3;
    QLineEdit *lineEdit_id_2;
    QLabel *label_4;
    QPushButton *pb_supprimer;
    QWidget *tab_4;
    QLineEdit *lineEdit_nomrech;
    QLabel *label_8;
    QPushButton *pb_Modifier;
    QPushButton *pushButton;
    QLabel *label_9;
    QLineEdit *lineEdit_dateLN;
    QLabel *label_11;
    QLineEdit *lineEdit_LivraisonCN;
    QLabel *label_12;
    QLineEdit *lineEdit_prenomN;
    QLabel *label_10;
    QLineEdit *lineEdit_CINN;
    QLineEdit *lineEdit_ProduitN;
    QLabel *label_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

private slots:


    void on_pb_supprimer_2_clicked();

    void on_pb_Modifier_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    /*void on_pushButton_2_clicked();*/

private:
    Ui::WWindow *ui;
    Client tmpclient;
    Gestion_Coli_Courrier *Gestion_coli_courrier;




};

#endif // WWINDOW_H
