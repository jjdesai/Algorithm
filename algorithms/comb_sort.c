
#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Comb Sort
    Worst Complexity    : n^2
    Average Complexity  : n log(n)
    Best Complexity     : n
    Space Complexity    : 1
    Method              : Exchanging
    Stable              : No
*/

unsigned int GenerateNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;

    if(gap < 1)     return 1;
    else            return gap;
}
 
void Comb_Sort(int array_ptr[], unsigned int array_size)
{
    if(array_ptr)
    {
        int gap;
        int is_swapped = TRUE;
        
        for(gap=GenerateNextGap(array_size); (gap != 1 || is_swapped == TRUE); gap=GenerateNextGap(gap))
        {
            is_swapped = FALSE;
            for (int i=0; i<array_size-gap; i++)
            {
                if (array_ptr[i] > array_ptr[i+gap])
                {
                    Swap(&array_ptr[i], &array_ptr[i+gap]);
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