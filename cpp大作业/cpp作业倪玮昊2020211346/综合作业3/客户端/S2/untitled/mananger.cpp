#include "mananger.h"
#include "ui_mananger.h"
#include"QNetworkProxy"
mananger::mananger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mananger)
{
    ui->setupUi(this);
    m_tcp= new QTcpSocket(this);


    // 检测服务器是否回复了数据
    QAbstractScrollArea::connect(m_tcp, &QTcpSocket::readyRead, [=]()
    {
        // 接收服务器发送的数据
        QString recvMsg = m_tcp->readAll();
       if(recvMsg!="登录成功") ui->textBrowser->append(recvMsg);
    });

    // 检测是否和服务器是否连接成功了
    QAbstractScrollArea::connect(m_tcp, &QTcpSocket::connected, this, [=]()
    {
        QString sendMsg = "clear";
        m_tcp->write(sendMsg.toUtf8());
    });

    // 检测服务器是否和客户端断开了连接
    QAbstractScrollArea::connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
    {
       this->close();
        c.close();
    });
}

mananger::~mananger()
{
     delete m_tcp;
    delete ui;
}

void mananger::on_comboBox_activated(int index)
{
    if(index==0) kind="1";
    else if(index==1) kind="2";
    else if(index==2) kind="3";
    else if(index==3) kind="4";
}
void mananger::sendimm(QString sendMsg)const{

    m_tcp->write(sendMsg.toUtf8());
    m_tcp->flush();
    m_tcp->waitForReadyRead(100);

}

void mananger::on_pushButton_clicked()const
{
   ui->textBrowser->clear();
   QString sendMsg = "clear";
   sendimm(sendMsg);
  sendMsg="2";
  sendimm(sendMsg);

   sendMsg=name;
   sendimm(sendMsg);
   sendMsg=password;
   sendimm(sendMsg);
   sendMsg="1";
   sendimm(sendMsg);
   sendMsg=kind;
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


void mananger::on_pushButton_2_clicked()const
{
     ui->textBrowser->clear();
     QString sendMsg = "clear";
     sendimm(sendMsg);

   sendMsg="2";
   sendimm(sendMsg);
   sendMsg=name;
   sendimm(sendMsg);
   sendMsg=password;
   sendimm(sendMsg);
   sendMsg="2";
   sendimm(sendMsg);
   sendMsg=ui->lineEdit_2->text();
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


void mananger::on_pushButton_3_clicked()const
{
    ui->textBrowser->clear();
    QString sendMsg = "clear";
    sendimm(sendMsg);
   sendMsg="2";
   sendimm(sendMsg);
   sendMsg=name;
   sendimm(sendMsg);
   sendMsg=password;
   sendimm(sendMsg);
   sendMsg="3";
   sendimm(sendMsg);
   sendMsg=ui->lineEdit_3->text();
   if(sendMsg.isEmpty()){
        sendMsg="clear";
        ui->textBrowser->append("行列中不能有空");
        m_tcp->write(sendMsg.toUtf8());
        return;
   }
   sendimm(sendMsg);
   sendMsg=ui->lineEdit_4->text();
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


void mananger::on_pushButton_4_clicked()const
{
    ui->textBrowser->clear();
    QString sendMsg = "clear";
    sendimm(sendMsg);
   sendMsg="2";
   sendimm(sendMsg);
   sendMsg=name;
   sendimm(sendMsg);
   sendMsg=password;
   sendimm(sendMsg);
   sendMsg="5";
   sendimm(sendMsg);
   sendMsg="end";
   sendimm(sendMsg);
}


void mananger::on_pushButton_5_clicked()
{
    c.name=name;
     c.password=password;
     c.m_tcp->setProxy(QNetworkProxy::NoProxy);
     // 连接服务器
     c.m_tcp->connectToHost(QHostAddress("127.0.0.1"), 8899);
    bool k= c.m_tcp->waitForConnected(3000);
    if(k==false){
         return;
    }
     c.show();

}


void mananger::on_pushButton_6_clicked()
{
    this->close();
emit look();
}


void mananger::on_pushButton_7_clicked()
{
    ui->textBrowser->clear();
     QString sendMsg = "clear";
     sendimm(sendMsg);
   sendMsg="2";
   sendimm(sendMsg);
   sendMsg=name;
   sendimm(sendMsg);
   sendMsg=password;
   sendimm(sendMsg);
   sendMsg="6";
   sendimm(sendMsg);
   sendMsg="end";
   sendimm(sendMsg);
}

