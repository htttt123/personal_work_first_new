#ifndef JZYS_WIDGET_H
#define JZYS_WIDGET_H

#include <QWidget>

namespace Ui {
class jzys_widget;
}

class jzys_widget : public QWidget
{
    Q_OBJECT

public:
    explicit jzys_widget(QWidget *parent = 0);
    ~jzys_widget();
    int num1=0,num2=0,result=0;
    int flag1=0,flag2=0;
    int operator_f=0;
    void calculate1(int a,int b);       //四则运算函数
    void calculate2(int a,int b);       //比较运算函数
private slots:
    void on_radioButton_12_clicked();

    void on_radioButton_18_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_16_clicked();

    void on_radioButton_22_clicked();

    void on_radioButton_28_clicked();

    void on_radioButton_20_clicked();

    void on_radioButton_26_clicked();

    void on_btn_add_clicked();

    void on_btn_sub_clicked();

    void on_btn_mult_clicked();

    void on_btn_div_clicked();

    void on_btn_compare_clicked();

    void on_btn_max_clicked();

    void on_btn_min_clicked();

    void on_btn_calculate1_clicked();

    void on_btn_calculate2_clicked();

    void on_btn_clearall_clicked();

private:
    Ui::jzys_widget *ui;
};

#endif // JZYS_WIDGET_H
