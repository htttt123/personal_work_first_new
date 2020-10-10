#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <jc_widget.h>      //四则运算器头文件
#include <hanshu_widget.h>  //函数运算器头文件
#include <trigo_widget.h>   //三角函数运算器头文件
#include <jzzh_widget.h>    //进制转换运算器头文件
#include <jzys_widget.h>    //进制运算运算器头文件
#include <change_widget.h>  //今天是星期几运算器头文件

namespace Ui {
class main_widget;
}

class main_widget : public QWidget
{
    Q_OBJECT

public:
    explicit main_widget(QWidget *parent = 0);
    ~main_widget();


private:
    Ui::main_widget *ui;
};

#endif // MAIN_WIDGET_H
