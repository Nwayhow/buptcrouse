#ifndef USER_SEN_H
#define USER_SEN_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class user_sen;
}

class user_sen : public QWidget
{
    Q_OBJECT

public:

    QString name;//用户名
    QString password;//密码
      void sendimm(QString)const;//立即发送
    QString kind="1";//发送类型
    QString kind2="1";//查找类型
      QTcpSocket* m_tcp;
    explicit user_sen(QWidget *parent = nullptr);
    ~user_sen();

private slots:
      void on_comboBox_activated(int index);//选择发送类型

      void on_pushButton_clicked()const;//发送

      void on_pushButton_2_clicked()const;//签收

      void on_pushButton_3_clicked()const;//查找

      void on_comboBox_2_activated(int index);//选择查找类型

private:
    Ui::user_sen *ui;
};

#endif // USER_SEN_H
