#include "user_mon.h"
#include "ui_user_mon.h"

user_rec::user_rec(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_rec)
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

user_rec::~user_rec()
{
     delete m_tcp;
    delete ui;
}

void user_rec::on_pushButton_clicked()const
{

    QString sendMsg = "clear";
    sendimm(sendMsg);
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="4";//操作
    sendimm(sendMsg);
    sendMsg="end";
    sendimm(sendMsg);
}
void user_rec::sendimm(QString sendMsg)const{

    m_tcp->write(sendMsg.toUtf8());
    m_tcp->flush();
    m_tcp->waitForReadyRead(100);

}

void user_rec::on_pushButton_2_clicked()const
{
    QString sendMsg = "clear";
    sendimm(sendMsg);
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="5";//操作
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

