#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"fournisseur.h"
#include"produit.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QMediaPlayer;
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

    void on_pushButton_8_clicked();



    void on_apporter_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_volume_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    FOURNISSEUR tab_four;
QMediaPlayer *mMediaPlayer;
    PRODUIT tab_pro;

#endif // MAINWINDOW_H
};
