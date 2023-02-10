#ifndef CHANGE_H
#define CHANGE_H


#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class change;
}

class change : public QWidget
{
    Q_OBJECT

public:
    QString kind="1";//判断查找类型
    QString name;//用户名
    QString password;//用户密码
      QTcpSocket* m_tcp;//通信口
        void sendimm(QString)const;//立即发出,防止几行指令凑成一行
    explicit change(QWidget *parent = nullptr);
    ~change();

private slots:
        void on_pushButton_2_clicked() const;//充值

        void on_comboBox_activated(int index) ;//选择修改内容

        void on_pushButton_clicked() const;//查询余额

private:
    Ui::change *ui;
};

#endif // CHANGE_H
