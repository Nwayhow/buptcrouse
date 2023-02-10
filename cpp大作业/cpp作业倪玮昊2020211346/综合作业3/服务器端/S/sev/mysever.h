#ifndef MYSEVER_H
#define MYSEVER_H
#include <QTcpServer>
using namespace std;
class myserver :public QTcpServer{
    Q_OBJECT
protected://将socketDescriptor传入新创建的线程对象,来实现多个客户端同时对用户端进行操作
    virtual void incomingConnection(qintptr socketDescriptor);

signals://信号槽函数发送信号
    void look(string) const;
    void look1(string) const;
    void look2(string) const;
private slots://信号槽函数接收信号
    void watch(string word) const{
        emit look(word);
    };
    void watch1(string word) const{
        emit look1(word);
    };
    void watch2(string word) const{
        emit look2(word);
    };
};
#endif // MYSEVER_H
