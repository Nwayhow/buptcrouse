#include "dev.h"
#include "ui_dev.h"

dev::dev(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dev)
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

    });

    // 检测服务器是否和客户端断开了连接
    QAbstractScrollArea::connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
    {

        this->close();
    });
}

dev::~dev()
{
     delete m_tcp;
    delete ui;
}

void dev::on_comboBox_activated(int index)
{
    if(index==0) kind="1";
    else if(index==1) kind="2";
    else if(index==2) kind="3";
    else if(index==3) kind="4";
    else if(index==4) kind="5";
    else if(index==5) kind="6";
    else if(index==6) kind="7";

}
void dev::sendimm(QString sendMsg)const{

    m_tcp->write(sendMsg.toUtf8());
    m_tcp->flush();
    m_tcp->waitForReadyRead(100);

}


void dev::on_pushButton_2_clicked()const
{
      ui->textBrowser->clear();
    QString sendMsg ;
    sendMsg="clear";
    sendimm(sendMsg);
    sendMsg="3";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=kind;
    sendimm(sendMsg);
     if(kind=="1" || kind=="2" ||kind=="3" || kind=="4"){
         sendMsg=ui->lineEdit->text();
             if(sendMsg.isEmpty()){
                  sendMsg="clear";
                  ui->textBrowser->append("行列中不能有空");
                  m_tcp->write(sendMsg.toUtf8());
                  return;
             }
     }
    sendimm(sendMsg);
    sendMsg="end";
    sendimm(sendMsg);
}


void dev::on_pushButton_clicked()const
{
    QString sendMsg ;
    sendMsg="clear";
    sendMsg="3";
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


void dev::on_pushButton_3_clicked()
{
    this->close();
    emit look();
}

