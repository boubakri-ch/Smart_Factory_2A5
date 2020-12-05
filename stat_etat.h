#ifndef STAT_ETAT_H
#define STAT_ETAT_H

#include <QDialog>
#include <QDialog>
#include <QApplication>
#include <QtWidgets/QMainWindow>



namespace Ui {
class stat_etat;
}

class stat_etat : public QDialog
{
    Q_OBJECT

public:
    explicit stat_etat(QWidget *parent = nullptr);
    ~stat_etat();

private:
    Ui::stat_etat *ui;
};

#endif // STAT_ETAT_H
