#include "widget.h"
#include "ui_widget.h"
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <QPushButton>
#define random(a,b) (rand()%(b-a+1))+a
int psm,pdm;
double pwm;
int saleamount;
double sumprice;
int alldate[13];
int allweight[16];
int allspiece[4];
struct pig{
    int spiece;
    double weight;
    int days;
    pig *next;
    int ipig;
};
class pigcircle{
    private:
        int sum;
        int ifblack;
        int number;
        int is;
    public:
        pig *head;
        pigcircle();
        int getnumber();
        int getsum();
        int getifblack();
        int getis();
        void sendnumber(int i);
        void sendsum(int i);
        void sendifblack(int i);
        void sendis(int i);
        int  searchspiece(int i);
        int  searchdays(int i);
        double searchweight(int i);
        void sale();
        void insert(pig *p);
};
pigcircle::pigcircle()
{
    sum=0;
    ifblack=0;
    number=0;
    is=0;
}
int pigcircle::getsum()
{
    return sum;
 }
int pigcircle::getnumber()
{
    return number;
}
int pigcircle::getifblack()
{
    return ifblack;
}
int pigcircle::getis()
{
    return is;
}
void pigcircle::sendis(int i)
{
    is=i;
}
void pigcircle::sendnumber(int i)
{
    number=i;
}
void pigcircle::sendifblack(int i)
{
    ifblack=i;
}
void pigcircle::sendsum(int i)
{
    sum=i;
}
int pigcircle::searchspiece(int i)
{
    if(i>sum) return -1;
    int j;
    pig *p=head;
    for(j=1;j<i;j++)
    p=p->next;
    return p->spiece;
}
double pigcircle::searchweight(int i)
{
    if(i>sum) return -1;
    int j;
    pig *p=head;
    for(j=1;j<i;j++)
    p=p->next;
    return p->weight;
}
int pigcircle::searchdays(int i)
{
    if(i>sum) return -1;
    int j;
    pig *p=head;
    for(j=1;j<i;j++)
    p=p->next;
    return p->days;
}
void initial(pigcircle pc[])
{
    srand(time(NULL));
    int i,j;
    pig *p,*q;
    for(i=1;i<=100;i++)
    {
        pc[i].head=NULL;
        pc[i].sendsum(5);
        pc[i].sendnumber(i);
        if(i<=30)
        {
            pc[i].sendifblack(1);
            for(j=1;j<=5;j++)
            {
            p=new pig;
            p->spiece=1;
            p->weight=(random(200,500))/10.0;
            p->days=0;
            p->ipig=0;
            p->next=NULL;
            if(pc[i].head==NULL)
            pc[i].head=p;
            else
            q->next=p;
            q=p;
        }
        }
        else
        {
            pc[i].sendifblack(0);
            for(j=1;j<=5;j++)
            {
            p=new pig;
            p->spiece=random(2,3);
            p->weight=(random(200,500))/10.0;
            p->days=0;
            p->next=NULL;
            if(pc[i].head==NULL)
            pc[i].head=p;
            else
            q->next=p;
            q=p;
        }
        }
    }
}
int amount(pigcircle pc[])
{
    int i,sum=0;
    for(i=1;i<=100;i++)
    {
        sum+=pc[i].getsum();
    }
    return sum;
}
int pigcirclestatistics(int t,pigcircle pc[])
{
    int j,t1=0,t2=0;
    pig *p=pc[t].head;
    int ifblack1=pc[t].getifblack();
    if(ifblack1==1)
    {
        cout<<"是黑猪圈"<<endl<<"黑猪数目为：  "<<pc[t].getsum()<<endl;
    }
    else
    {
        while(p!=NULL)
        {
            if(p->spiece==2)
            t1+=1;
            else
            t2+=1;
            p=p->next;
        }
        cout<<"是杂猪圈"<<endl<<"大花白猪数目为：  "<<t1<<endl;
        cout<< "小花白猪数目为：  "<<t2<<endl;
    }
}
void allmember(pigcircle pc[])
{
    memset(allspiece,0,sizeof(allspiece));
    memset(alldate,0,sizeof(alldate));
    memset(allweight,0,sizeof(allweight));
    int i,sum,j,t;
    for(i=1;i<=100;i++)
    {
        sum=pc[i].getsum();
        for(j=1;j<=sum;j++)
        {
            allspiece[pc[i].searchspiece(j)]++;
            alldate[pc[i].searchdays(j)/31]++;
            allweight[int(pc[i].searchweight(j)/10.0)]++;
        }
    }
}
void allupping(pigcircle pc[])
{
    int i;
    pig *p;
    for(i=1;i<=100;i++)
    {
    p=pc[i].head;
    while(p!=NULL)
    {
        p->days+=1;
        p->weight+=(random(0,12))/10.0;
        p=p->next;
    }
    }
}
void outFile(pigcircle pc[])
{
    ofstream destFile("pigsmessage.txt",ios::out);
    int i,j,sum;
    pig *p,*p1;
    for(i=1;i<=100;i++)
    {
        p=pc[i].head;
        sum=pc[i].getsum();
        destFile<<pc[i].getnumber()<<endl;
        for(j=1;j<=sum;j++)
        {
            destFile<<p->spiece<<' '<<p->weight<<' '<<p->days<<endl;
            p=p->next;
        }
    }
     destFile.close();
}
void inFile(pigcircle pc[])
{
    ifstream srcFile("pigsmessage.txt",ios::in);
    pig *p,*p1;
    int i,j,sum,t;
    for(i=1;i<=100;i++)
    {
        sum=pc[i].getsum();
        srcFile>>t;
        pc[i].sendnumber(t);
        for(j=1;j<=sum;j++)
        {
            p1=new pig;
            srcFile>>p1->spiece>>p1->weight>>p1->days;
            if(j==1) p=p1;
            else
            {
                p->next=p1;
                p=p1;
            }
        }
    }
    srcFile.close();
}
void pigcircle::sale()
{
    int i=1,t=0;
    pig *p=head,*p1,*p2;
    p1=head;
    for(;i<=sum;i++)
    {
        if(p->weight>75||p->days>360)
        {
          if(p->spiece==1)
            sumprice+=p->weight*15;
           else if(p->spiece==2)
           sumprice+=p->weight*7;
           else
           sumprice+=p->weight*6;
           saleamount++;
           if(p==head)
           {
            p=p->next;
            head=p1=p;
           }
           else
           {
            p2=p;
            p1->next=p->next;
            p=p->next;
             delete p2;
           }
            t++;
        }
        else
        {
         p1=p;
         p=p->next;
        }
    }
    sum-=t;
}
void saleall(pigcircle pc[])
{
    int i;
    saleamount=sumprice=0;
    for(i=1;i<=100;i++)
    pc[i].sale();
    ofstream destFile("buyandsale.txt",ios::app);
    destFile<<"sale"<<endl<<' '<<saleamount<<' '<<sumprice<<endl;
    destFile.close();
}
int buypigs(pigcircle pc[],int bp,int wp,int sp)
{
    ofstream destFile("buyandsale.txt",ios::app);
    destFile<<"buy"<<endl<<"black pig"<<' '<<bp<<endl<<"big white big"<<' '<<wp<<endl<<"samll white pig"<<' '<<sp<<endl;
    destFile.close();
    int i,sum=0,ave,gs,fg,j;
    pig *p,*np,*p1;
    for(i=1;i<31;i++)
    sum+=pc[i].getsum();
    sum+=bp;
    if(sum>300) return 0;
    ave=sum/30+1;
    for(i=1;i<31&&bp!=0;i++)
    {
        gs=pc[i].getsum();
        if(gs>=ave) continue;
        p=pc[i].head;
        for(j=1;j<gs&&bp!=0;j++)
        p=p->next;
         for(j=gs+1;j<=ave&&bp!=0;j++)
         {
            np=new pig;
            np->spiece=1;
            np->weight=(random(200,500))/10.0;
            np->days=0;
            np->next=NULL;
            p->next=np;
            bp--;
            gs++;
            p=np;
         }
         pc[i].sendsum(gs);
     }
    for(sum=0,i=30;i<=100;i++)
    sum+=pc[i].getsum();
    sum+=wp+sp;
    int ap=wp+sp;
    if(sum>700) return 0;
    ave=sum/70+1;
    for(i=31;i<=100&&ap!=0;i++)
    {
        gs=pc[i].getsum();
        if(gs>=ave) continue;
        p=pc[i].head;
        for(j=1;j<gs;j++)
        p=p->next;
         for(j=gs+1;j<=ave&&ap!=0;j++)
         {
            np=new pig;
            np->spiece=random(2,3);
            np->weight=(random(200,500))/10.0;
            np->days=0;
            np->next=NULL;
            p->next=np;
            ap--;
            gs++;
         }
         pc[i].sendsum(gs);
     }
     return 1;
}
int isf(int i,int p,pigcircle pc[])
{
    srand(time(NULL));
     int isamount=0,d=0;
    int j,sum,c,flag,is,is1,is2,t;
    pig *p1;
    p1=pc[i].head;
    sum=pc[i].getsum();
    pc[i].sendis(1);
    for(j=1;j<sum;j++)
    {
    p1=p1->next;
    }
    p1->ipig=1;
    while(isamount)
{
    for(t=i;t>=0;t--)
    {
        is=pc[t].getis();
        sum=pc[t].getsum();
        if(sum==0||sum==is)  continue;
        else if(is>0)
        {
          p1=pc[t].head;
          for(j=1;j<=sum;j++)
          {
            if(p1->ipig==0)
            {
                c=random(1,100);
                if(c<=50)
                {
                    p1->ipig=1;
                    is++;
                    isamount++;
                }
            }
            p1=p1->next;
          }
        }
        else if(is==0&&sum>0)
        {
            if(t-1>0) is1=pc[t-1].getis();
            else is1=0;
            is2=pc[t+1].getis();
            if(is2>0||is1>0)
            {
                p1=pc[t].head;
                for(j=1;j<=sum;j++)
                {
                    c=random(1,100);
                    if(c<=15)
                    {
                        is++;
                        isamount++;
                        p1->ipig=1;
                    }
                        p1=p1->next;
                }
            }
        }
        pc[t].sendis(is);
    }
    for(t=i+1;t<=100;t++)
    {
        is=pc[t].getis();
        sum=pc[t].getsum();
        if(sum==0||sum==is)  continue;
        else if(is>0)
        {
          p1=pc[t].head;
          for(j=1;j<=sum;j++)
          {
            if(p1->ipig==0)
            {
                c=random(1,100);
                if(c<=50)
                {
                    p1->ipig=1;
                    is++;
                    isamount++;
                }
            }
            p1=p1->next;
          }
        }
        else if(is==0&&sum>0)
        {
            if(t+1<=100) is2=pc[t+1].getis();
            else is2=0;
            is1=pc[t-1].getis();
            if(is1>0||is2>0)
            {
                p1=pc[t].head;
                for(j=1;j<=sum;j++)
                {
                    c=random(1,100);
                    if(c<=15)
                    {
                        is++;
                        p1->ipig=1;
                        isamount++;
                    }
                        p1=p1->next;
                }
            }
        }
        pc[t].sendis(is);
    }
    d++;
}
return d;
}
pigcircle pc[101];
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/ca31f6092070f6b9010f2a02de610597.jpg");
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    this->setPalette(palette);
    connect(ui->b1,&QPushButton::clicked,
            [=]()
    {
        initial(pc);
        ui->textBrowser->setText("初始化成功\n");
    }
            );
    connect(ui->pushButton,&QPushButton::clicked,
            [=]()
    {
        int t;
         ui->textBrowser->setText("感染成功\n完全感染所需要的天数为： ");
    }
           );
     connect(ui->pushButton_2,&QPushButton::clicked,
           [=]()
    {
      int a,b,flag=0;
      char t;
      QString str=ui->textBrowser->toPlainText();
      for(int i;i<str.length();i++)
      {
          if(str[i]==' ')
          {
              flag=1;
              continue;
          }
          else if(str[i]>='0'&&str[i]<='9'&&flag==0)
              {
              a=a*10+int(str[i]-'0');
              continue;
              }
          if(str[i]>='0'&&str[i]<='9'&&flag==1)
          {
              b=str[i]-'0';
          }
      }

    }
            );
}

Widget::~Widget()
{
    delete ui;
}
