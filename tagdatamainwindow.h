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

private:
    Ui::TagDataMainWindow *ui;
};

#endif // TAGDATAMAINWINDOW_H
