#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Stooge Sort
    Worst Complexity    : n^(log3/log1.5)
    Average Complexity  : n^(log3/log1.5)
    Best Complexity     : n^(log3/log1.5)
    Space Complexity    : n
    Stable              : No
    Class               : Comparison Sort
*/

void stoogeSort(int * array_ptr, unsigned int start, unsigned int end)
{
    int temp;

    if(end-start+1>2)
    {
        temp = (end-start+1)/3;
        stoogeSort(array_ptr, start, end-temp);
        stoogeSort(array_ptr, start+temp, end);
        stoogeSort(array_ptr, start, end-temp);
    }

    if(array_ptr[end] < array_ptr[start])
        Swap(&array_ptr[end], &array_ptr[start]);
}

void Stooge_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        stoogeSort(array_ptr, 0, array_size-1);
    }
    else
    {
        ERROR("Null pointer found");
    }
}