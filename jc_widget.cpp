#include "jc_widget.h"
#include "ui_jc_widget.h"
#include<QTextEdit>

#include<qmath.h>
#include<QStack>
#include<QVector>


jc_Widget::jc_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::jc_Widget)
{
    ui->setupUi(this);
    resize(600,550);
    setWindowTitle("四则运算器");
    connect(ui->btn_0,&QPushButton::clicked,
            [=]()
            {
        current ='0';
        jcys.push_back(current);
        ch +='0';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_1,&QPushButton::clicked,
            [=]()
            {
               current ='1';
               jcys.push_back(current);
               ch +='1';
               lens++;
               ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_2,&QPushButton::clicked,
            [=]()
            {
        current ='2';
        jcys.push_back(current);
        ch +='2';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_3,&QPushButton::clicked,
            [=]()
            {
        current ='3';
        jcys.push_back(current);
        ch +='3';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_4,&QPushButton::clicked,
            [=]()
            {
        current ='4';
        jcys.push_back(current);
        ch +='4';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_5,&QPushButton::clicked,
            [=]()
            {
        current ='5';
        jcys.push_back(current);
        ch +='5';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_6,&QPushButton::clicked,
            [=]()
            {
        current ='6';
        jcys.push_back(current);
        ch +='6';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_7,&QPushButton::clicked,
            [=]()
            {
        current ='7';
        jcys.push_back(current);
        ch +='7';
        lens++;
        ui->textEdit->setText(ch);
              }
            );
    connect(ui->btn_8,&QPushButton::clicked,
            [=]()
            {
        current ='8';
        jcys.push_back(current);
        ch +='8';
        lens++;
        ui->textEdit->setText(ch);
              }
            );
    connect(ui->btn_9,&QPushButton::clicked,
            [=]()
            {
        current ='9';
        jcys.push_back(current);
        ch +='9';
        lens++;
        ui->textEdit->setText(ch);
           }
            );


//按钮运算符*/+-
    connect(ui->btn_multS,&QPushButton::clicked,
            [=]()
            {
        current ='*';
        jcys.push_back(current);
        ch +='*';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_divS,&QPushButton::clicked,
            [=]()
            {
        current ='/';
        jcys.push_back(current);
        ch +='/';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_andS,&QPushButton::clicked,
            [=]()
            {
        current ='+';
        jcys.push_back(current);
        ch +='+';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_subS,&QPushButton::clicked,
            [=]()
            {
        current ='-';
        jcys.push_back(current);
        ch +='-';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_leftk,&QPushButton::clicked,
            [=]()
            {
        current ='(';
        jcys.push_back(current);
        ch +='(';
        lens++;
        left++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_rightk,&QPushButton::clicked,
            [=]()
            {
        current =')';
        jcys.push_back(current);
        ch +=')';
        lens++;
        right++;
        ui->textEdit->setText(ch);
             }
            );

    connect(ui->btn_point,&QPushButton::clicked,
            [=]()
            {
        current ='.';
        jcys.push_back(current);
        ch +='.';
        lens++;
        ui->textEdit->setText(ch);
             }
            );
    connect(ui->btn_clear,&QPushButton::clicked,
            [=]()
            {
         ch="";
         ui->textEdit->setText(ch);
                 left = 0;
                 right = 0;
                 lens = 0;
                 mark=0;
                 jcys.clear();
             }
            );
    connect(ui->btn_backspace,&QPushButton::clicked,
            [=]()
            {
        jcys.erase(jcys.end() - 1 );
        lens--;
        ch =ch.left(ch.length()-1);                                          //减去一字符
        ui->textEdit->setText(ch);
        if(lens<=-2)
        {
            ch="";
             ui->textEdit->setText(ch);
                     left = 0;
                     right = 0;
                     lens = 0;
                     mark=0;
                     jcys.clear();
        }
            }
            );
    connect(ui->btn_equalS,&QPushButton::clicked,
            [=]()
            {
        current = '=';
        jcys.push_back(current);
        if (hh == 0)
           {
               hh = 1;
               jcys.push_back(' ');
            }
        lens++;
        ch += '=';
        ui->textEdit->setText(ch);
        int i, j;
        double rs;
        if (left != right)
        {
            ch=ch+"=Error!";
             ui->textEdit->setText(ch);
        }
        else
            while (left > 0)
            {
            for (i = 0; i < lens; i++)
                if (jcys[i] == '(')
                {

                for (j = i; j <= lens; j++)
                    if (jcys[j] == ')')
                    {

                    calculate(i + 1, j-1);

                    break;
                    }

                break;
                }
            left--;
            right--;
            }

        if (left == 0 && right == 0)
            rs = calculate(0, lens);
        ch=ch+QString::number(rs);

         ui->textEdit->setText(ch);
             }
            );

}
jc_Widget::~jc_Widget()
{
    delete ui;
}


double jc_Widget::calculate(int x, int y)
{
    int starts, start;                        //起点
    start = x;
    mark = x;                                //数字的结尾
    double num1, num2, num3;

    num1 = operate(start, y);                //初始化num1
    start = mark;
    starts = start;                              //最初的起点

    while (mark < y)
    {

        start ++;
        num2 = operate(start, y);
        start = mark;

        if (jcys[start] == '*' || jcys[start] == '/')
        {
            start++;
            num2 = judge(start , num2, y);
            start = mark;
        }


            if (jcys[starts] == '+')
                num1 = num1 + num2;
            else if (jcys[starts] == '-')
                    num1 = num1 - num2;
            else if (jcys[starts] == '*')
                        num1 = num1 * num2;
            else if (jcys[starts] == '/')
                            num1 = num1 /(int) num2;
             starts = mark;

             num3 = num1;

        if (jcys[mark + 1] == '='||jcys[mark]=='=')
            break;

     }
    if (left!=0)
        solve(x-1, y+1, num3);

    return num3;
}

double jc_Widget::operate(int start, int end)
{
    string num = "";
    double temp;
    while ((jcys[start] >= '0'&&jcys[start]<='9') || jcys[start] == '.')
    {
        num += jcys[start];
        start++;                //下一个字符
        mark = start;
                              //记录下数字后一个的位置
    }
    temp = atof(num.c_str());        //字符串转double

    return temp;

}

double jc_Widget::judge(int start, double number, int y)
{
    double num3;
    if (jcys[start-1] == '*')             //前一个符号
    {
        num3 = operate(start, y);
        start = mark;
        num3 = number*num3;
    }
    else
    {
        num3 = operate(start, y);
        start = mark;
        num3 = number / (int)num3;
    }

    if (jcys[start] == '*' || jcys[start] == '/')
        num3 = judge(start+1, num3,y);

    return num3;
}

void jc_Widget::solve(int x, int y, double num)
{
    QString b=QString::number(num);

    QByteArray cpath = b.toLocal8Bit();
    char*buffer = cpath.data();

    int len;
    len = strlen(buffer);
    jcys.erase(jcys.begin() + x, jcys.begin() + y+1);
    lens = lens - y + x;

    for (int i = 0; i < len; i++)
    {
        jcys.insert(jcys.begin() + x, buffer[i]);
        lens++;
        x++;
    }

    return ;
}


