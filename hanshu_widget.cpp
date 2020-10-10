#include "hanshu_widget.h"
#include "ui_hanshu_widget.h"
#include <Qmath.h>
#include<QDebug>
hanshu_widget::hanshu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hanshu_widget)
{
    ui->setupUi(this);
    setWindowTitle("函数计算器");

}

hanshu_widget::~hanshu_widget()
{
    delete ui;
}

void hanshu_widget::on_radioButton_1y2c_clicked()
{
    flag=1;
}

void hanshu_widget::on_radioButton_1yuan1c_clicked()
{
    flag=2;
}

void hanshu_widget::on_radioButton_fan_clicked()
{
    flag=3;
}

void hanshu_widget::on_radioButton_zhi_clicked()
{
    flag=4;
}

void hanshu_widget::on_radioButton_dui_clicked()
{
    flag=5;
}

void hanshu_widget::on_btn_Calculate_clicked()
{
    if(flag==1)                                     //一元二次函数
    {
        double a=ui->LE_1y2c_a->text().toDouble();
        double b=ui->LE_1y2c_b->text().toDouble();
        double c=ui->LE_1y2c_c->text().toDouble();
        double d=ui->LE_1y2c_d->text().toDouble();
        double m=c-d;
        double drta=b*b-4*a*m;
        double n=sqrt(drta);
        if(drta>0)
        {
            x1=((-1)*b+n)/(2*a);//根1
            x2=((-1)*b-n)/(2*a);//根2
            ui->lineEdit_one_x1->setText(QString::number(x1));
            ui->lineEdit_one_x2->setText(QString::number(x1));
        }
        else if(drta==0)
        {
            x1=x2=((-1)*b)/(2*a);
            ui->lineEdit_one_x1->setText(QString::number(x1));
            ui->lineEdit_one_x2->setText(QString::number(x1));
        }
        else
        {
            ui->lineEdit_one_error->setText("无解！");
        }
    }
    else if(flag==2)                                //一元一次函数
    {
        double a=ui->LE_1y1c_a->text().toDouble();
        double b=ui->LE_1y1c_b->text().toDouble();
        double c=ui->LE_1y1c_c->text().toDouble();
        double m=c-b;
        x=m/a;
        ui->lineEdit_two_x->setText(QString::number(x));
    }
    else if(flag==3)                //反比例函数
    {
        double a=ui->LE_fan_a->text().toDouble();
        double b=ui->LE_fan_b->text().toDouble();
        x=a/b;
        ui->lineEdit_three_x->setText(QString::number(x));
    }
    else if(flag==4)                //指数函数
    {
        double a=ui->LE_zhi_a->text().toDouble();
        double b=ui->LE_zhi_b->text().toDouble();
        x=qLn(b)/qLn(a);
        ui->lineEdit_four_x->setText(QString::number(x));
    }
    else                            //对数函数
    {
        double a=ui->LE_dui_a->text().toDouble();
        double b=ui->LE_dui_b->text().toDouble();
        x=qPow(a,b);

        ui->lineEdit_five_x->setText(QString::number(x));
    }

}

void hanshu_widget::on_btn_ClearAll_clicked()           //清除数据
{
    flag=0;
    x=0,x1=0,x2=0;
    ui->LE_1y2c_a->setText("");
    ui->LE_1y2c_b->setText("");
    ui->LE_1y2c_c->setText("");
    ui->LE_1y2c_d->setText("");
    ui->LE_1y1c_a->setText("");
    ui->LE_1y1c_b->setText("");
    ui->LE_1y1c_c->setText("");
    ui->LE_fan_a->setText("");
    ui->LE_fan_b->setText("");
    ui->LE_zhi_a->setText("");
    ui->LE_zhi_b->setText("");
    ui->LE_dui_a->setText("");
    ui->LE_dui_b->setText("");
    ui->lineEdit_one_x1->setText("");
    ui->lineEdit_one_x2->setText("");
    ui->lineEdit_one_error->setText("");
    ui->lineEdit_two_x->setText("");
    ui->lineEdit_three_x->setText("");
    ui->lineEdit_four_x->setText("");
    ui->lineEdit_five_x->setText("");

}
