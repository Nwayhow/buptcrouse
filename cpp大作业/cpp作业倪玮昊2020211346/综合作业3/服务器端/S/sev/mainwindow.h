#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"mysever.h"
#include<QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMainWindow>
#include <QTcpServer>
#include "ui_mainwindow.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     myserver * server;//服务器
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int cons=0;//计算目前登录账号总数
    std::string ac[100];//储存所有目前登录的账号
signals:
    void look1(string) const;//发送信号
private slots:
    void on_startServer_clicked();//ui按钮
private:
    Ui::MainWindow *ui;

private slots:
     void watch(string);//接收信号
     void watch2(string);//接收信号
};



#endif // MAINWINDOW_H
