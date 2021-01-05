#include "historiquef.h"

historiquef::historiquef()
{

}
void historiquef::savef(QString type,QString req)
{    QFile file ("C:/Users/Maher/Desktop/Smart_Factory_2A5/hisf.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << type+"\n"+req << "\n";


}
QString historiquef::loadf()
{   tmp="";
    QFile file("C:/Users/Maher/Desktop/Smart_Factory_2A5/hisf.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();  // readline automatically removes the EOL
         tmp+=myString+"\n";

   }
   return tmp;
}
