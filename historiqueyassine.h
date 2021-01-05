#ifndef HISTORIQUEYASSINE_H
#define HISTORIQUEYASSINE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historiqueyassine
{
    QString tmp;
public:
    historiqueyassine();
    void saveyass(QString,QString);
        QString loadyass();
};

#endif // HISTORIQUEYASSINE_H
