#ifndef JZZH_WIDGET_H
#define JZZH_WIDGET_H

#include <QWidget>

namespace Ui {
class jzzh_widget;
}

class jzzh_widget : public QWidget
{
    Q_OBJECT

public:
    explicit jzzh_widget(QWidget *parent = 0);
    ~jzzh_widget();
    int flag=0;
private:
    Ui::jzzh_widget *ui;
};

#endif // JZZH_WIDGET_H
