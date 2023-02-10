#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include<iostream>
#include"mysever.h"
#include"sock.h"
using namespace std;


void myserver::incomingConnection(qintptr socketDescriptor)
{//当mysever收到监听信号时,再new一个子线程对象socketThread,再调用start进入重新写过的run函数

    qDebug()<<"New Connect is connect"<<socketDescriptor;
        socketThread * thread=new socketThread();
        connect(thread,SIGNAL(look(string)),this,SLOT(watch(string)));//登录时进行操作
        connect(this,SIGNAL(look1(string)),thread,SLOT(watch1(string)));//返回确认可以登录
          connect(thread,SIGNAL(look2(string)),this,SLOT(watch2(string)));//下线
        thread->write_ptr(socketDescriptor);
    thread->start();
}
void socketThread::watch1(string) const{


}
void socketThread::run(){
//run函数中new一个QTcpSocket,完成客户端初始化,带到连接成功以后对客户端的数据进行读取,待收到end时将储存在数组中全部数据发给ays()函数进行分析,再将数组清空,等待下一次接收消息.
    socket=new QTcpSocket();
    socket->setSocketDescriptor(ptr);//客户端的初始化
    if(socket->waitForConnected(10000)){
        qDebug()<<"Connect Success";
    }
    else{
        qDebug()<<"Connect Fail";
    }
   // while(true ){//完成需要的功能
        // 接收数据
        cout<<"1"<<endl;
        connect(socket, &QTcpSocket::readyRead, this, [=]()
               {

                   // 接收数据
            QByteArray recvMsg = socket->readAll();
            string str=recvMsg.toStdString();
            mes[cons]=str;
            cons++;
            if(str=="end"){

                ays(cons,mes);
                cons=0;
            }
            if(str=="clear"){
                cons=0;
                socket->waitForBytesWritten(3000);
            }

               });
        connect(socket, &QTcpSocket::disconnected, this, [=]()
        {
            if(kind==1){
                emit look2(name);
            }

        });
         this->exec();
/**

**/
   //  }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("TCP - 服务器");
    // 创建 QTcpServer 对象
     server=new myserver();
    connect(server,SIGNAL(look(string)),this,SLOT(watch(string)));//登录时操作
    connect(this,SIGNAL(look1(string)),server,SLOT(watch1(string)));
connect(server,SIGNAL(look2(string)),this,SLOT(watch2(string)));
}
void MainWindow::watch(string word) {
    for(int con=0;con<cons;con++){
        if(ac[con]==word){
             return;
        }
    }
    ac[cons]=word;
    cons++;
    ui->record->append("账号"+QString::fromStdString(word)+"成功登录");
}
void MainWindow::watch2(string word){
    for(int con=0;con<cons;con++){
        if(ac[con]==word){
            ac[con]="0";
            ui->record->append("账号"+QString::fromStdString(word)+"下线");

        }
    }
   ;
}
MainWindow::~MainWindow()
{

    delete ui;
}

// 启动服务器端的服务按钮
void MainWindow::on_startServer_clicked()
{
    unsigned short port = ui->port->text().toInt();
    // 设置服务器监听
   server->listen(QHostAddress::Any, port);
    ui->startServer->setEnabled(false);
    ui->record->append("已打开 ");
}









