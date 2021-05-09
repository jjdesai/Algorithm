#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Bubble Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n
    Space Complexity    : 1
    Method              : Exchanging
    Stable              : Yes
    Class               : Comparison Sort
*/

void Bubble_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        for(int i=0; i<array_size; i++)
            for(int j=0; j<array_size-i-1; j++)
                if(array_ptr[j] > array_ptr[j+1])
                    Swap(array_ptr, j, j+1);
    }
    else
    {
        ERROR("Null pointer found");
    }
}