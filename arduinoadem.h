#ifndef ARDUINOADEM_H
#define ARDUINOADEM_H
#include "arduinoad.h"
#include <QDialog>

namespace Ui {
class arduinoadem;
}

class arduinoadem : public QDialog
{
    Q_OBJECT

public:
    explicit arduinoadem(QWidget *parent = nullptr);
    ~arduinoadem();
    void update_label();

private slots:
    void on_on1_clicked();

    void on_off1_clicked();

    void on_on2_clicked();

    void on_off2_clicked();

    void on_on3_clicked();

    void on_off3_clicked();

private:
    Ui::arduinoadem *ui;
    arduinoad A;
    QByteArray data;
};

#endif // ARDUINOADEM_H
