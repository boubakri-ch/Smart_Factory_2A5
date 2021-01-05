#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>

namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();
            int Stat_partie2() ;
            int Stat_partie3() ;
            int Stat_partie4() ;

            void paintEvent(QPaintEvent *) ;


private:
    Ui::statistique *ui;
};

#endif // STATISTIQUE_H
