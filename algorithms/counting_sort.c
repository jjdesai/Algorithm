
#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Counting Sort
    Worst Complexity    : n+r
    Average Complexity  : n+r
    Best Complexity     : n+r
    Space Complexity    : n+r
    Stable              : Yes
    Class               : Non Comparing Sort
*/

int FindMaxValue(int * array_ptr, unsigned int array_size)
{
    int max=array_ptr[0];
    for(int i=1; i<array_size; i++)
        if(array_ptr[i] > max)
            max = array_ptr[i];
    return max;
}
 
void Counting_Sort(int array_ptr[], unsigned int array_size)
{
    if(array_ptr)
    {
        int max_value = FindMaxValue(array_ptr, array_size);
        int * count_array_ptr = calloc(max_value+1, sizeof(int));
        if(count_array_ptr)
        {
            for(int i=0; i<array_size; i++)
                ++count_array_ptr[array_ptr[i]];

            for(int i=0, j=0; i<(max_value+1); i++)
            {
                while(count_array_ptr[i])
                {
                    array_ptr[j++] = i;
                    --count_array_ptr[i];
                }
            }
        }
        else
        {
            ERROR("Memory allocation failed");
        }
        FREE(count_array_ptr);
    }
    else
    {
        ERROR("Null pointer found");
    }
}