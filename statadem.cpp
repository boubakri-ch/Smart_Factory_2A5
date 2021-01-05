#include "statadem.h"
#include "ui_statadem.h"

statadem::statadem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statadem)
{
    ui->setupUi(this);
}

statadem::~statadem()
{
    delete ui;
}
int statadem::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from produit where quantité BETWEEN '0' AND '99'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int statadem::Stat_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from produit where quantité BETWEEN '100' AND '500'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int statadem::Stat_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from produit where quantité BETWEEN '501' AND '10000'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void statadem::paintEvent(QPaintEvent *)
{

    int b=Stat_partie2();
    //cout<<b<<endl ;
    int c=Stat_partie3();
   // cout<<c<<endl ;
    int d=Stat_partie4();
    //cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-1000,this->width()-1000);

    painter.setBrush(Qt::yellow);
    painter.drawPie(size,0,16*y);
    //ui->label->setText("blue:1-100") ;
    painter.setBrush(Qt::white);
    painter.drawPie(size,16*y,16*m);
    //ui->label_2->setText("green:101-500") ;
    painter.setBrush(Qt::black);
    painter.drawPie(size,16*(m+y),16*z);
    //ui->label_3->setText("red:501-10000") ;

}
