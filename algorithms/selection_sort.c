
#include <stdio.h>

#include "./../common_include.h"

void Selection_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        for(int i=0; i<array_size-1; i++)
            for(int j=i+1; j<array_size; j++)
                if(array_ptr[j] < array_ptr[i])
                    Swap(array_ptr, i, j);
    }
    else
    {
        ERROR("Null pointer found");
    }
}