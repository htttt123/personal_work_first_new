#include "jzzh_widget.h"
#include "ui_jzzh_widget.h"
#include <QDebug>

jzzh_widget::jzzh_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::jzzh_widget)
{
    ui->setupUi(this);
    resize(600,550);
    setWindowTitle("进制转换计算器");
    connect(ui->radioButton_10,&QRadioButton::clicked,
            [=]()
            {
                flag=1;
            });
    connect(ui->radioButton_2,&QRadioButton::clicked,
            [=]()
            {
                flag=2;
            });
    connect(ui->radioButton_8,&QRadioButton::clicked,
            [=]()
            {
                flag=3;
            });
    connect(ui->radioButton_16,&QRadioButton::clicked,
            [=]()
            {
                flag=4;
            });
    connect(ui->pushButton_c,&QPushButton::clicked,     //计算
            [=]()
            {
        if(flag==1)
        {
            QString ch=ui->lineEdit_10->text();         //十进制转换为其他进制
            bool ok;
            int a=ch.toInt(&ok,10);
            ch=ch.setNum(a,2);
            ui->lineEdit_2->setText(ch);
            ch=ch.setNum(a,8);
            ui->lineEdit_8->setText(ch);
            ch=ch.setNum(a,16);
            ui->lineEdit_16->setText(ch);
        }
        else if(flag==2)
        {
            QString ch=ui->lineEdit_2->text();      //二进制转换为其他进制
            bool ok;
            int a=ch.toInt(&ok,2);
            ch=ch.setNum(a,8);
            ui->lineEdit_8->setText(ch);
            ch=ch.setNum(a,10);
            ui->lineEdit_10->setText(ch);
            ch=ch.setNum(a,16);
            ui->lineEdit_16->setText(ch);
         }
        else if(flag==3)
         {
            QString ch=ui->lineEdit_8->text();          //八进制转换为其他进制
            bool ok;
            int a=ch.toInt(&ok,8);
            ch=ch.setNum(a,2);
            ui->lineEdit_2->setText(ch);
            ch=ch.setNum(a,10);
            ui->lineEdit_10->setText(ch);
            ch=ch.setNum(a,16);
            ui->lineEdit_16->setText(ch);
        }
        else if(flag==4)
        {
            QString ch=ui->lineEdit_16->text();         //十六进制转换为其他进制
            bool ok;
            int a=ch.toInt(&ok,16);
            ch=ch.setNum(a,2);
            ui->lineEdit_2->setText(ch);
            ch=ch.setNum(a,10);
            ui->lineEdit_10->setText(ch);
            ch=ch.setNum(a,8);
            ui->lineEdit_8->setText(ch);
       }
            });
    connect(ui->btn_clearall,&QPushButton::clicked,         //清空
            [=]()
            {
               flag=0;
               ui->lineEdit_2->setText("");
               ui->lineEdit_8->setText("");
               ui->lineEdit_10->setText("");
               ui->lineEdit_16->setText("");
            });
}

jzzh_widget::~jzzh_widget()
{
    delete ui;
}
