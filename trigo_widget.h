#ifndef TRIGO_WIDGET_H
#define TRIGO_WIDGET_H

#include <QWidget>

namespace Ui {
class Trigo_widget;
}

class Trigo_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Trigo_widget(QWidget *parent = 0);
    ~Trigo_widget();
    QString ch;         //获取按钮的字符串
    int flag;           //用于计算各函数的标志
    double num1,num2,result;//两个操作数以及运算结果
    int zhengfu_f;          //用于标明正负符号，=0表示正号，=1表示负号
    int position_f;         //用于表明操作数的位置，在前为0，在后为1

    void read(double num);
    void calculate();

private:
    Ui::Trigo_widget *ui;
};

#endif // TRIGO_WIDGET_H
