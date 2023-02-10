#include "mainwindow.h"

#include <QApplication>
#include <QTcpServer>
#include <QTcpSocket>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
