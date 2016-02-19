#ifndef DATAMIFWARE1KWIDGET_H
#define DATAMIFWARE1KWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class DataMifware1kWidget;
}

class DataMifware1kWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataMifware1kWidget(QWidget *parent = 0, int numberSector =42);
    ~DataMifware1kWidget();

    void setData(QString data);
    QString* getData();
    void setTextData(QString data);
    QString* getTextData();
    void conversionTextDataToText();
    void conversionDataToTextData();

private:
    Ui::DataMifware1kWidget *ui;
};

#endif // DATAMIFWARE1KWIDGET_H
