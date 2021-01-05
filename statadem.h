#ifndef STATADEM_H
#define STATADEM_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>

namespace Ui {
class statadem;
}

class statadem : public QDialog
{
    Q_OBJECT

public:
    explicit statadem(QWidget *parent = nullptr);
    ~statadem();
    int Stat_partie2() ;
        int Stat_partie3() ;
        int Stat_partie4() ;

        void paintEvent(QPaintEvent *) ;

private:
    Ui::statadem *ui;
};

#endif // STATADEM_H
