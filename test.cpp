#include "keysarraymifare1k.h"
#include "dataarray.h"
#include <iostream>

using namespace std;

void test(){

    int i;
    int j;

    cout << "Test of KeysArray" << endl;

    KeysArray<unsigned char> *a=new KeysArray<unsigned char>();

    unsigned char *t = new unsigned char[6];
    t[0]=63;
    t[1]=64;
    t[2]=65;
    t[3]=4;
    t[4]=5;
    t[5]=6;

    a->addKey(t);
    cout << (int) t[0] << " = " <<(int) (*a)[0][0] << endl;

    cout << "Test of KeysArrayMifare1K" << endl;

    KeysArrayMifare1K *b=new KeysArrayMifare1K();
    b->addKey(t);

    cout << (int) t[1] << " = " <<(int) (*b)[0][1] << endl;




    cout << "Test of DataArray" << endl;


    int numberOfSectors =3;
    int *numberOfBlocks = new int[numberOfSectors];
    int **lengthOfBlocks = new int*[numberOfSectors];
    for(i=0;i<numberOfSectors;i++){
        numberOfBlocks[i]=5;
        lengthOfBlocks[i]=new int[numberOfBlocks[i]];
        for(j=0;j<numberOfBlocks[i];j++){
            lengthOfBlocks[i][j]=6;
        }
    }
    DataArray <unsigned char> *c = new DataArray<unsigned char>(numberOfSectors,numberOfBlocks,lengthOfBlocks);

    c->setData(0,0,6,t);
    c->setDataDetermined(0,0);

    cout << c->isDataDetermined(0,0) << " = " <<"true" << endl;

    unsigned char *r = c->getData(0,0);

    for (i=0 ; i<5 ; i++){
       cout << t[i] << " = " << r[i] << endl;
    }

}
