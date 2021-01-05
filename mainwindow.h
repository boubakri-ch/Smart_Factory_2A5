#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "login.h"
#include "categorie.h"
#include "produit.h"
#include "fournisseur.h"
#include "matierepremiere.h"
#include "formateur.h"
#include "formation.h"
#include "materiel.h"
#include "intervention.h"
#include "client.h"
#include "coli.h"
#include "employe.h"
#include "departement.h"
#include "statistique.h"
#include "stattatar.h"
#include "statadem.h"
#include "statmaher.h"
#include "statmalthus.h"
#include "statyassine.h"
#include "historique.h"
#include "historiquef.h"
#include "historiquemalth.h"
#include "historiqueyassine.h"
#include "historiqueyoussef.h"
#include "historiquemaher.h"
#include "arduinoadem.h"
#include <QRegExpValidator>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QSystemTrayIcon;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rh_clicked();

    void on_employe_clicked();




    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_3_clicked();

    void on_employe_2_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_39_clicked();

    void on_employe_3_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_58_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_2_clicked();

    void on_employe_4_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_66_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_68_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_75_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_4_clicked();

    void on_employe_5_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_87_clicked();

    void on_pushButton_95_clicked();

    void on_pushButton_94_clicked();

    void on_pushButton_96_clicked();

    void on_pushButton_5_clicked();

    void on_employe_6_clicked();

    void on_pushButton_103_clicked();

    void on_pushButton_104_clicked();

    void on_pushButton_105_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_114_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_115_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_122_clicked();

    void on_pushButton_123_clicked();

    void on_pushButton_124_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_126_clicked();

    void on_pushButton_127_clicked();


    void on_pushButton_connecter_clicked();

    void on_pushButton_comfirmer_clicked();

    void on_pushButton_sinscrire_clicked();

    void on_pushButton_retour_clicked();

    void on_ajout_categorie_clicked();

    void on_suppression_categorie_clicked();

    void on_modification_categorie_clicked();

    void on_recherche_categorie_textChanged(const QString &arg1);

    void on_tri_alphabetique_categorie_clicked();

    void on_tri_desc_id_categorie_clicked();

    void on_tri_asc_id_categorie_clicked();

    void on_pdf_categorie_clicked();

    void on_ajouter_produit_clicked();

    void on_supp_produit_clicked();

    void on_modifier_produit_clicked();

    void on_produit_rech_dynamique_textChanged(const QString &arg1);

    void on_tri_produit_prix_clicked();

    void on_tri_produit_identifiant_clicked();

    void on_tri_produit_quantity_clicked();

    void on_pdf_produit_clicked();

    void on_statcp_clicked();

    void on_ajout_fournisseur_clicked();

    void on_modifier_fournisseur_clicked();

    void on_fournisseur_supp_clicked();

    void on_tri_id_fournisseur_clicked();

    void on_tri_rib_desc_clicked();

    void on_tri_nom_fournisseur_clicked();

    void on_pdf_fournisseur_clicked();

    void on_lineEdit_rechereche_fournisseur_textChanged(const QString &arg1);

    void on_matiere_ajout_clicked();

    void on_supprimer_matierep_clicked();

    void on_modifier_matierep_clicked();

    void on_tri_matierep_id_clicked();

    void on_tri_matierep_quantit_clicked();

    void on_trimp_clicked();

    void on_pdf_matierep_clicked();

    void on_recherche_matierep_textChanged(const QString &arg1);

    void on_stat_chiheb_clicked();

    void on_google_clicked();

    void on_excel_matiere_prem_clicked();

    void on_saida_clicked();

    void on_excel_fournisseur_clicked();

    void on_excel_produit_clicked();

    void on_pushButton_excel_adem_clicked();

    void on_ajout_formateur_clicked();

    void on_modification_formateur_clicked();

    void on_supprimer_formateur_clicked();

    void on_tri_cin_formateur_clicked();

    void on_tri_nom_formateur_clicked();

    void on_rei_prenom_formateur_clicked();

    void on_recherche_formateur_textChanged(const QString &arg1);

    void on_generer_liste_formateur_clicked();

    void on_ajout_formation_clicked();

    void on_supprimer_formation_clicked();

    void on_modifier_formation_clicked();

    void on_recherche_formation_textChanged(const QString &arg1);

    void on_tri_code_formation_clicked();

    void on_tri_nom_formation_clicked();

    void on_tri_domaine_formation_clicked();

    void on_tri_department_formation_clicked();

    void on_genere_liste_formation_clicked();

    void on_stat_malthus_clicked();

    void on_excel_ff_clicked();

    void on_excel_formateur_clicked();

    void on_ajout_materiel_clicked();

    void on_modifier_materiel_clicked();

    void on_supprimer_materiel_clicked();

    void on_tri_materiel_prix_clicked();

    void on_tri_id_desc_clicked();

    void on_tri_selon_id_clicked();

    void on_recherche_materiel_textChanged(const QString &arg1);

    void on_pdf_materiel_clicked();

    void on_ajout_intervention_clicked();

    void on_modifier_intervention_clicked();

    void on_intervention_suppression_clicked();

    void on_recherche_intervention_textChanged(const QString &arg1);

    void on_pdf_intervention_clicked();

    void on_tri_nom_clicked();

    void on_tri_nom_desc_clicked();

    void on_stat_yassine_clicked();

    void on_excel_intervention_clicked();

    void on_excel_materiel_clicked();

    void on_ajout_client_clicked();

    void on_supprimer_client_clicked();

    void on_modifier_client_clicked();

    void on_recherche_client_textChanged(const QString &arg1);

    void on_client_pdf_clicked();

    void on_tri_client_cin_clicked();

    void on_tri_client_nom_clicked();

    void on_tri_client_prenom_clicked();

    void on_ajouter_coli_clicked();

    void on_coli_supp_clicked();

    void on_modifier_coli_clicked();



    void on_recherche_coli_textChanged(const QString &arg1);

    void on_pdf_coli_clicked();

    void on_tri_prix_coli_clicked();

    void on_tri_coli_poids_clicked();

    void on_tri_colitype_clicked();

    void on_stat_tatar_clicked();

    void on_pushButton_excel_coli_clicked();

    void on_excel_client_clicked();

    void on_ajout_un_employ_clicked();

    void on_mod_employe_clicked();

    void on_supp_emp_clicked();

    void on_trier_employe_clicked();

    void on_pdf_employe_clicked();

    void on_select_employe_clicked();

    void on_lineEdit_rech_employe_textChanged(const QString &arg1);

    void on_ajout_departement_clicked();

    void on_mod_departement_clicked();

    void on_supp_departement_clicked();

    void on_tri_departement_clicked();

    void on_pdf_departement_clicked();

    void on_select_dep_clicked();

    void on_lineEdit_rechdep_textChanged(const QString &arg1);

    void on_stat_maher_clicked();

    void on_excel_departement_clicked();

    void on_excel_employe_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_comfirmer_2_clicked();

    void on_pushButton_comfirmer_3_clicked();

    void on_pushButton_131_clicked();

private:
    Ui::MainWindow *ui;
    login l;
    categorie tempCategorie;
    produit tempProduit;
    fournisseur tempFournisseur;
    matierepremiere tempMatierep;
    formateur tempFormateur;
    formation tempFormation;
    materiel tempMateriel;
    intervention tempIntervention;
    client tempClient;
    coli tempColi;
    employe tempEmploye;
    Departement tempDep;
    statistique *stat;
    stattatar *statt;
    statadem *stata;
    statmaher *statm;
    statmalthus *statmalth;
    statyassine *statyass;
    arduinoadem *ademard;
    QSystemTrayIcon *mSystemTrayIcon;
    historique h;
    historiquef hf;
    historiquemalth hm;
    historiqueyassine hy;
    historiqueyoussef hyou;
    historiquemaher hmaher;

};
#endif // MAINWINDOW_H
