#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Cocktail Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n
    Space Complexity    : 1
    Method              : Exchanging
    Stable              : Yes
    Class               : Comparison Sort
*/

void Cocktail_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {  
        int is_swapped = TRUE;
        int i;
        int begin, end;

        for(begin=0, end = array_size - 1; is_swapped; begin++)
        {
            // In forward direction ---->
            is_swapped = FALSE;
            for(i=begin; i<end; i++)
            {
                if(array_ptr[i] > array_ptr[i+1])
                {
                    Swap(array_ptr, i, i+1);
                    is_swapped = TRUE;
                }
            }

            if(!is_swapped) break;

            // In array forward direction <----
            is_swapped = FALSE;
            for(i=end-1; i>begin; i--)
            {
                if(array_ptr[i-1] > array_ptr[i])
                {
                    Swap(array_ptr, i, i-1);
                    is_swapped = TRUE;
                }
            }
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}