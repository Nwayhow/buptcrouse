#ifndef CHANGEDEV_H
#define CHANGEDEV_H
#include <QTcpSocket>
#include <QWidget>


namespace Ui {
class changedev;
}

class changedev : public QWidget
{
    Q_OBJECT

public:
    QString name;//用户名
    QString password;//密码

      QTcpSocket* m_tcp;//通信端
      void sendimm(QString)const;//立即发出,防止几行指令凑成一行
    explicit changedev(QWidget *parent = nullptr);
    ~changedev();

private slots:
        void on_pushButton_clicked()const;//删除快递员

        void on_pushButton_2_clicked()const;//添加快递员

private:
    Ui::changedev *ui;
};

#endif // CHANGEDEV_H
