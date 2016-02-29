#ifndef DATAARRAYMIFARE1K_H
#define DATAARRAYMIFARE1K_H

#include "data/dataarray.h"

class DataArrayMifare1K : public DataArray<unsigned char>
{
public:
    DataArrayMifare1K(){
        int i;
        int j;

        int numberOfSectors =16;
        int *numberOfBlocks = new int[numberOfSectors];
        int **lengthOfBlocks = new int*[numberOfSectors];
        for(i=0;i<numberOfSectors;i++){
            numberOfBlocks[i]=4;
            lengthOfBlocks[i]=new int[numberOfBlocks[i]];
            for(j=0;j<numberOfBlocks[i];j++){
                lengthOfBlocks[i][j]=16;
            }
        }
        initData(numberOfSectors, numberOfBlocks, lengthOfBlocks);
    }
};

#endif // DATAARRAYMIFARE1K_H
