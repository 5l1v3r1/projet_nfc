#ifndef KEYSARRAYMIFARE1K_H
#define KEYSARRAYMIFARE1K_H

#include "data/keysarray.h"

class KeysArrayMifare1K  : public KeysArray<unsigned char>
{
public:
    KeysArrayMifare1K():KeysArray(6){
    }

};

#endif // KEYSARRAYMIFARE1K_H
