#include "change.h"
#include "ui_change.h"

change::change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
    m_tcp= new QTcpSocket(this);

    // 检测服务器是否回复了数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
    {
        // 接收服务器发送的数据
        QString recvMsg = m_tcp->readAll();
        if(recvMsg!="登录成功") ui->textBrowser->append(recvMsg);
        if(recvMsg=="密码修改完成") password=ui->lineEdit->text();
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
void change::sendimm(QString sendMsg) const{

    if(sendMsg.isEmpty()){
         m_tcp->write(sendMsg.toUtf8());
    }
    m_tcp->write(sendMsg.toUtf8());
    m_tcp->flush();//顺利发送
    m_tcp->waitForReadyRead(100);

}

change::~change()
{
    delete m_tcp;
    delete ui;
}

void change::on_pushButton_2_clicked ()const
{
    QString sendMsg ;
    sendMsg="1";
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


void change::on_comboBox_activated(int index)
{
    if(index==0) kind="1";
    else if(index==1) kind="3";
    else if(index==2) kind="4";
}


void change::on_pushButton_clicked()const
{
    QString sendMsg ;
    sendMsg="1";
    sendimm(sendMsg);
    sendMsg=name;
    sendimm(sendMsg);
    sendMsg=password;
    sendimm(sendMsg);
    sendMsg="7";
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

