#include "mainwindow.h"
#include <QApplication>


#include "keysarraymifare1k.h"

#include <iostream>

int main(int argc, char *argv[])
{
    unsigned char c;
    KeysArray <unsigned char> *b=new KeysArray<unsigned char>();

    unsigned char *t = new unsigned char[6];
    t[0]=63;
    t[1]=64;
    t[2]=65;
    t[3]=4;
    t[4]=5;
    t[5]=6;



    b->addKey(t);

    std::cout << (int) (b[0])[1];

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
