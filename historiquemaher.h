#ifndef HISTORIQUEMAHER_H
#define HISTORIQUEMAHER_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historiquemaher
{
    QString tmp;
public:
    historiquemaher();
    void savemaher(QString,QString);
        QString loadmaher();
};

#endif // HISTORIQUEMAHER_H
