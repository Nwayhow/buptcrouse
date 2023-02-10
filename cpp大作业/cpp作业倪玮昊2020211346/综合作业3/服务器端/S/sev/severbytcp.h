#ifndef SEVERBYTCP_H
#define SEVERBYTCP_H

#include <QObject>
#include <QTcpServer>
#include <QList>
#include "tcpclientsocket.h"//这个类是自己继承QTcpSocket的，下个示例就会补充

class SeverByTcp : public QTcpServer
{
    Q_OBJECT
public:
    explicit SeverByTcp(QObject *parent = 0);

    //开启监听
    bool startSeverListen(const QString sHostPort);

    // 当有新连接可用时，QTcpServer将调用此虚拟函数
    void incomingConnection(int socketDescriptor);

signals:

public slots:
    //处理服务器收到tcpsocket发过来的信息
    void slotUpdateServer(QString, int);

    //告诉服务器有客户端断开连接
    void slotClientDisconnected(int);

private:
    // 连接到服务器的客户端链表
    QList<TcpClientSocket*> m_tcpClientSocketList;

};

#endif // SEVERBYTCP_H
