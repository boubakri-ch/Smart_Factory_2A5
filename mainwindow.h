#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "etudiant.h"
#include "produit.h"
#include "fournisseur.h"
#include "matierepremiere.h"
#include "formateur.h"
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

    void on_pushButton_recherchef_clicked();

    void on_pushButton_p_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_modifier_activated(int index);

    void on_lineEdit_P_R_textChanged(const QString &arg1);

    void on_pushButton_p_prix_clicked();

    void on_pushButton_excel_clicked();

    void on_ajout_matierep_clicked();

    void on_supprimer_matierep_clicked();

    void on_modification_matierep_clicked();

    void on_tri_id_clicked();

    void on_rechercher_id_matierep_textChanged(const QString &arg1);

    void on_pdf_matiere_premiere_clicked();

    void on_ajout_formateur_clicked();

    void on_supprimer_formateur_clicked();

    void on_modifier_formateur_clicked();

    void on_radioButton_CIN_clicked();

    void on_radioButton_nom_clicked();

    void on_radioButton_prenom_clicked();

    void on_genere_liste_formateur_clicked();

private:
    Ui::MainWindow *ui;
    etudiant tempEtudiant;
    produit tempProduit;
    fournisseur tempFournisseur;
    matierepremiere tempmatiereprem;
    formateur tempformateur;
};
#endif // MAINWINDOW_H
