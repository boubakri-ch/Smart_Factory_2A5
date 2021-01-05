#ifndef STATMAHER_H
#define STATMAHER_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>

namespace Ui {
class statmaher;
}

class statmaher : public QDialog
{
    Q_OBJECT

public:
    explicit statmaher(QWidget *parent = nullptr);
    ~statmaher();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;

private:
    Ui::statmaher *ui;
};

#endif // STATMAHER_H
