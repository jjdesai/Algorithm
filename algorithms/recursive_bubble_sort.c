#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Recursive Bubble Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n 
    Space Complexity    : 1
    Method              : Exchanging
    Stable              : Yes
    Class               : Comparison Sort
*/

void Recursive_Bubble_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        if(array_size == 1)
            return;

        for(int i=0; i<array_size-1; i++)
            if(array_ptr[i] > array_ptr[i+1])
                Swap(&array_ptr[i], &array_ptr[i+1]);
        
        Recursive_Bubble_Sort(array_ptr, array_size-1);
    }
    else
    {
        ERROR("Null pointer found");
    }
}
