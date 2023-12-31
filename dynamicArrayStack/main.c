#include <stdio.h>
#include "dynamicArrayStack.h"

#define DEFAULT_SIZE 10
#define BUFFER_SIZE 5





int main()
{
    dynamicArrayStack stack;
    dynamicArrayStackInit(&stack);

    int buffer[BUFFER_SIZE] = {5, 32, 7, 77, 23};
    for (int idx = 1; idx <= BUFFER_SIZE; idx++)
    {
        dynamicArrayStackPush(&stack, buffer[idx-1]);
    }

    int size = 0;
    dynamicArrayStackGetSize(&stack, &size);

    printf("size:%d\n", size);

    int val = 0;
    while (!dynamicArrayStackIsEmpty(&stack))
    {
        /* todo considering */
        printf("2");
        dynamicArrayStackTop(&stack, &val);
        printf("val:%d\n", val);
        dynamicArrayStackPop(&stack);
    }

    /* 栈的销毁 */
    dynamicArrayStackDestroy(&stack);

    return 0;
}