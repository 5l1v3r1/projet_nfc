#include "tagdatamainwindow.h"
#include "ui_tagdatamainwindow.h"

TagDataMainWindow::TagDataMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TagDataMainWindow)
{
    ui->setupUi(this);
}

TagDataMainWindow::~TagDataMainWindow()
{
    delete ui;
}
