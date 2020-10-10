#include "jzys_widget.h"
#include "ui_jzys_widget.h"
#include <QTextEdit>
#include <qmath.h>
#include <QPushButton>

jzys_widget::jzys_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::jzys_widget)
{
    ui->setupUi(this);
    setWindowTitle("进制运算计算器");
}

jzys_widget::~jzys_widget()
{
    delete ui;
}

void jzys_widget::on_radioButton_12_clicked()       //操作数1的二进制
{
    flag1=1;
}

void jzys_widget::on_radioButton_18_clicked()       //操作数1的八进制
{
    flag1=2;
}

void jzys_widget::on_radioButton_10_clicked()       //操作数1的十进制
{
    flag1=3;
}

void jzys_widget::on_radioButton_16_clicked()       //操作数1的十六进制
{
    flag1=4;
}

void jzys_widget::on_radioButton_22_clicked()       //操作数2的二进制
{
    flag2=1;
}

void jzys_widget::on_radioButton_28_clicked()       //操作数2的八进制
{
    flag2=2;
}

void jzys_widget::on_radioButton_20_clicked()       //操作数2的十进制
{
    flag2=3;
}

void jzys_widget::on_radioButton_26_clicked()       //操作数2的十六进制
{
    flag2=4;
}

void jzys_widget::on_btn_add_clicked()              //加法
{
    operator_f=1;
    if(flag1==1)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,2);     //把二进制转化成十进制数
        num1=dec;
    }
    else if(flag1==2)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,8);     //把八进制转化成十进制数
        num1=dec;
    }
    else if(flag1==3)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,10);     //把十六进制转化成十进制数
        num1=dec;
    }
    else if(flag1==4)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,16);     //把十进制转化成十进制数
        num1=dec;
    }
}

void jzys_widget::on_btn_sub_clicked()              //减法
{
    operator_f=2;
    if(flag1==1)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,2);     //把二进制转化成十进制数
        num1=dec;
    }
    else if(flag1==2)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,8);     //把八进制转化成十进制数
        num1=dec;
    }
    else if(flag1==3)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,10);     //把十六进制转化成十进制数
        num1=dec;
    }
    else if(flag1==4)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,16);     //把十进制转化成十进制数
        num1=dec;
    }
}

void jzys_widget::on_btn_mult_clicked()             //乘法
{
    operator_f=3;
    if(flag1==1)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,2);     //把二进制转化成十进制数
        num1=dec;
    }
    else if(flag1==2)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,8);     //把八进制转化成十进制数
        num1=dec;
    }
    else if(flag1==3)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,10);     //把十六进制转化成十进制数
        num1=dec;
    }
    else if(flag1==4)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,16);     //把十进制转化成十进制数
        num1=dec;
    }
}

void jzys_widget::on_btn_div_clicked()              //除法
{
    operator_f=4;
    if(flag1==1)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,2);     //把二进制转化成十进制数
        num1=dec;
    }
    else if(flag1==2)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,8);     //把八进制转化成十进制数
        num1=dec;
    }
    else if(flag1==3)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,10);     //把十六进制转化成十进制数
        num1=dec;
    }
    else if(flag1==4)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,16);     //把十进制转化成十进制数
        num1=dec;
    }
}

void jzys_widget::on_btn_compare_clicked()          //比较
{
    if(flag1==1)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,2);     //把二进制转化成十进制数
        num1=dec;
    }
    else if(flag1==2)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,8);     //把八进制转化成十进制数
        num1=dec;
    }
    else if(flag1==3)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,10);     //把十六进制转化成十进制数
        num1=dec;
    }
    else if(flag1==4)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,16);     //把十进制转化成十进制数
        num1=dec;
    }
}

