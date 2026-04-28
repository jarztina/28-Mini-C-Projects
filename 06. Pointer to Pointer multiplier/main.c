#include <stdio.h>
#include <stdlib.h>

void multiplyRelocate(int **pp1)
{
    int newValue = (**pp1) * 10;
    free(*pp1);

    int *temp = malloc(sizeof(int)); //temporary placeholder that blocks the old address from being used again by valuebefore
                                     //It never actually stores anything useful, its only purpose is to sit in the old address long enough for valueBefore to get a new one.
    *pp1 = malloc(sizeof(int)); // gets new address
    **pp1 = newValue;
    free(temp);
}

int main()
{
    int *valueBefore = malloc(sizeof(int));
    if (valueBefore == NULL)
    {
        printf("Memory Allocation Error!");
    }

    *valueBefore = 5;

    printf("Address = %p, Value = %d\n", valueBefore, *valueBefore);

    multiplyRelocate(&valueBefore);

    printf("Relocating...\n");

    printf("Address = %p, Value = %d\n", valueBefore, *valueBefore);

    free(valueBefore);
    valueBefore = NULL;

    return 0;
}