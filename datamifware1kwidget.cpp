#include "datamifware1kwidget.h"
#include "ui_datamifware1kwidget.h"

DataMifware1kWidget::DataMifware1kWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMifware1kWidget)
{
    ui->setupUi(this);
}

DataMifware1kWidget::~DataMifware1kWidget()
{
    delete ui;
}