void jzys_widget::on_btn_max_clicked()              //最大公约数
{
    operator_f=5;
    if(flag1==1)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,2);     //把二进制转化成十进制数
        num1=dec;
    }
    else if(flag1==2)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,8);     //把八进制转化成十进制数
        num1=dec;
    }
    else if(flag1==3)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,10);     //把十六进制转化成十进制数
        num1=dec;
    }
    else if(flag1==4)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,16);     //把十进制转化成十进制数
        num1=dec;
    }
}

void jzys_widget::on_btn_min_clicked()             //最小公倍数
{
    operator_f=6;
    if(flag1==1)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,2);     //把二进制转化成十进制数
        num1=dec;
    }
    else if(flag1==2)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,8);     //把八进制转化成十进制数
        num1=dec;
    }
    else if(flag1==3)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,10);     //把十六进制转化成十进制数
        num1=dec;
    }
    else if(flag1==4)
    {
        bool ok;
        int dec=ui->lineEdit_num1->text().toInt(&ok,16);     //把十进制转化成十进制数
        num1=dec;
    }
}

void jzys_widget::on_btn_calculate1_clicked()           //四则运算
{
    if(flag2==1)
    {
        bool ok;
        int dec=ui->lineEdit_num2->text().toInt(&ok,2);     //把二进制转化成十进制数
        num2=dec;
        calculate1(num1,num2);
    }
    else if(flag2==2)
    {
        bool ok;
        int dec=ui->lineEdit_num2->text().toInt(&ok,8);     //把八进制转化成十进制数
        num2=dec;
        calculate1(num1,num2);
    }
    else if(flag2==3)
    {
        bool ok;
        int dec=ui->lineEdit_num2->text().toInt(&ok,16);     //把十六进制转化成十进制数
        num2=dec;
        calculate1(num1,num2);
    }
    else if(flag2==4)
    {
        bool ok;
        int dec=ui->lineEdit_num2->text().toInt(&ok,10);     //把十进制转化成十进制数
        num2=dec;
        calculate1(num1,num2);
    }
}

void jzys_widget::on_btn_calculate2_clicked()           //比较运算
{
    if(flag2==1)
    {
        bool ok;
        int dec=ui->lineEdit_num2->text().toInt(&ok,2);     //把二进制转化成十进制数
        num2=dec;
        calculate2(num1,num2);
    }
    else if(flag2==2)
    {
        bool ok;
        int dec=ui->lineEdit_num2->text().toInt(&ok,8);     //把八进制转化成十进制数
        num2=dec;
        calculate2(num1,num2);
    }
    else if(flag2==3)
    {
        bool ok;
        int dec=ui->lineEdit_num2->text().toInt(&ok,10);     //把十六进制转化成十进制数
        num2=dec;
        calculate2(num1,num2);
    }
    else if(flag2==4)
    {
        bool ok;
        int dec=ui->lineEdit_num2->text().toInt(&ok,16);     //把十进制转化成十进制数
        num2=dec;
        calculate2(num1,num2);
    }
}

void jzys_widget::on_btn_clearall_clicked()         //清空
{
    ui->lineEdit_num1->setText("");
    ui->lineEdit_num2->setText("");
    ui->lineEdit_two->setText("");
    ui->lineEdit_eight->setText("");
    ui->lineEdit_ten->setText("");
    ui->lineEdit_sixteen->setText("");
    ui->lineEdit_6->setText("");
    num1=0,num2=0,result=0;
    flag1=0,flag2=0;
    operator_f=0;
}

