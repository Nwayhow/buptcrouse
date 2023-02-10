#include "user.h"
#include "ui_user.h"
#include"QNetworkProxy"
user::user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}




void user::on_pushButton_2_clicked()
{
    change_s.name=name;
    change_s.password=password;
     change_s.m_tcp->setProxy(QNetworkProxy::NoProxy);
     // 连接服务器
     change_s.m_tcp->connectToHost(QHostAddress("127.0.0.1"), 8899);
    bool k= change_s.m_tcp->waitForConnected(3000);
    if(k==false){
         ui->label->setText("连接失败,请重复点击或者向开发者报告错误");return;
    }
     change_s.show();
}


void user::on_pushButton_6_clicked()
{
    this->close();
    emit look();

}


void user::on_pushButton_clicked()
{

    sen_s.name=name;
     sen_s.password=password;
     sen_s.m_tcp->setProxy(QNetworkProxy::NoProxy);
     // 连接服务器
     sen_s.m_tcp->connectToHost(QHostAddress("127.0.0.1"), 8899);

    bool k= sen_s.m_tcp->waitForConnected(3000);
    if(k==false){
         ui->label->setText("连接失败,请重复点击或者向开发者报告错误");return;
    }
    sen_s.show();
}


void user::on_pushButton_5_clicked()
{
   mon_s.name=name;
    mon_s.password=password;
    mon_s.m_tcp->setProxy(QNetworkProxy::NoProxy);
    // 连接服务器

    mon_s.m_tcp->connectToHost(QHostAddress("127.0.0.1"), 8899);
     QString sendMsg = "clear";
   bool k= mon_s.m_tcp->waitForConnected(3000);
   if(k==false){
        ui->label->setText("连接失败,请重复点击或者向开发者报告错误");return;
   }
    mon_s.show();
}

