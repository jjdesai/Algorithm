#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Bogo Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n
    Space Complexity    : 1
    Method              : Insertion
    Stable              : Yes
    Class               : Comparison Sort
*/

int IsSorted(int * array_ptr, unsigned int array_size)
{
    for(int i=0; i<array_size-1; i++)
        if(array_ptr[i] > array_ptr[i+1])
            return FALSE;
    return TRUE;
}

void Shuffle(int * array_ptr, unsigned int array_size)
{
    for(int i=0; i<array_size; i++)
    {
        unsigned int randnumber = rand()%array_size;
        Swap(&array_ptr[i], &array_ptr[randnumber]);
    }
}

void Bogo_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        while(!IsSorted(array_ptr, array_size))
            Shuffle(array_ptr, array_size);
    }
    else
    {
        ERROR("Null pointer found");
    }
}