#include "datamifware1kwidget.h"
#include "ui_datamifware1kwidget.h"

DataMifware1kWidget::DataMifware1kWidget(QWidget *parent, int numberSector) :
    QWidget(parent),
    ui(new Ui::DataMifware1kWidget)
{
    ui->setupUi(this);
    QString a="Sector : ";
    a+=QString::number(numberSector);
    ui->sectorTitleLabel->setText(a);
}

DataMifware1kWidget::~DataMifware1kWidget()
{
    delete ui;
}

void DataMifware1kWidget::setData(QString data){
    ui->dataTextEdit->setText(data);
}

QString* DataMifware1kWidget::getData(){
    QString * a;
    *a= ui->dataTextEdit->toPlainText();
    return a;
}

void DataMifware1kWidget::setTextData(QString data){
    ui->textDataTextEdit->setText(data);
}

QString* DataMifware1kWidget::getTextData(){
    QString * a;
    *a= ui->textDataTextEdit->toPlainText();
    return a;
}

void DataMifware1kWidget::conversionTextDataToText(){

}

void DataMifware1kWidget::conversionDataToTextData(){

}
