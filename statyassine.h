#ifndef STATYASSINE_H
#define STATYASSINE_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>

namespace Ui {
class statyassine;
}

class statyassine : public QDialog
{
    Q_OBJECT

public:
    explicit statyassine(QWidget *parent = nullptr);
    ~statyassine();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;

    void paintEvent(QPaintEvent *) ;


private:
    Ui::statyassine *ui;
};

#endif // STATYASSINE_H
