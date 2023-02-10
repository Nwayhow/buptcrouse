
#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = 0);

signals:
    // 通知服务器 客户端收到了消息
    void sigUpdateSever(QString,int);
    // 通知服务器 客户端掉线
    void sigClientDisconnect(int);

public slots:
    // 处理readyRead信号读取数据
    void slotReceiveData();
    // 用来处理客户端断开连接触发disconnected信号
    void slotClientDisconnected();
private:

};

#endif // TCPCLIENTSOCKET_H
