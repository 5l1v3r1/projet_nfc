#include "mainwindow.h"
#include <QApplication>

#include "test.cpp"


int main(int argc, char *argv[])
{
    //test();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    test();

    return a.exec();
}
