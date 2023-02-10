#ifndef USER_MON_H
#define USER_MON_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class user_rec;
}

class user_rec : public QWidget
{
    Q_OBJECT

public:

    QString name;//用户名
    QString password;//密码
      QTcpSocket* m_tcp;//客户端
        void sendimm(QString)const;//立即发送
    explicit user_rec(QWidget *parent = nullptr);
    ~user_rec();

private slots:
        void on_pushButton_clicked()const;//查询余额

        void on_pushButton_2_clicked()const;//充值

private:
    Ui::user_rec *ui;
};

#endif // USER_MON_H
