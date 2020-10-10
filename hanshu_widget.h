#ifndef HANSHU_WIDGET_H
#define HANSHU_WIDGET_H

#include <QWidget>

namespace Ui {
class hanshu_widget;
}

class hanshu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit hanshu_widget(QWidget *parent = 0);
    ~hanshu_widget();
    int flag=0;//选择某个函数的标志
    double x,x1,x2;//运算的结果



private slots:

    void on_radioButton_1yuan1c_clicked();

    void on_radioButton_fan_clicked();

    void on_radioButton_zhi_clicked();

    void on_radioButton_dui_clicked();

    void on_radioButton_1y2c_clicked();

    void on_btn_Calculate_clicked();

    void on_btn_ClearAll_clicked();

private:
    Ui::hanshu_widget *ui;
};

#endif // HANSHU_WIDGET_H
