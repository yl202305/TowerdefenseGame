//#include "mainwindow.h"
#include "startform.h"      //��ʼ����
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartForm w;
    w.show();
    return a.exec();
}
