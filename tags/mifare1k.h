#ifndef MIFARE1K_H
#define MIFARE1K_H

#include "data/mifare1k/keysarraymifare1k.h"
#include "data/mifare1k/dataarraymifare1k.h"
#include "windows/tagdatamainwindow.h"
#include "windows/mifare1k/datamifware1kwidget.h"
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
