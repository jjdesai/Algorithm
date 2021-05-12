
#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Gnome Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n
    Space Complexity    : 1
    Stable              : Yes
    Method              : Exchanging
*/
 
void Gnome_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        int i=0;

        while(i<array_size)
        {
            if(i==0)    i++;
            
            if(array_ptr[i] < array_ptr[i-1])
            {
                Swap(array_ptr, i, i-1);
                i--;
            }
            else if(array_ptr[i] >= array_ptr[i-1])
            {
                i++;
            }
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}