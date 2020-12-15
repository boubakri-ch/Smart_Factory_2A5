QT       += core gui multimedia printsupport serialport network
QT +=sql
QT += widgets multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RC_ICONS = cinemapp.ico
SOURCES += \
    arduino.cpp \
    connection.cpp \
    fournisseur.cpp \
    historique.cpp \
    main.cpp \
    mainwindow.cpp \
    produit.cpp \
    statistique.cpp

HEADERS += \
    arduino.h \
    connection.h \
    fournisseur.h \
    historique.h \
    mainwindow.h \
    produit.h \
    statistique.h

FORMS += \
    mainwindow.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QMAKE_CXXFLAGS += -std=gnu++11
TARGET =test_son
TEMPLATE =app

RESOURCES += \
    photo.qrc \
    son.qrc
