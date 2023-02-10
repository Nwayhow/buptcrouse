#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "login.h"
#include "user.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    changedev c;//增删快递员
        QString kind="1";//查找类型
          QTcpSocket* m_tcp;//客户端
        QString name;//用户名
        QString password;//密码
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    login m_dlglogin;

};
#endif // MAINWINDOW_H
