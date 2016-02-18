#ifndef DATAMIFWARE1KWIDGET_H
#define DATAMIFWARE1KWIDGET_H

#include <QWidget>

namespace Ui {
class DataMifware1kWidget;
}

class DataMifware1kWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataMifware1kWidget(QWidget *parent = 0);
    ~DataMifware1kWidget();

private:
    Ui::DataMifware1kWidget *ui;
};

#endif // DATAMIFWARE1KWIDGET_H
