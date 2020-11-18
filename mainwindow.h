#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "formation.h"
#include "formateur.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
FORMATION f , *fs;
FORMATEUR g , *gs;
QString ch;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_AJOUTER_clicked();
    void on_pushButton_VALIDERMOD_clicked();
    void on_pushButton_SUPPRIMERFRMTS_clicked();
    void on_pushButton_add_teurs_clicked();
    void on_pushButton_mod_teurs_clicked();
    void on_pushButton_supp_teur_clicked();
    void on_rechercher_3_textChanged(const QString &ch);
    void on_rechercher_2_textChanged(const QString &ch);
private:
    Ui::MainWindow *ui;
    FORMATION tmpFORMATION;
    FORMATEUR tmpFORMATEUR;
};
#endif // MAINWINDOW_H