void jzys_widget::calculate1(int a, int b)      //四则运算
{
    switch (operator_f)
    {
     case 1:{
            result=a+b;
            ui->lineEdit_ten->setText(QString::number(result));
            int m=result;
            QString n=QString("%1").arg(m,0,2,QLatin1Char(' '));// 十进制转换为二进制
            ui->lineEdit_two->setText(n);
            QString n1=QString("%1").arg(m,0,8,QLatin1Char(' '));// 十进制转换为八进制
            ui->lineEdit_eight->setText(n1);
            QString n2=QString("%1").arg(m,0,16,QLatin1Char(' '));// 十进制转换为十六进制
            ui->lineEdit_sixteen->setText(n2);
           }
            break;
    case 2:{
            result=a-b;
            ui->lineEdit_ten->setText(QString::number(result));
            int m=result;
            QString n=QString("%1").arg(m,0,2,QLatin1Char(' '));// 十进制转换为二进制
            ui->lineEdit_two->setText(n);
            QString n1=QString("%1").arg(m,0,8,QLatin1Char(' '));// 十进制转换为八进制
            ui->lineEdit_eight->setText(n1);
            QString n2=QString("%1").arg(m,0,16,QLatin1Char(' '));// 十进制转换为十六进制
            ui->lineEdit_sixteen->setText(n2);
            }
            break;
    case 3:{
            result=a*b;
            ui->lineEdit_ten->setText(QString::number(result));
            int m=result;
            QString n=QString("%1").arg(m,0,2,QLatin1Char(' '));// 十进制转换为二进制
            ui->lineEdit_two->setText(n);
            QString n1=QString("%1").arg(m,0,8,QLatin1Char(' '));// 十进制转换为八进制
            ui->lineEdit_eight->setText(n1);
            QString n2=QString("%1").arg(m,0,16,QLatin1Char(' '));// 十进制转换为十六进制
            ui->lineEdit_sixteen->setText(n2);
           }
            break;
    case 4:{
            result=a/b;
            ui->lineEdit_ten->setText(QString::number(result));
            int m=result;
            QString n=QString("%1").arg(m,0,2,QLatin1Char(' '));// 十进制转换为二进制
            ui->lineEdit_two->setText(n);
            QString n1=QString("%1").arg(m,0,8,QLatin1Char(' '));// 十进制转换为八进制
            ui->lineEdit_eight->setText(n1);
            QString n2=QString("%1").arg(m,0,16,QLatin1Char(' '));// 十进制转换为十六进制
            ui->lineEdit_sixteen->setText(n2);
           }
            break;
    case 5:
    {
        int max;
        if(a<b)max=b;
        else max=a;
        for(int i=max;i<=(a)*(b);i++)
        {
            if((i%a==0)&&(i%b==0))
            {
                result=i;
                break;
            }
            else continue;
        }
        ui->lineEdit_ten->setText(QString::number(result));
        int m=result;
        QString n=QString("%1").arg(m,0,2,QLatin1Char(' '));// 十进制转换为二进制
        ui->lineEdit_two->setText(n);
        QString n1=QString("%1").arg(m,0,8,QLatin1Char(' '));// 十进制转换为八进制
        ui->lineEdit_eight->setText(n1);
        QString n2=QString("%1").arg(m,0,16,QLatin1Char(' '));// 十进制转换为十六进制
        ui->lineEdit_sixteen->setText(n2);
    }
    case 6:
    {
        int min;
        if(a<b)min=a;
        else min=b;
        for(int i=min;i>=1;i--)
        {
            if((a%i==0)&&(b%i==0))
            {
               result=i;
               break;
            }
            else continue;
        }
        ui->lineEdit_ten->setText(QString::number(result));
        int m=result;
        QString n=QString("%1").arg(m,0,2,QLatin1Char(' '));// 十进制转换为二进制
        ui->lineEdit_two->setText(n);
        QString n1=QString("%1").arg(m,0,8,QLatin1Char(' '));// 十进制转换为八进制
        ui->lineEdit_eight->setText(n1);
        QString n2=QString("%1").arg(m,0,16,QLatin1Char(' '));// 十进制转换为十六进制
        ui->lineEdit_sixteen->setText(n2);
    }
        break;
    }
}
void jzys_widget::calculate2(int a, int b)
{
    if(a>b)
       ui->lineEdit_6->setText(">");
    else if(a<b)
       ui->lineEdit_6->setText("<");
    else
       ui->lineEdit_6->setText("=");
}
