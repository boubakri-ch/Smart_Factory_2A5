#ifndef STATTATAR_H
#define STATTATAR_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>

namespace Ui {
class stattatar;
}

class stattatar : public QDialog
{
    Q_OBJECT

public:
    explicit stattatar(QWidget *parent = nullptr);
    ~stattatar();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;


private:
    Ui::stattatar *ui;
};

#endif // STATTATAR_H
