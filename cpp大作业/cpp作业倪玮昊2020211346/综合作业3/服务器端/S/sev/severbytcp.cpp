using namespace std;
#include"iostream"
#include "severbytcp.h"
SeverByTcp::SeverByTcp(QObject *parent) : QTcpServer(parent)
{
}

bool SeverByTcp::startSeverListen(const QString sHostPort)
{
    //监听端口
    if(listen(QHostAddress::Any, sHostPort.toInt()))
    {
        return true;
    }
    return false;
}

void SeverByTcp::incomingConnection(int socketDescriptor)
{
    //只要有新的连接就生成一个新的通信套接字
    TcpClientSocket *tcpClientSocket = new TcpClientSocket(this);

    //将新创建的通信套接字描述符指定为参数socketdescriptor
    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    //将这个套接字加入客户端套接字列表中
    m_tcpClientSocketList.append(tcpClientSocket);

    //接收到tcpclientsocket发送过来信息
    connect(tcpClientSocket,SIGNAL(sigUpdateSever(QString,int)),this,SLOT(slotUpdateServer(QString, int)));
    //处理客户端掉线
    connect(tcpClientSocket,SIGNAL(sigClientDisconnect(int)),this,SLOT(slotClientDisconnected(int)));

}

void SeverByTcp::slotUpdateServer(QString sMsg, int iLength)
{
cout<<"1"<<endl;
   std:: string str=sMsg.toStdString();

}

void SeverByTcp::slotClientDisconnected(int iSocketDescriptor)
{
    cout<<"2"<<endl;
    //如果有客户端断开连接， 就将列表中的套接字删除
    for(int i = 0; i < m_tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = m_tcpClientSocketList.value(i);
        if(item->socketDescriptor() == iSocketDescriptor)
        {
            m_tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return;
}
