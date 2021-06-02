#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Cycle Sort
    Worst Complexity    : n^2
    Average Complexity  : n^2
    Best Complexity     : n^2
    Space Complexity    : 1
    Stable              : No
    Sort                : Comparison Sort
*/

void Cycle_Sort(int * array_ptr, unsigned int array_size)
{    
    if(array_ptr)
    {
        int writes = 0;

        for(int cycle_start = 0; cycle_start <= array_size - 2; cycle_start++)
        {
            int item = array_ptr[cycle_start];
    
            int pos = cycle_start;
            for(int i = cycle_start + 1; i < array_size; i++)
                if(array_ptr[i] < item)
                    pos++;
    
            if(pos == cycle_start)
                continue;
    
            while(item == array_ptr[pos])
                pos += 1;
    
            if(pos != cycle_start)
            {
                Swap(&item, &array_ptr[pos]);
                writes++;
            }
    
            while(pos != cycle_start)
            {
                pos = cycle_start;
                
                for (int i = cycle_start + 1; i < array_size; i++)
                    if (array_ptr[i] < item)
                        pos += 1;
                        
                while (item == array_ptr[pos])
                    pos += 1;
    
                if(item != array_ptr[pos])
                {
                    Swap(&item, &array_ptr[pos]);
                    writes++;
                }
            }
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}