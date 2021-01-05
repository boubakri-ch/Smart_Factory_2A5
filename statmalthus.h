#ifndef STATMALTHUS_H
#define STATMALTHUS_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>

namespace Ui {
class statmalthus;
}

class statmalthus : public QDialog
{
    Q_OBJECT

public:
    explicit statmalthus(QWidget *parent = nullptr);
    ~statmalthus();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;

private:
    Ui::statmalthus *ui;
};

#endif // STATMALTHUS_H
