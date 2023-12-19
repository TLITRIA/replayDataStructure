#include <string.h>
#include <stdio.h>
#include "myDynamicArray.h"


#define BUFFER_SIZE 20
#define DEFAULT_NUM 3


#define PRINT(a)\
printf("%-5s : %d\n", #a, a);\

#define JUDGE_IFDESTROY(array)\
if (NULL == array.data)\
        printf("动态数组已销毁\n");\
    else\
        printf("动态数组未销毁\n");\

int main()
{
    int sign = 0;
    dynamicArray array;

    sign = dynamicInit(&array, BUFFER_SIZE);
    // PRINT(sign);

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
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



    printf("===========\n");
    dynamicGetLength(&array, &len);
    for (int idx = 0; idx < len; idx++)
    {
        dynamicGetPosVal(&array, idx, &tmpNum);
        printf("array[%d]:%d\n", idx, tmpNum);
    }
    printf("===========\n");



#if 0
    pos = 6;
    tmpNum = 10;
    dynamicModifyPosData(&array, pos, tmpNum);
#elif 0
    dynamicDelLastData(&array);
#elif 0
    pos = 6;
    dynamicDelPosData(&array, pos);
#elif 0
    pos = 6;
    dynamicDelPosData(&array, pos);
    tmpNum = 7;
    dynamicDelData(&array, tmpNum);
#endif

    dynamicGetLength(&array, &len);
    for (int idx = 0; idx < len; idx++)
    {
        dynamicGetPosVal(&array, idx, &tmpNum);
        printf("array[%d]:%d\n", idx, tmpNum);
    }
    printf("===========\n");

    JUDGE_IFDESTROY(array);
    dynamicDestroy(&array);
    JUDGE_IFDESTROY(array);

    return 0;
}









/*    END    */

