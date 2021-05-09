#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Recursive Insertion Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n
    Space Complexity    : n
    Method              : Insertion
    Stable              : Yes
    Class               : Comparison Sort
*/

void Recursive_Insertion_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        if(array_size <= 1)
            return;

        Recursive_Insertion_Sort(array_ptr, array_size-1);

        int key = array_ptr[array_size-1];
        
        int i=0;
        for(i = array_size-2; (i>=0 && array_ptr[i] > key); i--)
            array_ptr[i+1] = array_ptr[i];

        array_ptr[i+1] = key;
    }
    else
    {
        ERROR("Null pointer found");
    }
}