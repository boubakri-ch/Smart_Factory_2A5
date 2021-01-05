#include "arduinoad.h"
#include <QDebug>
arduinoad::arduinoad()
{

}
QString arduinoad::getArduino_port_name()
{
    return arduino_prot_name;
}
QSerialPort* arduinoad::getserial()
{
    return serial;
}
int arduinoad::connect_arduino()
{
    foreach (const QSerialPortInfo& serial_port_info,QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() ==arduino_uno_product_id)
            {
               arduino_is_available=true;
               arduino_prot_name=serial_port_info.portName();
            }
        }
    }
    qDebug()<<"arduino port name :"<<arduino_prot_name;
    if(arduino_is_available)
    {
        serial->setPortName(arduino_prot_name);
        if(serial->open(QSerialPort::ReadWrite))
        {
           serial->setBaudRate(QSerialPort::Baud9600);
           serial->setDataBits(QSerialPort::Data8);
           serial->setParity(QSerialPort::NoParity);
           serial->setStopBits(QSerialPort::OneStop);
           serial->setFlowControl(QSerialPort::NoFlowControl);
           return 0;
        }
        return 1;
    }
    return -1;
}
int arduinoad::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}
int arduinoad::write_to_arduino(QByteArray d)
{
    if(serial->isWritable())
    {
        serial->write(d);
    }
    else
        qDebug()<<"error en ecriture";
}
QByteArray arduinoad::read_from_arduino()
{
    if(serial->isReadable())
    {
        data=serial->readAll();
        return data;
    }
}
