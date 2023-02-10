#ifndef SIGN_H
#define SIGN_H
#include <QTcpSocket>
#include <QWidget>

namespace Ui {
class sign;
}

class sign : public QWidget
{
    Q_OBJECT

public:

    QString name;//用户名
    QString password;//密码
      QTcpSocket* m_tcp;//客户端
        void sendimm(QString)const;//直接发送
    explicit sign(QWidget *parent = nullptr);
    ~sign();

private slots:
        void on_pushButton_clicked()const;//注册


private:
    Ui::sign *ui;
};

#endif // SIGN_H
