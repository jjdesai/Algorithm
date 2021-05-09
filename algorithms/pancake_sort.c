#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Pancake Sort
    Worst Complexity    : n
    Average Complexity  : n
    Best Complexity     : 1
    Space Complexity    : log(n)
    Method              : Exchange
    Stable              : NO
    Class               : Comparison Sort
*/

void Flip(int * array_ptr, unsigned int array_size)
{
    int start = 0;
    while(start < array_size)
    {
        Swap(array_ptr, start, array_size);
        array_size--;
        start++;
    }
}

unsigned int FindMaxValueIndex(int * array_ptr, unsigned int array_size)
{
    int max = 0;
    for(int i=1; i<array_size; i++)
        if(array_ptr[i] > array_ptr[max])
            max = i;
    return max;
}

// void Pancake_Sort(int * array_ptr, unsigned int array_size)
// {
//     for(int curr_size = array_size; curr_size > 1; --curr_size)
//     {
//         int mi = FindMaxValueIndex(array_ptr, curr_size);
//         if (mi != curr_size - 1)
//         {
//             Flip(array_ptr, mi);
//             Flip(array_ptr, curr_size - 1);
//         }
//     }
// }

void Pancake_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        for(int i=array_size; i>1; --i)
        {
            unsigned int max = FindMaxValueIndex(array_ptr, i);
            if(max != array_size-1)
            {
                Flip(array_ptr, max);
                Flip(array_ptr, i-1);
            }
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}