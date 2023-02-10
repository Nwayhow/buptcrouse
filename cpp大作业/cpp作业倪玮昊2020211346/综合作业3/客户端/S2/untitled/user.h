#ifndef USER_H
#define USER_H
#include <QWidget>
#include <QObject>
#include"user_sen.h"
#include"user_mon.h"
#include"change.h"
using namespace std;
namespace Ui {
class user;
}

class user : public QWidget
{
    Q_OBJECT

public:
    QTcpSocket* m_tcp;//客户端
    user_sen sen_s;//处理快递界面
    user_rec mon_s;//余额界面
    change change_s;//修改用户信息界面
    QString name;//用户名
    QString password;//密码
    explicit user(QWidget *parent = nullptr);
    ~user();
    void connect(short port,QString ip);//连接端口和ip
    void user_(QString path);
signals:
    void look()const;//信号槽,回到登录界面
private slots:





    void on_pushButton_2_clicked();//修改信息界面打开

    void on_pushButton_6_clicked();//退回登录界面

    void on_pushButton_clicked();//查询快递界面打开

    void on_pushButton_5_clicked();//查找余额

private:
     Ui::user *ui;

};

#endif // USER_H
