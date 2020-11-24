#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "etudiant.h"
#include "produit.h"
#include "fournisseur.h"
#include <QMainWindow>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_clicked();

    void on_pdf_clicked();

    void on_print_clicked();

    void on_pushButton_apply_clicked();

    void on_pushButton_Ajout_P_clicked();

    void on_pushButton_afficherp_clicked();

    void on_pushButton_produit_mod_clicked();

    void on_pushButton_ps_clicked();

    void on_pushButton_P_RECHERCHE_clicked();

    void on_lineEdit_r_d_textChanged(const QString &arg1);

    void on_ajouter_fournisseur_clicked();

    void on_modifier_fournisseur_clicked();

    void on_tri_id_fournisseur_clicked();

    void on_supprimer_fournisseur_clicked();

private:
    Ui::MainWindow *ui;
    etudiant tempEtudiant;
    produit tempProduit;
    fournisseur tempFournisseur;
};
#endif // MAINWINDOW_H
