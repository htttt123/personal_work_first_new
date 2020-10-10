#include "main_widget.h"
#include "ui_main_widget.h"
#include <jc_widget.h>      //四则运算器头文件
#include <hanshu_widget.h>  //函数运算器头文件
#include <trigo_widget.h>   //三角函数运算器头文件
#include <jzzh_widget.h>    //进制转换运算器头文件
#include <jzys_widget.h>    //进制运算运算器头文件


main_widget::main_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main_widget)
{
    ui->setupUi(this);
    resize(600,550);
    setWindowTitle("计算器");
    connect(ui->btn_jc,&QPushButton::clicked,
            [=]()
            {
              jc_Widget *w=new jc_Widget();
              w->show();
             }
             );
    connect(ui->btn_hanshu,&QPushButton::clicked,
            [=]()
            {
              hanshu_widget *w=new hanshu_widget();
              w->show();
             }
             );
    connect(ui->btn_trigo,&QPushButton::clicked,
            [=]()
            {
              Trigo_widget *w=new Trigo_widget();
              w->show();
             }
             );
    connect(ui->btn_jzzh,&QPushButton::clicked,
            [=]()
            {
              jzzh_widget *w=new jzzh_widget();
              w->show();
             }
             );
    connect(ui->btn_jzys,&QPushButton::clicked,
            [=]()
            {
                jzys_widget *w=new jzys_widget();
                w->show();
            }
            );
    connect(ui->btn_week,&QPushButton::clicked,
            [=]()
            {
                change_widget *w=new change_widget();
                w->show();
            }
            );
}

main_widget::~main_widget()
{
    delete ui;
}
