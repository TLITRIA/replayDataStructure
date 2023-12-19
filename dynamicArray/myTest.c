#include <string.h>
#include <stdio.h>
#include "myDynamicArray.h"


#define BUFFER_SIZE 20
#define DEFAULT_NUM 3


#define PRINT(a)\
printf("%-5s : %d\n", #a, a);\



int main()
{
    int sign = 0;
    dynamicArray array;

    sign = dynamicInit(&array, BUFFER_SIZE);
    // PRINT(sign);

    for (int idx = 0; idx < BUFFER_SIZE * 2; idx++)
    {
        dynamicInsertAppointData(&array, idx);
    }

    int len = 0;
    dynamicGetLength(&array, &len);
    PRINT(len);

    int cap = 0;
    dynamicGetCapacity(&array, &cap);
    PRINT(cap);

    int pos = 6;
    ELEMENTTYPE tmpNum = 0;
    dynamicGetPosVal(&array, pos, &tmpNum);
    PRINT(tmpNum);


    return 0;
}









/*    END    */

