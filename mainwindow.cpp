#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLoad_clicked()
{

}

void MainWindow::on_ReadpushButton_clicked()
{

}

void MainWindow::on_ShowSavedCheckBox_stateChanged(int checked)
{
    if(checked){
        ui->testLabel->setText("checked");
    }
    else {
        ui->testLabel->setText("unchecked");
    }

}
