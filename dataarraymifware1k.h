#ifndef DATAARRAYMIFWARE1K_H
#define DATAARRAYMIFWARE1K_H

#include <dataarray.h>

class DataArrayMifware1K : public DataArray <unsigned char>
{
public:
    DataArrayMifware1K() : DataArray(){

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
        DataArray(numberOfSectors, numberOfBlocks, lengthOfBlocks);
    }
};

#endif // DATAARRAYMIFWARE1K_H
