
#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Selection Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n^2
    Space Complexity    : 1
    Method              : Selection
    Stable              : No
    Class               : Comparison Sort
*/

void Selection_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        for(int i=0; i<array_size-1; i++)
            for(int j=i+1; j<array_size; j++)
                if(array_ptr[j] < array_ptr[i])
                    Swap(&array_ptr[i], &array_ptr[j]);
    }
    else
    {
        ERROR("Null pointer found");
    }
}