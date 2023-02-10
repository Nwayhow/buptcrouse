#ifndef DEV_H
#define DEV_H
#include <QWidget>
#include <QObject>
#include <QTcpSocket>
#include "qtmetamacros.h"

namespace Ui {
class dev;
}

class dev : public QWidget
{
    Q_OBJECT

public:

   QString kind="1";//查找类型
      void sendimm(QString)const;//立即发送
      QTcpSocket* m_tcp;//端口
    QString name;//用户名
    QString password;//密码
    explicit dev(QWidget *parent = nullptr);
    ~dev();
    void connect(short port,QString ip)const;
    void dev_(QString path);
signals:
    void look()const;
private slots:



    void on_comboBox_activated(int index);//选择类型

    void on_pushButton_2_clicked()const;//搜索

    void on_pushButton_clicked()const;//确认揽收

    void on_pushButton_3_clicked();//退回登录界面

private:
     Ui::dev *ui;

};

#endif // USER_H
