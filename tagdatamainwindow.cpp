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

void TagDataMainWindow::addWidgetDataLayout(QWidget *toAdd){
    ui->dataLayout->addWidget(toAdd);
}

void TagDataMainWindow::setTitleId(QString id){
    ui->idLabel->setText(id);
}

QString* TagDataMainWindow::getData(){
}

void TagDataMainWindow::setTextData(QString* data){

}

QString* TagDataMainWindow::getTextData(){

}

void TagDataMainWindow::conversionTextDataToText(){

}

void TagDataMainWindow::conversionDataToTextData(){

}
