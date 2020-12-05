#ifndef STAT_CLIENT_H
#define STAT_CLIENT_H
#include <QDialog>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QTextCharFormat>

#include <QDialog>

namespace Ui {
class stat_client;
}

class stat_client : public QDialog
{
    Q_OBJECT

public:
    explicit stat_client(QWidget *parent = nullptr);
    ~stat_client();

private:
    Ui::stat_client *ui;
};

#endif // STAT_CLIENT_H
