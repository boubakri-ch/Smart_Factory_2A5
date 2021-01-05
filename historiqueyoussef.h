#ifndef HISTORIQUEYOUSSEF_H
#define HISTORIQUEYOUSSEF_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historiqueyoussef
{
    QString tmp;
public:
    historiqueyoussef();
    void saveyou(QString,QString);
        QString loadyou();
};

#endif // HISTORIQUEYOUSSEF_H
