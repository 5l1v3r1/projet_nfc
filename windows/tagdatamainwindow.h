#ifndef TAGDATAMAINWINDOW_H
#define TAGDATAMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TagDataMainWindow;
}

class TagDataMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TagDataMainWindow(QWidget *parent = 0);
    ~TagDataMainWindow();
    void addWidgetDataLayout(QWidget *toAdd);
    void setTitleId(QString id);
    void setData(QString* data);
    QString* getData();
    void setTextData(QString* data);
    QString* getTextData();
    void conversionTextDataToText();
    void conversionDataToTextData();

private:
    Ui::TagDataMainWindow *ui;
};

#endif // TAGDATAMAINWINDOW_H
