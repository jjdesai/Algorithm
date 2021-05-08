
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "./../common_include.h"

int * InputFromTerminal(unsigned int * array_size_ptr)
{
    int * array_ptr = NULL;

    printf("\n");
    printf(" Enter the size of the array : ");
    USER_INPUT(" %u", array_size_ptr);

    if(YES == IsArraySizeValid(*array_size_ptr))
    {
        array_ptr = (int *) calloc((*array_size_ptr), sizeof(int)); 
        if(array_ptr)
        {
            for(int i=0; i<(*array_size_ptr); i++)
            {
                YELLOW_COLOR;
                printf("\tEnter array element %u : ", i+1);
                USER_INPUT(" %d", &array_ptr[i]);
                RESET_COLOR;
            }
        }
        else
        {
            ERROR("Memory allocation failed");
        }
    }
    else
    {
        ERROR("Invalid size of the array entered by User");
    }

    return array_ptr;
}
