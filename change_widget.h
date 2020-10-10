#ifndef CHANGE_WIDGET_H
#define CHANGE_WIDGET_H

#include <QWidget>

namespace Ui {
class change_widget;
}

class change_widget : public QWidget
{
    Q_OBJECT

public:
    explicit change_widget(QWidget *parent = 0);
    ~change_widget();
    int pd1(int y,int m,int d);

private slots:


    void on_btn_calculate_clicked();

    void on_btn_clearall_clicked();

private:
    Ui::change_widget *ui;
};

#endif // CHANGE_WIDGET_H
