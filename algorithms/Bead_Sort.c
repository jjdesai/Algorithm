#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Bead Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n
    Space Complexity    : 1
    Method              : Exchanging
    Stable              : Yes
*/

void Bead_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        int i, j;
        int * temp_array_ptr = calloc(array_size, sizeof(int));
        if(temp_array_ptr)
        {
            do
            {
                for (i=j=0; i<array_size; i++)
                {
                    if (array_ptr[i])
                    {
                        temp_array_ptr[j++]++;
                        array_ptr[i]--;
                    }
                }
            }
            while (j);

            for (j = array_size, i = 0; i < array_size; i++)
                array_ptr[i] = temp_array_ptr[--j]; // A is now sorted ascending.

            FREE(temp_array_ptr);
        }
        else
        {
            ERROR("Memory allocation failed");
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}