#ifndef DATAARRAY_H
#define DATAARRAY_H

#include <QVector>

template<typename T> class KeysArray;

typedef unsigned char uint8_t;
typedef unsigned char byte_t;



//  SECTOR 0 => BLOCK 0 (8 T)                                   lenghOfBlocks[0][0]=8
//           => BLOCK 1 (16 T)        numberBlocks[0]=2         lenghOfBlocks[0][1]=16
//  SECTOR 1 => BLOCK 0 (40 T)                                  lenghOfBlocks[1][0]=40
//           => BLOCK 1
//           => BLOCK 2
//           => BLOCK 3              numberBlocks[4]=4
//  SECTOR 2 => BLOCK 0
//           => BLOCK 1

template <typename T>
class DataArray
{
public:
    DataArray();


    DataArray(int numberOfSectors, int *numberOfBlocks, int **lengthOfBlocks){
        data = new QVector < QVector <T*>*>;
        dataDetermined = new QVector < QVector <bool>*>;
        numberSectors= numberOfSectors;
        numberBlocks = new int[numberOfSectors];
        blocksLength = new int*[numberOfSectors];
        int i;
        int j;
        for(i=0;i<numberOfSectors;i++){
            numberBlocks[i] = numberOfBlocks[i];
            blocksLength[i] = new int[numberOfBlocks[i]];
            (*data).push_back(new QVector <T*>);
            (*dataDetermined).push_back(new QVector <bool>);
            for(j=0; j<numberOfBlocks[i];j++){
                (*(*data)[i]).push_back(new T[lengthOfBlocks[i][j]]);
                (*(*dataDetermined)[i]).push_back(false);
                blocksLength[i][j]=lengthOfBlocks[i][j];
            }
        }
    }

    ~DataArray(){
        int i;
        for(i=0 ; i<numberSectors; i++){
            delete (*dataDetermined)[i];
            delete (*data)[i];
        }
        delete data;
        delete dataDetermined;
        delete numberBlocks;
        delete blocksLength;
    }


    bool setData(int sector, int block, int length, T* dataToWrite){
        int i;
        bool res = false;
        if (sector<=numberSectors){
            if(block <= numberBlocks[sector]){
                if(length<= blocksLength[sector][block]){
                    res = true;
                    for(i=0 ; i<length; i++){
                        (*(*data)[sector])[block][i]=dataToWrite[i];
                    }
                }
            }
        }
        return res;
    }

    bool setDataDetermined(int sector, int block){
        bool res = false;
        if (sector<=numberSectors){
            if(block <= numberBlocks[sector]){
                res = true;
                (*(*dataDetermined)[sector])[block]=true;
            }
        }
        return res;
    }

    bool isDataDetermined(int sector, int block){
        bool res = false;
        if (sector<=numberSectors){
            if(block <= numberBlocks[sector]){
                if((*(*dataDetermined)[sector])[block]){
                    res = true;
                }
            }
        }
        return res;
    }

    T* getData(int sector, int block)
    {
       return (*(*data)[sector])[block];
    }

    /*

    T* operator[](int i)
    {
       return (*data)[i];
    }

    bool
*/


private :

    QVector < QVector <T*>* > *data;
    QVector < QVector <bool>* > *dataDetermined;
    int numberSectors;
    int *numberBlocks;
    int **blocksLength;

};

#endif // DATAARRAY_H
