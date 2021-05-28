#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Odd Even Sort / Brick Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n
    Space Complexity    : 1
    Method              : Exchanging
    Stable              : Yes
*/

void Odd_Even_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        int isSorted = FALSE;
        int i;

        while(!isSorted)
        {
            isSorted = TRUE;
            // Sorting on ODD index element
            for(i=1; i<=array_size-2; i+=2)
            {
                if (array_ptr[i] > array_ptr[i+1])
                {
                    Swap(&array_ptr[i], &array_ptr[i+1]);
                    isSorted = FALSE;
                }
            }

            // Sorting on EVEN index element
            for (i=0; i<=array_size-2; i+=2)
            {
                if (array_ptr[i] > array_ptr[i+1])
                {
                    Swap(&array_ptr[i], &array_ptr[i+1]);
                    isSorted = FALSE;
                }
            }
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}