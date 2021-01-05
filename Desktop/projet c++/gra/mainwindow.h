#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"fournisseur.h"
#include"produit.h"
#include<arduino.h>
#include"statistique.h"
#include<QSound>
#include <QRegExpValidator>
#include <QMainWindow>
#include <QTcpSocket>
#include"historique.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QMediaPlayer;
class QSystemTrayIcon;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_apporter_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_volume_valueChanged(int value);

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_lineEdit_r_f_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_combo_currentTextChanged(const QString &arg1);

    void on_pushButton_18_clicked();
    void leer();
    void on_pushButton_19_clicked();

private:
    Ui::MainWindow *ui;
    FOURNISSEUR tab_four;
    QMediaPlayer *mMediaPlayer;
    PRODUIT tab_pro;
    arduino A;
    QByteArray data;
    QSound *son;
     QSystemTrayIcon *mSystemTrayIcon;
     statistique *stat;
     QTcpSocket*mSocket;
     Historique histo;
     QString temp="";
#endif // MAINWINDOW_H
};
