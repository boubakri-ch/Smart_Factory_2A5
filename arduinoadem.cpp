#include "arduinoadem.h"
#include "ui_arduinoadem.h"
#include <QDebug>
arduinoadem::arduinoadem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduinoadem)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
    switch(ret)
        {
        case (0):qDebug()<<"arduino is available and connected to:"<<A.getArduino_port_name();
            break;
        case (1):qDebug()<<"arduino is availabe but not connected to:"<<A.getArduino_port_name();
            break;
        case(-1):qDebug()<<"arduino is not available";
        }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

arduinoadem::~arduinoadem()
{
    delete ui;
}


void arduinoadem::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")
        ui->label->setText("ON");
    else if(data=="0")
        ui->label->setText("OFF");
}

void arduinoadem::on_on1_clicked()
{
    A.write_to_arduino("1");
}

void arduinoadem::on_off1_clicked()
{
    A.write_to_arduino("0");
}

void arduinoadem::on_on2_clicked()
{
    A.write_to_arduino("2");
}

void arduinoadem::on_off2_clicked()
{
    A.write_to_arduino("3");
}

void arduinoadem::on_on3_clicked()
{
    A.write_to_arduino("4");
}

void arduinoadem::on_off3_clicked()
{
    A.write_to_arduino("5");
}
