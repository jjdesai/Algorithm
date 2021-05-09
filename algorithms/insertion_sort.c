#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Insertion Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n
    Space Complexity    : 1
    Method              : Insertion
    Stable              : Yes
    Class               : Comparison Sort
*/

void Insertion_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        int i,j;

        for(i=1; i<array_size; i++)
        {
            int key = array_ptr[i];
            for(j=i-1; (key < array_ptr[j] && j>=0); j--)
                array_ptr[j+1] = array_ptr[j]; 
            array_ptr[j+1] = key;
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}