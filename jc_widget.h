#ifndef JC_WIDGET_H
#define JC_WIDGET_H

#include <QWidget>
#include<QTextEdit>
#include<QStack>
#include<QString>
#include <QVector>

using namespace std;


namespace Ui {
class jc_Widget;
}

class jc_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit jc_Widget(QWidget *parent = 0);
        char current;//当前的符号
        int left = 0, right = 0;//左括号和右括号
        int lens = 0;//字符串长度
        int  hh=0;
        int mark;
        vector<char>jcys;//用于计算的表达式存放在这里,基础运算

    ~jc_Widget();

private slots:


private:
    Ui::jc_Widget *ui;
    QString ch=" ";

    //计算函数
    double calculate(int x, int y); //括号里的计算
    double operate(int start, int end);//读取操作数
    double judge(int start, double number, int y);//判断函数
    void solve(int x, int y, double num);


};

#endif // JC_WIDGET_H
