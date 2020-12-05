#include "mainwindow.h"
#include "wwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QPushButton>
#include "connection.h"
#include<QtDebug>
#include <QtUiTools/QtUiTools>



int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    QMainWindow window;
    WWindow wwindow;
    Gestion_Coli_Courrier ges;



    try{

        wwindow.show();


    }catch(QString s){
        qDebug()<<s;
    }
    return a.exec();
}
