#ifndef LOGIN_H
#define LOGIN_H
#include "user.h"
#include"dev.h"
#include <QWidget>
#include"mananger.h"
#include"sign.h"
#include <QTcpSocket>


namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:

    sign sign_s;//注册类,用于打开注册界面
    void sendimm(QString)const;//立即发送
     user user_s;//用户类,用于打开用户界面
    mananger mananger_s;//管理员类,打开管理员界面
    dev dev_s;//快递员类,打开快递员界面
    int id=0;//省份
        QTcpSocket* m_tcp;//客户端
        explicit login(QWidget *parent = nullptr);
        ~login();


private slots:
     void open_s();//在连接断开时打开登录界面
    void on_pushButton_clicked();//登录

    void on_pushButton_2_clicked();//注册

    void on_pushButton_3_clicked()const;//连接





    void on_comboBox_activated(int index);//选择身份


private:
    Ui::login *ui;
};

#endif // LOGIN_H
