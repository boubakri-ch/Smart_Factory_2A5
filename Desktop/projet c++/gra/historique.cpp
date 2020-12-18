#include "historique.h"


Historique::Historique()
{

}
void Historique::save(QString id,QString quantiter)
{    QFile file ("C:/Users/Chiheb/Desktop/projet c++/gra/histo.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << id+"\n"+quantiter << "\n";


}
QString Historique::load()
{   tmp="";
    QFile file("C:/Users/Chiheb/Desktop/projet c++/gra/histo.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();  // readline automatically removes the EOL
         tmp+=myString+"\n";

   }
   return tmp;
}
