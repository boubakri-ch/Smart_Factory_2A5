#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtMultimedia/qsound.h>
#include "formation.h"
#include "formateur.h"
#include <QMainWindow>
#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
FORMATION f , *fs;
FORMATEUR g , *gs;
QString ch;
  QSound *sound= new QSound(":/click.wav");
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
    void on_radioButton_nom_clicked();
    void on_radioButton_cin_clicked();
    void on_radioButton_pre_clicked();
    void on_radioButton_CODE_clicked();
    void on_radioButton_NOM_clicked();
    void on_radioButton_DOMAINE_clicked();
    void on_radioButton_DEP_clicked();
    void on_pdf_tions_clicked();
    void on_pdf_teurs_clicked();

private:
    Ui::MainWindow *ui;
    FORMATION tmpFORMATION;
    FORMATEUR tmpFORMATEUR;
};
#endif // MAINWINDOW_H
