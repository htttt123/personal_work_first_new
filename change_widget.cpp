#include "change_widget.h"
#include "ui_change_widget.h"
#include<QDebug>
change_widget::change_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_widget)
{
    ui->setupUi(this);
    setWindowTitle("今天是星期几？");
    resize(600,550);

}

int change_widget::pd1(int y,int m,int d)           //计算所给定日期距离该年第一天的天数
   {
       int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};      //每月的天数
       if((y<=1582) && (y%4) )                //1582年之前使用朱利安规则
          a[2]++;
       else if((y> 1582) && (y%4== 0 && y%100) || (y%400== 0) )  //1582年之后使用格里高利规则
          a[2]++;
       if(d> 0 && d<= a[m])         //确定二月份的天数
          {
             int sum= 0;
             for(int i= 1; i< y; i++)
               {
                  if(i<= 1582)
                    {
                       if(i%4==0)
                        {
                           sum+= 366;
                         }
                        else
                            sum+= 365;
                    }
                  else
                  {
                    if( (i%4== 0 && i%100) || (i%400== 0) )
                       sum+= 366;
                    else
                       sum+= 365;
                   }
               }
              for(int i= 1; i< m; i++)
                   sum+= a[i];
               sum+= d;
              return sum;
          }
          return 0;
    }

  change_widget::~change_widget()
  {
      delete ui;
  }

void change_widget::on_btn_calculate_clicked()      //计算出结果
{
    char b[7][10] = {"Sunday","Monday","Tuesday","Wednesday",
    "Thursday","Friday","Saturday"};

    int y=ui->lineEdit_y->text().toInt();
    int m=ui->lineEdit_m->text().toInt();
    int d=ui->lineEdit_d->text().toInt();
    while(y+m+d)
    {
        int sum= pd1(y,m,d);
        if(!sum)
        {
            ui->lineEdit_3->setText("is an invalid date.");
            continue;
        }
        int flag= 0;
        if(y>1752)
        {
            flag= 1;
        }
        else if(y==1752)
        {
            if(m > 9)
                flag= 1;
            else if(m==9)
            {
                if(d>= 14)
                    flag= 1;
            }
        }
        //判断改天是在星期修改前还是修改后
        if(flag==0)
        {
            // 1年1月1日为星期日
            int w= (sum -1)% 7;
            //qDebug()<<w;
            if(w==0) ui->lineEdit_3->setText("Sunday");
            else if(w==1) ui->lineEdit_3->setText("Monday");
            else if(w==2) ui->lineEdit_3->setText("Tuesday");
            else if(w==3) ui->lineEdit_3->setText("Wednesday");
            else if(w==4) ui->lineEdit_3->setText("Thursday");

            else if(w==5) ui->lineEdit_3->setText("Friday");
            else ui->lineEdit_3->setText("Saturday");
            break;

        }
        else
        {
            //当日子为 1752年9月14日时，函数返回639809天,此时为星期四
            int w= (sum- 639805) % 7;
            //qDebug()<<w;
            if(w==0) ui->lineEdit_3->setText("Sunday");
            else if(w==1) ui->lineEdit_3->setText("Monday");
            else if(w==2) ui->lineEdit_3->setText("Tuesday");
            else if(w==3) ui->lineEdit_3->setText("Wednesday");
            else if(w==4) ui->lineEdit_3->setText("Thursday");
            else if(w==5) ui->lineEdit_3->setText("Friday");
            else ui->lineEdit_3->setText("Saturday");
            break;
        }
      }

}

void change_widget::on_btn_clearall_clicked()   //清空
{
    ui->lineEdit_y->setText("");
    ui->lineEdit_m->setText("");
    ui->lineEdit_d->setText("");
    ui->lineEdit_3->setText("");
}
