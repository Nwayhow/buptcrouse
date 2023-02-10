#include "changedev.h"
#include "ui_changedev.h"

changedev::changedev(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changedev)
{
    ui->setupUi(this);
    m_tcp= new QTcpSocket(this);

    // 检测服务器是否回复了数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
    {
        // 接收服务器发送的数据
        QString recvMsg = m_tcp->readAll();
       if(recvMsg!="登录成功") ui->label_7->setText(recvMsg);
    });

    // 检测是否和服务器是否连接成功了
    connect(m_tcp, &QTcpSocket::connected, this, [=]()
    {

    });

    // 检测服务器是否和客户端断开了连接
    connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
    {

        this->close();
    });
}

changedev::~changedev()
{
     delete m_tcp;
    delete ui;
}
void changedev::sendimm(QString sendMsg)const{

    m_tcp->write(sendMsg.toUtf8());
    m_tcp->flush();
    m_tcp->waitForReadyRead(100);

}
void changedev::on_pushButton_clicked()const
{
    QString sendMsg="2";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="4";
    sendimm(sendMsg);
    sendMsg="2";
    sendimm(sendMsg);
    sendMsg=ui->lineEdit_2->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->label_7->setText("用户名不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg="end";
    sendimm(sendMsg);
}


void changedev::on_pushButton_2_clicked()const
{
    QString sendMsg="2";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="4";
    sendimm(sendMsg);
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=ui->lineEdit_2->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->label_7->setText("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg=ui->lineEdit_3->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->label_7->setText("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg=ui->lineEdit_4->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->label_7->setText("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg=ui->lineEdit_5->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->label_7->setText("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg=ui->lineEdit_6->text();
    if(sendMsg.isEmpty()){
         sendMsg="clear";
         ui->label_7->setText("行列中不能有空");
         m_tcp->write(sendMsg.toUtf8());
         return;
    }
    sendimm(sendMsg);
    sendMsg="end";
    sendimm(sendMsg);
}

