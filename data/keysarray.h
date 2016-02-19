#ifndef KEYSARRAY_H
#define KEYSARRAY_H

#include <QVector>

template<typename T> class KeysArray;

typedef unsigned char uint8_t;
typedef unsigned char byte_t;


template <typename T>
class KeysArray
{
public:

    KeysArray(const int numberOfElementsPerKeys =6){
        keys = new QVector < T* >;
        numberOfKeys=0;
        sizeOfKeys=numberOfElementsPerKeys;
    }

    ~KeysArray(){
        int i;
        for(i=0 ; i<numberOfKeys; i++){
            delete (*keys)[i];
        }
        delete keys;
    }


    void addKey(T* data){
        numberOfKeys++;
        T* tab = new T[sizeOfKeys];
        int i;
        for(i=0 ; i<sizeOfKeys; i++){
            tab[i]=data[i];
        }
        keys->push_back(tab);
    }

    T* operator[](int i)
    {
       return (*keys)[i];
    }


private :

    QVector <T*> *keys;
    int numberOfKeys;
    int sizeOfKeys;

};



#endif // KEYSARRAY_H
