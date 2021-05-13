#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Shell Sort
    Worst Complexity    : Depend on gap sequence
    Average Complexity  : n*log(n)^2
    Best Complexity     : n
    Space Complexity    : 1
    Method              : Exchanging
    Stable              : Yes
*/

void Shell_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        int i, j, temp, gap;
        for(gap=array_size/2; gap>0; gap/=2)
        {
            for(i=gap; i<array_size; i++)
            {
                temp = array_ptr[i];
                for(j=i; j>=gap && temp<array_ptr[j-gap]; j-=gap)
                {
                    array_ptr[j] = array_ptr[j-gap];
                }
                array_ptr[j] = temp;
            }
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}