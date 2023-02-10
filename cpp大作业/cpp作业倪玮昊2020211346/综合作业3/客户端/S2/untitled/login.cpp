#include "login.h"
#include "ui_login.h"
#include "login.h"
#include "sign.h"
#include"ui_sign.h"
#include"dev.h"
#include"ui_mananger.h"
#include"mananger.h"
#include "login.h"
#include<iostream>
#include<QString>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<fstream>
#include <iomanip>
#include"user.h"
#include"QThread"
#include"QNetworkProxy"
using namespace std;
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
     connect(&user_s,SIGNAL(look()),this,SLOT(open_s()));
      connect(&mananger_s,SIGNAL(look()),this,SLOT(open_s()));
       connect(&dev_s,SIGNAL(look()),this,SLOT(open_s()));
    // 创建通信的套接字对象
    m_tcp = new QTcpSocket(this);

    // 检测服务器是否回复了数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
    {
        // 接收服务器发送的数据
        QString recvMsg = m_tcp->readAll();
        ui->label->setText(recvMsg);
        if(recvMsg=="登录成功") {
             sign_s.close();
            if(id==0){ user_s.show();this->close();  }
            if(id==2){
               dev_s.m_tcp->setProxy(QNetworkProxy::NoProxy);
                // 连接服务器
                dev_s.m_tcp->connectToHost(QHostAddress("127.0.0.1"), 8899);
               bool k= dev_s.m_tcp->waitForConnected(3000);
               if(k!=false){
                   dev_s.show();this->close();
               }

            }
             if(id==1){

                 mananger_s.m_tcp->setProxy(QNetworkProxy::NoProxy);
                 // 连接服务器
                 mananger_s.m_tcp->connectToHost(QHostAddress("127.0.0.1"), 8899);
                bool k= mananger_s.m_tcp->waitForConnected(3000);
                if(k!=false){
                    mananger_s.show();this->close();
                }

             }
        }
        else if(recvMsg=="重复登录"){
             mananger_s.close();
             dev_s.close();
             user_s.close();
             this->show();
             this->m_tcp->close();
        }
    });

    // 检测是否和服务器是否连接成功了
    connect(m_tcp, &QTcpSocket::connected, this, [=]()
    {
        ui->label_2->setText("恭喜, 连接服务器成功!!!");


    });

    // 检测服务器是否和客户端断开了连接
    connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
    {
         ui->label_2->setText("服务器已经断开了连接, ...");
         user_s.close();

         this->show();

    });
}
void login::open_s(){
    m_tcp->close();
    this->show();
}

login::~login()
{
 delete m_tcp;
    delete ui;
}

void login::on_pushButton_clicked()
{
    sendimm("clear");
    QString sendMsg ;
    if(id==0) {
        sendMsg="1";
        user_s.name=ui->lineEdit->text();
        user_s.password=ui->lineEdit_2->text();
    }
    else if(id==1)   {
        sendMsg="2";
        mananger_s.name=ui->lineEdit->text();
        mananger_s.password=ui->lineEdit_2->text();
    }
    else if(id==2)   {
        sendMsg="3";

        dev_s.name=ui->lineEdit->text();
        dev_s.password=ui->lineEdit_2->text();
    }
    sendimm(sendMsg);
    sendMsg=ui->lineEdit->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->label->setText("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
     sendimm(sendMsg);
    sendMsg=ui->lineEdit_2->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->label->setText("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg="end";
    sendimm(sendMsg);


}


void login::on_pushButton_2_clicked()
{    sign_s.m_tcp->setProxy(QNetworkProxy::NoProxy);
     // 连接服务器
     sign_s.m_tcp->connectToHost(QHostAddress("127.0.0.1"), 8899);
    bool k= m_tcp->waitForConnected(3000);
    if(k==false){
         ui->label->setText("连接失败");return;
    }
    sign_s.show();

}
void login::sendimm(QString sendMsg)const{
    m_tcp->write(sendMsg.toUtf8());
    m_tcp->flush();
     m_tcp->waitForReadyRead(100);
}

void login::on_pushButton_3_clicked()const
{

    m_tcp->setProxy(QNetworkProxy::NoProxy);
    // 连接服务器
    m_tcp->localAddress();
    m_tcp->connectToHost(QHostAddress("127.0.0.1"), 8899);
     QString sendMsg = "请登陆";
     m_tcp->write(sendMsg.toUtf8());
   bool k= m_tcp->waitForConnected(3000);
   if(k==false){
        ui->label_2->setText("连接失败");
   }
}








void login::on_comboBox_activated(int index)
{
    id=index;
}




