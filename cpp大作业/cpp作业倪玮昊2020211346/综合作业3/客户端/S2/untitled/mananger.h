#ifndef MANANGER_H
#define MANANGER_H
#include <QTcpSocket>
#include <QWidget>

#include "changedev.h"
namespace Ui {
class mananger;
}

class mananger : public QWidget
{
    Q_OBJECT

public:
    changedev c;//增删快递员
        QString kind="1";//查找类型
          QTcpSocket* m_tcp;//客户端
        QString name;//用户名
        QString password;//密码
        void sendimm(QString)const;//立即发送
        explicit mananger(QWidget *parent = nullptr);
        ~mananger();
        void mananger_(QString path);
           void connect(short port,QString ip);//将changdev的客户端进行连接
signals:
    void look();//信号,用于返回
private slots:
    void on_comboBox_activated(int index);//选择类型

    void on_pushButton_clicked()const;//查询快递

    void on_pushButton_2_clicked()const;//查询快递员

    void on_pushButton_3_clicked()const;//分配快递

    void on_pushButton_4_clicked()const;//一键查询所有快递员和快递

    void on_pushButton_5_clicked();//修改快递员

    void on_pushButton_6_clicked();//退回登录界面

    void on_pushButton_7_clicked();//查询用户

private:
    Ui::mananger *ui;
};

#endif // MANANGER_H
