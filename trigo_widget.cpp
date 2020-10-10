#include "trigo_widget.h"
#include "ui_trigo_widget.h"
#include <qmath.h>
#include<QDebug>
#define PI 3.14159265358979323846
#define E 2.71828182845904523536
Trigo_widget::Trigo_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Trigo_widget)
{
    ui->setupUi(this);
    resize(653,541);
    setWindowTitle("三角函数计算器");
    num1=0;
    num2=0;
    result=0;
    position_f=0;
    zhengfu_f=0;
    connect(ui->pushButton_0,&QPushButton::clicked,
            [=]()
            {
               ch+='0';
               ui->textEdit->setText(ch);
               read(0);
            }
            );
    connect(ui->pushButton_1,&QPushButton::clicked,
            [=]()
            {
               ch+='1';
               ui->textEdit->setText(ch);
               read(1);
            }
            );
    connect(ui->pushButton_2,&QPushButton::clicked,
            [=]()
            {
               ch+='2';
               ui->textEdit->setText(ch);
               read(2);
            }
            );
    connect(ui->pushButton_3,&QPushButton::clicked,
            [=]()
            {
               ch+='3';
               ui->textEdit->setText(ch);
               read(3);
            }
            );
    connect(ui->pushButton_4,&QPushButton::clicked,
            [=]()
            {
               ch+='4';
               ui->textEdit->setText(ch);
               read(4);
            }
            );
    connect(ui->pushButton_5,&QPushButton::clicked,
            [=]()
            {
               ch+='5';
               ui->textEdit->setText(ch);
               read(5);
            }
            );
    connect(ui->pushButton_6,&QPushButton::clicked,
            [=]()
            {
               ch+='6';
               ui->textEdit->setText(ch);
               read(6);
            }
            );
    connect(ui->pushButton_7,&QPushButton::clicked,
            [=]()
            {
               ch+='7';
               ui->textEdit->setText(ch);
               read(7);
            }
            );
    connect(ui->pushButton_8,&QPushButton::clicked,
            [=]()
            {
               ch+='8';
               ui->textEdit->setText(ch);
               read(8);
            }
            );
    connect(ui->pushButton_9,&QPushButton::clicked,
            [=]()
            {
               ch+='9';
               ui->textEdit->setText(ch);
               read(9);
            }
            );
    connect(ui->btn_cos,&QPushButton::clicked,
            [=]()
            {
               ch+="cos";
               ui->textEdit->setText(ch);
               position_f=1;
               flag=0;
            }
            );
    connect(ui->btn_sin,&QPushButton::clicked,
            [=]()
            {
               ch+="sin";
               ui->textEdit->setText(ch);
               position_f=1;
               flag=1;
            }
            );
    connect(ui->btn_tan,&QPushButton::clicked,
            [=]()
            {
               ch+="tan";
               ui->textEdit->setText(ch);
               position_f=1;
               flag=2;
            }
            );
    connect(ui->btn_1_x,&QPushButton::clicked,
            [=]()
            {
               ch+="1/";
               ui->textEdit->setText(ch);
               position_f=1;
               flag=3;
            }
            );
    connect(ui->btn_2_x,&QPushButton::clicked,
            [=]()
            {
               ch+="²√";
               ui->textEdit->setText(ch);
               position_f=1;
               flag=4;
            }
            );
    connect(ui->btn_ln,&QPushButton::clicked,
            [=]()
            {
               ch+="ln";
               ui->textEdit->setText(ch);
               position_f=1;
               flag=5;
            }
            );
    connect(ui->btn_log,&QPushButton::clicked,
            [=]()
            {
               ch+="lg";
               ui->textEdit->setText(ch);
               position_f=1;
               flag=6;
            }
            );
    connect(ui->btn_pi,&QPushButton::clicked,
            [=]()
            {
               ch+="Π";
               ui->textEdit->setText(ch);
               if(position_f==0){
                   num1=PI;
               }
               else num2=PI;
            }
            );
    connect(ui->btn_e,&QPushButton::clicked,
            [=]()
            {
               ch+='e';
               ui->textEdit->setText(ch);
               if(position_f==0){
                   num1=E;
               }
               else num2=E;
            }
            );
    connect(ui->btn_x_y,&QPushButton::clicked,
            [=]()
            {
               ch+='^';
               ui->textEdit->setText(ch);
               flag=7;
               position_f=1;
            }
            );
    connect(ui->btn_zhengfu,&QPushButton::clicked,  // +/-
            [=]()
            {
                if(position_f==0)
                {
                    ch+='-';
                    ui->textEdit->setText(ch);
                    zhengfu_f=1;
                }
                else
                {
                    ch+="(-)";
                    ui->textEdit->setText(ch);
                    zhengfu_f=1;
                }

            });
    connect(ui->btn_CE,&QPushButton::clicked,       //清空
            [=]()
            {
                ch="";
                ui->textEdit->setText(ch);
                num1=0;
                num2=0;
                result=0;
                position_f=0;
                zhengfu_f=0;
            }
            );
    connect(ui->btn_backspace,&QPushButton::clicked,    //退格
            [=]()
            {
               ch=ch.left(ch.length()-1);
               ui->textEdit->setText(ch);
               if(position_f==0&&num1!=0)
               {
                   int m=num1/10;
                   num1=m;
                }
               else if(position_f==1&&num2!=0)
                {
                   double m=num2/10;
                   num2=m;
                }
               else
                   zhengfu_f=0;
            }
            );
    connect(ui->btn_equal,&QPushButton::clicked,    //=
            [=]()
            {
               ch+='=';
               ui->textEdit->setText(ch);
               if(position_f==0)
               {
                   QString c=QString::number(num1);
                   ch+=c;
                   ui->textEdit->setText(ch);
               }
               else
               {
                   calculate();
                   zhengfu_f=0;
                   ui->textEdit->setText(ch);
               }
            }
            );



}
Trigo_widget::~Trigo_widget()
{
    delete ui;
}

void Trigo_widget::read(double num)
{
    if(position_f==0&&zhengfu_f==0)
        num1=num1*10+num;
    else if(position_f==0&&zhengfu_f==1)
        num1=-num1*10-num;
    else if(position_f==1&&zhengfu_f==0)
        num2=num2*10+num;
    else if(position_f==1&&zhengfu_f==1)
        num2=-num2*10-num;
}

void Trigo_widget::calculate()
{
    switch (flag) {
    case 0:
        num1=0;
        result=cos(num2);
        if(num2==PI)
            result=-1;
        break;
    case 1:
        num1=0;
        result=sin(num2);
        //qDebug()<<result;
        if(num2==PI)
            result=0;
        break;
    case 2:
        num1=0;
        result=tan(num2);
        break;
    case 3:
        num1=0;
        result=1/num2;                  //1/num2
        //qDebug()<<result;
        break;
    case 4:
        num1=0;
        result=sqrt(num2);              //²√ num2
        //qDebug()<<result;
        break;
    case 5:
        num1=0;
        result=qLn(num2)/qLn(E);        //ln num2
        //qDebug()<<result;
        break;
    case 6:
        num1=0;
        result=qLn(num2)/qLn(10);       //log num2
        //qDebug()<<result;
        break;
    case 7:
        result=qPow(num1,num2);         //num1^num2
        //qDebug()<<result;
        break;
    }
    ch+=QString::number(result,'g');
}


