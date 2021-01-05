--------------------------------------------------------
--  Fichier cr�� - vendredi-janvier-01-2021   
--------------------------------------------------------
DROP TABLE "ADEM"."CATEGORIE";
DROP TABLE "ADEM"."CLIENT";
DROP TABLE "ADEM"."COLI";
DROP TABLE "ADEM"."DEPARTEMENT";
DROP TABLE "ADEM"."EMPLOY�";
DROP TABLE "ADEM"."FORMATEUR";
DROP TABLE "ADEM"."FORMATION";
DROP TABLE "ADEM"."FOURNISSEUR";
DROP TABLE "ADEM"."INTERVENTION";
DROP TABLE "ADEM"."LIVRAISON";
DROP TABLE "ADEM"."LOGIN";
DROP TABLE "ADEM"."MATERIEL";
DROP TABLE "ADEM"."MATIERE";
DROP TABLE "ADEM"."PRODUIT";
--------------------------------------------------------
--  DDL for Table CATEGORIE
--------------------------------------------------------

  CREATE TABLE "ADEM"."CATEGORIE" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CLIENT
--------------------------------------------------------

  CREATE TABLE "ADEM"."CLIENT" 
   (	"CIN_CLIENT" NUMBER, 
	"NOM_CLIENT" VARCHAR2(20 BYTE), 
	"PRENOM_CLIENT" VARCHAR2(20 BYTE), 
	"LOCALISATION_CLIENT" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COLI
--------------------------------------------------------

  CREATE TABLE "ADEM"."COLI" 
   (	"IDCOLI" NUMBER, 
	"ADRESSE_D" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"POIDS" NUMBER, 
	"PRIX" NUMBER, 
	"CINCLIENT" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table DEPARTEMENT
--------------------------------------------------------

  CREATE TABLE "ADEM"."DEPARTEMENT" 
   (	"ID_DEPARTEMENT" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"NOMBRE_EMPLOYE" VARCHAR2(20 BYTE), 
	"SALAIRE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOY�
--------------------------------------------------------

  CREATE TABLE "ADEM"."EMPLOY�" 
   (	"CIN" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"DATENAISSANCE" VARCHAR2(20 BYTE), 
	"ID_DEPARTEMENT" VARCHAR2(20 BYTE), 
	"NUMERO" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FORMATEUR
--------------------------------------------------------

  CREATE TABLE "ADEM"."FORMATEUR" 
   (	"CIN" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FORMATION
--------------------------------------------------------

  CREATE TABLE "ADEM"."FORMATION" 
   (	"CODE" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"DOMAINE" VARCHAR2(20 BYTE), 
	"DEPARTEMENT" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FOURNISSEUR
--------------------------------------------------------

  CREATE TABLE "ADEM"."FOURNISSEUR" 
   (	"ID_FOURNISSEUR" NUMBER, 
	"NOM_FOURNISSEUR" VARCHAR2(20 BYTE), 
	"PRENOM_FOURNISSEUR" VARCHAR2(20 BYTE), 
	"DATE_FOURNISSEUR" DATE, 
	"NUM_TEL" VARCHAR2(8 BYTE), 
	"RIB" VARCHAR2(23 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table INTERVENTION
--------------------------------------------------------

  CREATE TABLE "ADEM"."INTERVENTION" 
   (	"ID" VARCHAR2(20 BYTE), 
	"IDM" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"DATE_I" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LIVRAISON
--------------------------------------------------------

  CREATE TABLE "ADEM"."LIVRAISON" 
   (	"IDLIV" VARCHAR2(20 BYTE), 
	"LIDCOLI" VARCHAR2(20 BYTE), 
	"LIDEQUIP" VARCHAR2(20 BYTE), 
	"LDATE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LOGIN
--------------------------------------------------------

  CREATE TABLE "ADEM"."LOGIN" 
   (	"MDP" VARCHAR2(20 BYTE), 
	"IDENTIFIANT" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MATERIEL
--------------------------------------------------------

  CREATE TABLE "ADEM"."MATERIEL" 
   (	"DATEFAB" VARCHAR2(20 BYTE), 
	"PRIX_U" VARCHAR2(20 BYTE), 
	"ID" VARCHAR2(20 BYTE), 
	"FOURNISSEUR" VARCHAR2(20 BYTE), 
	"QUANTITE_T" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MATIERE
--------------------------------------------------------

  CREATE TABLE "ADEM"."MATIERE" 
   (	"ID_MATIERE" NUMBER, 
	"NOM_MATIERE" VARCHAR2(20 BYTE), 
	"QUANTITY_MATIERE" NUMBER, 
	"DATE_MATIERE" VARCHAR2(20 BYTE), 
	"ID_F" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PRODUIT
--------------------------------------------------------

  CREATE TABLE "ADEM"."PRODUIT" 
   (	"IDP" VARCHAR2(20 BYTE), 
	"NOMP" VARCHAR2(20 BYTE), 
	"QUANTIT�" NUMBER, 
	"PRIX" NUMBER, 
	"IDC" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into ADEM.CATEGORIE
SET DEFINE OFF;
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('194',null,null);
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('15631','a','a');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('457','president','fromage');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('1879','pre','fromage');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('1000','l','p');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('50',null,null);
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('300',null,null);
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('13','zrg','grz');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('213','rhyhgbd','gbd');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('468','slim','slim');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('0',null,null);
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('1348','j','o');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('9944','n','l');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('21','k','k');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('48976245','g-yu','hui');
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('45','grzg',null);
Insert into ADEM.CATEGORIE (ID,NOM,TYPE) values ('2424','bh','zfzrfr');
REM INSERTING into ADEM.CLIENT
SET DEFINE OFF;
Insert into ADEM.CLIENT (CIN_CLIENT,NOM_CLIENT,PRENOM_CLIENT,LOCALISATION_CLIENT) values ('15','i','b','a');
Insert into ADEM.CLIENT (CIN_CLIENT,NOM_CLIENT,PRENOM_CLIENT,LOCALISATION_CLIENT) values ('11','f','f','f');
Insert into ADEM.CLIENT (CIN_CLIENT,NOM_CLIENT,PRENOM_CLIENT,LOCALISATION_CLIENT) values ('20',null,null,null);
Insert into ADEM.CLIENT (CIN_CLIENT,NOM_CLIENT,PRENOM_CLIENT,LOCALISATION_CLIENT) values ('10',null,null,null);
Insert into ADEM.CLIENT (CIN_CLIENT,NOM_CLIENT,PRENOM_CLIENT,LOCALISATION_CLIENT) values ('30',null,null,null);
Insert into ADEM.CLIENT (CIN_CLIENT,NOM_CLIENT,PRENOM_CLIENT,LOCALISATION_CLIENT) values ('80',null,null,null);
Insert into ADEM.CLIENT (CIN_CLIENT,NOM_CLIENT,PRENOM_CLIENT,LOCALISATION_CLIENT) values ('79458',null,null,null);
REM INSERTING into ADEM.COLI
SET DEFINE OFF;
Insert into ADEM.COLI (IDCOLI,ADRESSE_D,TYPE,POIDS,PRIX,CINCLIENT) values ('155',null,'adefr','0','0','0');
Insert into ADEM.COLI (IDCOLI,ADRESSE_D,TYPE,POIDS,PRIX,CINCLIENT) values ('6','fr','fzr','100','100','80');
Insert into ADEM.COLI (IDCOLI,ADRESSE_D,TYPE,POIDS,PRIX,CINCLIENT) values ('245',null,null,'0','0','0');
Insert into ADEM.COLI (IDCOLI,ADRESSE_D,TYPE,POIDS,PRIX,CINCLIENT) values ('15',null,'b','0','0','0');
Insert into ADEM.COLI (IDCOLI,ADRESSE_D,TYPE,POIDS,PRIX,CINCLIENT) values ('700',null,null,'700','0','0');
REM INSERTING into ADEM.DEPARTEMENT
SET DEFINE OFF;
Insert into ADEM.DEPARTEMENT (ID_DEPARTEMENT,NOM,NOMBRE_EMPLOYE,SALAIRE) values ('15','b','10','10');
Insert into ADEM.DEPARTEMENT (ID_DEPARTEMENT,NOM,NOMBRE_EMPLOYE,SALAIRE) values ('19',null,'0','0');
Insert into ADEM.DEPARTEMENT (ID_DEPARTEMENT,NOM,NOMBRE_EMPLOYE,SALAIRE) values ('5','gre','100','13');
Insert into ADEM.DEPARTEMENT (ID_DEPARTEMENT,NOM,NOMBRE_EMPLOYE,SALAIRE) values ('18','bre','1','1');
REM INSERTING into ADEM."EMPLOY�"
SET DEFINE OFF;
Insert into ADEM."EMPLOY�" (CIN,NOM,PRENOM,DATENAISSANCE,ID_DEPARTEMENT,NUMERO) values ('48',null,null,'06/05/2002',null,'0');
Insert into ADEM."EMPLOY�" (CIN,NOM,PRENOM,DATENAISSANCE,ID_DEPARTEMENT,NUMERO) values ('50','rzggrz','gzr','01/01/2000','1','56');
Insert into ADEM."EMPLOY�" (CIN,NOM,PRENOM,DATENAISSANCE,ID_DEPARTEMENT,NUMERO) values ('15',null,null,'01/01/2000',null,'0');
Insert into ADEM."EMPLOY�" (CIN,NOM,PRENOM,DATENAISSANCE,ID_DEPARTEMENT,NUMERO) values ('19',null,null,'01/01/2000',null,'0');
REM INSERTING into ADEM.FORMATEUR
SET DEFINE OFF;
Insert into ADEM.FORMATEUR (CIN,NOM,PRENOM) values ('12','op','op');
Insert into ADEM.FORMATEUR (CIN,NOM,PRENOM) values ('8','adem','bkhr');
Insert into ADEM.FORMATEUR (CIN,NOM,PRENOM) values ('78','l','a');
Insert into ADEM.FORMATEUR (CIN,NOM,PRENOM) values ('7','f','t');
REM INSERTING into ADEM.FORMATION
SET DEFINE OFF;
Insert into ADEM.FORMATION (CODE,NOM,DOMAINE,DEPARTEMENT) values ('10','b','a','c');
Insert into ADEM.FORMATION (CODE,NOM,DOMAINE,DEPARTEMENT) values ('12','j','b','l');
Insert into ADEM.FORMATION (CODE,NOM,DOMAINE,DEPARTEMENT) values ('2','a','k','l');
Insert into ADEM.FORMATION (CODE,NOM,DOMAINE,DEPARTEMENT) values ('5','l','l','l');
REM INSERTING into ADEM.FOURNISSEUR
SET DEFINE OFF;
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('471',null,null,to_date('10/12/20','DD/MM/RR'),null,null);
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('48','l','l',to_date('08/12/20','DD/MM/RR'),'1','1');
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('20','ziedi','slim',to_date('23/11/20','DD/MM/RR'),'516','564');
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('1','chiheb','boubakri',to_date('23/11/20','DD/MM/RR'),'48','129');
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('14','m','u',to_date('08/12/20','DD/MM/RR'),'1315','1535');
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('0','1',null,to_date('08/12/20','DD/MM/RR'),null,null);
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('10','k','b',to_date('10/12/20','DD/MM/RR'),'165','10');
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('80','k','b',to_date('10/12/20','DD/MM/RR'),'165','10');
Insert into ADEM.FOURNISSEUR (ID_FOURNISSEUR,NOM_FOURNISSEUR,PRENOM_FOURNISSEUR,DATE_FOURNISSEUR,NUM_TEL,RIB) values ('45','frzg',null,to_date('15/12/20','DD/MM/RR'),null,null);
REM INSERTING into ADEM.INTERVENTION
SET DEFINE OFF;
Insert into ADEM.INTERVENTION (ID,IDM,NOM,DATE_I) values (null,null,'1','12');
Insert into ADEM.INTERVENTION (ID,IDM,NOM,DATE_I) values (null,null,'21','21');
Insert into ADEM.INTERVENTION (ID,IDM,NOM,DATE_I) values (null,null,'21','21');
Insert into ADEM.INTERVENTION (ID,IDM,NOM,DATE_I) values (null,null,'18','21');
Insert into ADEM.INTERVENTION (ID,IDM,NOM,DATE_I) values (null,null,'18','21');
Insert into ADEM.INTERVENTION (ID,IDM,NOM,DATE_I) values (null,'2','a','4');
Insert into ADEM.INTERVENTION (ID,IDM,NOM,DATE_I) values (null,'5','b','4');
Insert into ADEM.INTERVENTION (ID,IDM,NOM,DATE_I) values (null,'12','l','4m');
REM INSERTING into ADEM.LIVRAISON
SET DEFINE OFF;
REM INSERTING into ADEM.LOGIN
SET DEFINE OFF;
Insert into ADEM.LOGIN (MDP,IDENTIFIANT) values ('12','12');
Insert into ADEM.LOGIN (MDP,IDENTIFIANT) values ('13','13');
Insert into ADEM.LOGIN (MDP,IDENTIFIANT) values ('1','1');
REM INSERTING into ADEM.MATERIEL
SET DEFINE OFF;
Insert into ADEM.MATERIEL (DATEFAB,PRIX_U,ID,FOURNISSEUR,QUANTITE_T) values ('7','5','1','pl','1000');
Insert into ADEM.MATERIEL (DATEFAB,PRIX_U,ID,FOURNISSEUR,QUANTITE_T) values ('5','2','236','m','200');
Insert into ADEM.MATERIEL (DATEFAB,PRIX_U,ID,FOURNISSEUR,QUANTITE_T) values ('5','300','236','m','200');
Insert into ADEM.MATERIEL (DATEFAB,PRIX_U,ID,FOURNISSEUR,QUANTITE_T) values ('100','126','236','m','400');
Insert into ADEM.MATERIEL (DATEFAB,PRIX_U,ID,FOURNISSEUR,QUANTITE_T) values ('687','10','20','plh','200');
Insert into ADEM.MATERIEL (DATEFAB,PRIX_U,ID,FOURNISSEUR,QUANTITE_T) values ('5','5','123','a','4');
REM INSERTING into ADEM.MATIERE
SET DEFINE OFF;
Insert into ADEM.MATIERE (ID_MATIERE,NOM_MATIERE,QUANTITY_MATIERE,DATE_MATIERE,ID_F) values ('12',null,'20','01-01-2000','0');
Insert into ADEM.MATIERE (ID_MATIERE,NOM_MATIERE,QUANTITY_MATIERE,DATE_MATIERE,ID_F) values ('15',null,'560','01-01-2000','0');
Insert into ADEM.MATIERE (ID_MATIERE,NOM_MATIERE,QUANTITY_MATIERE,DATE_MATIERE,ID_F) values ('16',null,'570','01-01-2000','0');
Insert into ADEM.MATIERE (ID_MATIERE,NOM_MATIERE,QUANTITY_MATIERE,DATE_MATIERE,ID_F) values ('156',null,'200','01-01-2000','0');
Insert into ADEM.MATIERE (ID_MATIERE,NOM_MATIERE,QUANTITY_MATIERE,DATE_MATIERE,ID_F) values ('18',null,null,'01-01-2000','0');
Insert into ADEM.MATIERE (ID_MATIERE,NOM_MATIERE,QUANTITY_MATIERE,DATE_MATIERE,ID_F) values ('151','grz',null,'01-01-2000','0');
REM INSERTING into ADEM.PRODUIT
SET DEFINE OFF;
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('100','m','8','3','50');
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('40',null,'0','0','0');
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('12','k','100','100','21');
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('14','m','800','100','0');
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('3',null,'0','0','0');
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('11',null,'0','0','0');
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('45',null,'2','0','0');
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('5',null,'5','0','0');
Insert into ADEM.PRODUIT (IDP,NOMP,"QUANTIT�",PRIX,IDC) values ('78','guthei','0','0','0');
--------------------------------------------------------
--  DDL for Index ETUDIANT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."ETUDIANT_PK" ON "ADEM"."CATEGORIE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index COLI_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."COLI_PK" ON "ADEM"."COLI" ("IDCOLI") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index DEPARTEMENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."DEPARTEMENT_PK" ON "ADEM"."DEPARTEMENT" ("ID_DEPARTEMENT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOY�_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."EMPLOY�_PK" ON "ADEM"."EMPLOY�" ("CIN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FOURNISSEUR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."FOURNISSEUR_PK" ON "ADEM"."FOURNISSEUR" ("ID_FOURNISSEUR") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index LIVRAISON_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."LIVRAISON_PK" ON "ADEM"."LIVRAISON" ("IDLIV") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index LOGIN_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."LOGIN_PK" ON "ADEM"."LOGIN" ("MDP") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PRODUIT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."PRODUIT_PK" ON "ADEM"."MATIERE" ("ID_MATIERE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CATEGORIE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ADEM"."CATEGORIE_PK" ON "ADEM"."PRODUIT" ("IDP") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table CATEGORIE
--------------------------------------------------------

  ALTER TABLE "ADEM"."CATEGORIE" ADD CONSTRAINT "ETUDIANT_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "ADEM"."CATEGORIE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COLI
--------------------------------------------------------

  ALTER TABLE "ADEM"."COLI" ADD CONSTRAINT "COLI_PK" PRIMARY KEY ("IDCOLI")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "ADEM"."COLI" MODIFY ("IDCOLI" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table DEPARTEMENT
--------------------------------------------------------

  ALTER TABLE "ADEM"."DEPARTEMENT" MODIFY ("ID_DEPARTEMENT" NOT NULL ENABLE);
  ALTER TABLE "ADEM"."DEPARTEMENT" ADD CONSTRAINT "DEPARTEMENT_PK" PRIMARY KEY ("ID_DEPARTEMENT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table EMPLOY�
--------------------------------------------------------

  ALTER TABLE "ADEM"."EMPLOY�" MODIFY ("CIN" NOT NULL ENABLE);
  ALTER TABLE "ADEM"."EMPLOY�" ADD CONSTRAINT "EMPLOY�_PK" PRIMARY KEY ("CIN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table FOURNISSEUR
--------------------------------------------------------

  ALTER TABLE "ADEM"."FOURNISSEUR" ADD CONSTRAINT "FOURNISSEUR_PK" PRIMARY KEY ("ID_FOURNISSEUR")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "ADEM"."FOURNISSEUR" MODIFY ("ID_FOURNISSEUR" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LIVRAISON
--------------------------------------------------------

  ALTER TABLE "ADEM"."LIVRAISON" ADD CONSTRAINT "LIVRAISON_PK" PRIMARY KEY ("IDLIV")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "ADEM"."LIVRAISON" MODIFY ("IDLIV" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LOGIN
--------------------------------------------------------

  ALTER TABLE "ADEM"."LOGIN" ADD CONSTRAINT "LOGIN_PK" PRIMARY KEY ("MDP")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "ADEM"."LOGIN" MODIFY ("MDP" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MATIERE
--------------------------------------------------------

  ALTER TABLE "ADEM"."MATIERE" ADD CONSTRAINT "PRODUIT_PK" PRIMARY KEY ("ID_MATIERE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "ADEM"."MATIERE" MODIFY ("ID_MATIERE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PRODUIT
--------------------------------------------------------

  ALTER TABLE "ADEM"."PRODUIT" ADD CONSTRAINT "CATEGORIE_PK" PRIMARY KEY ("IDP")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "ADEM"."PRODUIT" MODIFY ("IDP" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table MATIERE
--------------------------------------------------------

  ALTER TABLE "ADEM"."MATIERE" ADD CONSTRAINT "PRODUIT_FK1" FOREIGN KEY ("ID_F")
	  REFERENCES "ADEM"."FOURNISSEUR" ("ID_FOURNISSEUR") ENABLE;
