#ifndef HISTORIQUEF_H
#define HISTORIQUEF_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historiquef
{
    QString tmp;
public:
    historiquef();
    void savef(QString,QString);
        QString loadf();
};

#endif // HISTORIQUEF_H
