#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Spaghetti Sort
    Worst Complexity    : n
    Average Complexity  : n
    Best Complexity     : n
    Space Complexity    : n*2
    Method              : Replacement/Copy
    Stable              : Yes
    Class               : Polling
*/

int FindIndexAtMaxValue(int * array_ptr, unsigned int array_size)
{
    int max=array_ptr[0];
    int array_index = 0;
    for(int i=0; i<array_size; i++)
    {
        if(array_ptr[i] > max)
        {
            max = array_ptr[i];
            array_index = i;
        }
    }
    return array_index;
}

void Spaghetti_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        int * spaghetti_array_ptr = NULL;
        spaghetti_array_ptr = (int *) calloc(array_size, sizeof(int));
        if(spaghetti_array_ptr)
        {
            int i, index;
            int size = array_size-1;

            for(i=0; i<array_size; i++, size--)
            {
                index = FindIndexAtMaxValue(array_ptr, array_size);
                spaghetti_array_ptr[size] = array_ptr[index];
                array_ptr[index] = 0;
            }

            for(i=0; i<array_size; i++)
                array_ptr[i] = spaghetti_array_ptr[i];
        }
        else
        {
            ERROR("Memory Allocation failed");
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}