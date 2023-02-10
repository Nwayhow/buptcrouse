#include "user_sen.h"
#include "ui_user_sen.h"
#include"QNetworkProxy"
#include<iostream>
using namespace std;
user_sen::user_sen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_sen)
{
    ui->setupUi(this);
    m_tcp= new QTcpSocket(this);

    // 检测服务器是否回复了数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
    {
        // 接收服务器发送的数据
        QString recvMsg = m_tcp->readAll();
        if(recvMsg!="登录成功") ui->textBrowser->append(recvMsg);
    });

    // 检测是否和服务器是否连接成功了
    connect(m_tcp, &QTcpSocket::connected, this, [=]()
    {
        QString sendMsg = "clear";
        m_tcp->write(sendMsg.toUtf8());
    });

    // 检测服务器是否和客户端断开了连接
    connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
    {

        this->close();
    });
}

user_sen::~user_sen()
{
    delete m_tcp;
    delete ui;
}

void user_sen::on_comboBox_activated(int index)
{
    if(index==0) kind="1";
    else if(index==1) kind="2";
    else if(index==2) kind="3";
}


void user_sen::on_pushButton_clicked()const
{
    QString sendMsg = "clear";
    sendimm(sendMsg);
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=kind;
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->textBrowser->append("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg=ui->l1->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->textBrowser->append("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg=ui->l2->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->textBrowser->append("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg=ui->l3->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->textBrowser->append("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg=ui->lineEdit->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->textBrowser->append("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg="end";
    sendimm(sendMsg);


}
void user_sen::sendimm(QString sendMsg)const{

    if(sendMsg.isEmpty()){
         m_tcp->write(sendMsg.toUtf8());
    }
    m_tcp->write(sendMsg.toUtf8());
    m_tcp->flush();
    m_tcp->waitForReadyRead(100);

}


void user_sen::on_pushButton_2_clicked()const
{//收快递

    QString sendMsg = "clear";
    sendimm(sendMsg);
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="2";
    sendimm(sendMsg);
    sendMsg=ui->l4->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->textBrowser->append("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg="end";
    sendimm(sendMsg);

}


void user_sen::on_pushButton_3_clicked()const
{
//查快递
    ui->textBrowser->clear();
    QString sendMsg = "clear";
    sendimm(sendMsg);
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="3";
    sendimm(sendMsg);
    sendMsg=kind2;
    sendimm(sendMsg);
    sendMsg=ui->l5->text();
    if(sendMsg.isEmpty() && kind2!="5" &&  kind2!="7" &&  kind2!="6" && kind2!="8"){
         sendMsg="clear";
         ui->textBrowser->append("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg="end";
    sendimm(sendMsg);

}


void user_sen::on_comboBox_2_activated(int index)
{
    if(index==0) kind2="1";
    else if(index==1) kind2="2";
    else if(index==2) kind2="3";
    else if(index==3) kind2="4";
    else if(index==4) kind2="5";
    else if(index==5) kind2="6";
    else if(index==6) kind2="7";
     else if(index==7) kind2="8";
}

