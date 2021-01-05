#ifndef HISTORIQUEMALTH_H
#define HISTORIQUEMALTH_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historiquemalth
{
    QString tmp;
public:
    historiquemalth();
    void savemalhus(QString,QString);
        QString loadmalthus();
};

#endif // HISTORIQUEMALTH_H
