#include "mifare1k.h"


Mifare1K::Mifare1K(QString id)
{
    keys_A = new KeysArrayMifare1K();
    keys_B = new KeysArrayMifare1K();
    data = new DataArrayMifare1K();
    window = new TagDataMainWindow();
    window->setWindowTitle("Mifare 1K");
    window->setTitleId(id);
    dataWidgets = new DataMifware1kWidget*[16];
    int i;
    for(i=0; i<16; i++){
        dataWidgets[i] = new DataMifware1kWidget(0,i);
        window->addWidgetDataLayout(dataWidgets[i]);
        dataWidgets[i]->setData("zafefefeef");
    }


    window->show();

}

