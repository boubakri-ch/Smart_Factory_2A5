#ifndef ARDUINOAD_H
#define ARDUINOAD_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class arduinoad
{
public:
    arduinoad();
    int connect_arduino();
        int close_arduino();
        int write_to_arduino(QByteArray);
        QByteArray read_from_arduino();
        QSerialPort* getserial();
        QString getArduino_port_name();
private:
    QSerialPort* serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_product_id=67;
    QString arduino_prot_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // ARDUINOAD_H
