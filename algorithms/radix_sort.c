
#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Radix Sort
    Worst Complexity    : n*k/d
    Average Complexity  : n*k/d
    Best Complexity     : n*k/d
    Space Complexity    : n*k/d
    Stable              : Yes
    Class               : Non-comparison sort
*/

void CountSort(int * array_ptr, unsigned int array_size, unsigned int position)
{
    int count_array[10] = {0,0,0,0,0,0,0,0,0,0};
    int i;

    int * dummy_array_ptr = calloc(array_size, sizeof(int));
    if(!dummy_array_ptr)
    {
        ERROR("Memory allocation failed");
        return;
    }

    for(i=0; i<array_size; i++)
    {
        unsigned int main_digita = (array_ptr[i]/position) % 10;
        ++count_array[main_digita];
    }

    for(i=1; i<=9; i++)
        count_array[i] = count_array[i] + count_array[i-1];

    for(i=array_size-1; i>=0; i--)
    {
        int temp = (array_ptr[i]/position)%10;
        --count_array[temp];
        dummy_array_ptr[count_array[temp]] = array_ptr[i];
    }

    for(i=0; i<array_size; i++)
        array_ptr[i] = dummy_array_ptr[i];
}

void Radix_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        int max;

        max = FindMaxValue(array_ptr, array_size);
        for(unsigned int position=1; max/position>0; position*=10)
        {
            CountSort(array_ptr, array_size, position);
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}