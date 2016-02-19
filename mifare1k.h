#ifndef MIFARE1K_H
#define MIFARE1K_H

#include "keysarraymifare1k.h"
#include "dataarraymifare1k.h"
#include "tagdatamainwindow.h"
#include "datamifware1kwidget.h"
#include <QString>

class Mifare1K
{
public:
    Mifare1K(QString id);

private :
    KeysArrayMifare1K *keys_A;
    KeysArrayMifare1K *keys_B;
    DataArrayMifare1K *data;
    TagDataMainWindow *window;
    DataMifware1kWidget **dataWidgets;

};

#endif // MIFARE1K_H
