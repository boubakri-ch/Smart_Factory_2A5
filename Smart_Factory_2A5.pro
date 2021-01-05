QT       += core gui sql printsupport serialport multimedia widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduinoad.cpp \
    arduinoadem.cpp \
    categorie.cpp \
    client.cpp \
    coli.cpp \
    connection.cpp \
    departement.cpp \
    employe.cpp \
    formateur.cpp \
    formation.cpp \
    fournisseur.cpp \
    historique.cpp \
    historiquef.cpp \
    historiquemaher.cpp \
    historiquemalth.cpp \
    historiqueyassine.cpp \
    historiqueyoussef.cpp \
    intervention.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp \
    matierepremiere.cpp \
    produit.cpp \
    statadem.cpp \
    statistique.cpp \
    statmaher.cpp \
    statmalthus.cpp \
    stattatar.cpp \
    statyassine.cpp

HEADERS += \
    arduinoad.h \
    arduinoadem.h \
    categorie.h \
    client.h \
    coli.h \
    connection.h \
    departement.h \
    employe.h \
    formateur.h \
    formation.h \
    fournisseur.h \
    historique.h \
    historiquef.h \
    historiquemaher.h \
    historiquemalth.h \
    historiqueyassine.h \
    historiqueyoussef.h \
    intervention.h \
    login.h \
    mainwindow.h \
    materiel.h \
    matierepremiere.h \
    produit.h \
    statadem.h \
    statistique.h \
    statmaher.h \
    statmalthus.h \
    stattatar.h \
    statyassine.h

FORMS += \
    arduinoadem.ui \
    mainwindow.ui \
    statadem.ui \
    statistique.ui \
    statmaher.ui \
    statmalthus.ui \
    stattatar.ui \
    statyassine.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
