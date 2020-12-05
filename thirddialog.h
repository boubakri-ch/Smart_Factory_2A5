#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H
#include "client.h"
#include <QDialog>
#include"wwindow.h"

namespace Ui {
class ThirdDialog;
}

class ThirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdDialog(QWidget *parent = nullptr);
    ~ThirdDialog();
private slots:


    void on_pb_supprimer_2_clicked();

    void on_pb_Modifier_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::ThirdDialog *ui;


};

#endif // THIRDDIALOG_H
