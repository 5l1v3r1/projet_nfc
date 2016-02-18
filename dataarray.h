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
    DataArray(){
    }


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

    void initData(int numberOfSectors, int *numberOfBlocks, int **lengthOfBlocks){
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
        int j;
        for(i=0 ; i<numberSectors; i++){
            for(j=0; j<numberBlocks[i];j++){
                delete (*(*data)[i])[j];
            }
            delete (*dataDetermined)[i];
            delete (*data)[i];
            delete blocksLength[i];
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

    void addSector(int numberOfBlocksInSectorToAdd, int *lengthOfBlocksInSectorToAdd){
        int *numberBlocksTemp = new int[numberSectors+1];
        int **blocksLengthTemp = new int*[numberSectors+1];
        int i;
        int j;
        for(i=0;i<numberSectors;i++){
            numberBlocksTemp[i] = numberBlocks[i];
            blocksLengthTemp[i] = new int[numberBlocks[i]];
            for(j=0; j<numberBlocks[i];j++){
                blocksLengthTemp[i][j]=blocksLength[i][j];
            }
            delete blocksLength[i];
        }
        numberSectors++;
        numberBlocksTemp[numberSectors]=numberOfBlocksInSectorToAdd;
        (*data).push_back(new QVector <T*>);
        (*dataDetermined).push_back(new QVector <bool>);
        for(j=0; j<numberOfBlocksInSectorToAdd;j++){
            blocksLengthTemp[numberSectors][j]=lengthOfBlocksInSectorToAdd[j];
            (*(*data)[numberSectors]).push_back(new T[lengthOfBlocksInSectorToAdd[j]]);
            (*(*dataDetermined)[numberSectors]).push_back(false);
        }
        delete blocksLength;
        delete numberBlocks;

        numberBlocks = numberBlocksTemp;
        blocksLength = blocksLengthTemp;


    }

private :

    QVector < QVector <T*>* > *data;
    QVector < QVector <bool>* > *dataDetermined;
    int numberSectors;
    int *numberBlocks;
    int **blocksLength;

};

#endif // DATAARRAY_H
