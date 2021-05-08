#include <stdio.h>

#include "./../common_include.h"

void Bubble_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        for(int i=0; i<array_size; i++)
            for(int j=0; j<array_size-i-1; j++)
                if(array_ptr[j] > array_ptr[j+1])
                    Swap(array_ptr, j, j+1);
    }
    else
    {
        ERROR("Null pointer found");
    }
}