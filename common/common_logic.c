
#include <stdio.h>
#include "./../common_include.h"

char algorithm_str[MAX_SORTING+1][100] = { ALGORITHM(GENERATE_STRING) };

void (*algorithm_function_ptr[MAX_SORTING+1])(int *, unsigned int) = 
{
    ALGORITHM(GENERATE_FUNCTION_POINTER)
};

void LogPrint(int prio, char * msg)
{
    char * str;
    if(prio == 1)       {str = "DEBUG"; GREEN_COLOR; }
    else if(prio == 2)  {str = "ERROR"; RED_COLOR;  }

    printf("[%s] : %s : %s : %d : %s \n", str, __FILE__, __FUNCTION__,  __LINE__, msg);
    RESET_COLOR;
}

void Swap(int * arrayPtr, int index_1, int index_2)
{
    if(arrayPtr)
    {
        int temp = arrayPtr[index_1];
        arrayPtr[index_1] = arrayPtr[index_2];
        arrayPtr[index_2] = temp;
    }
}

void PrintArray(const char * str, int * array_ptr, unsigned int array_size, ALGORITHM_enum algo_choice)
{
    printf(" %s %s\t :", str, algorithm_str[algo_choice]);
    for(int i=0; i<array_size; i++)
        printf(" %d,", array_ptr[i]);
    printf("\b.\n");    // To remove last ','
}

int IsArraySizeValid(int array_size)
{
    if((array_size >= MIN_ARRAY_SIZE) && (array_size <= MAX_ARRAY_SIZE))
        return YES;
    else
        return NO;
}

void All_Sort(int * array_ptr, unsigned int array_size)
{
    int * dummy_array_ptr = (int *)calloc(array_size, sizeof(int));
    if(dummy_array_ptr)
    {
        for(ALGORITHM_enum i=1; i<MAX_SORTING; i++)
        {
            printf(" ************************* \n");
            for(int j=0; j<array_size; j++)
                dummy_array_ptr[j] = array_ptr[j];

            PRINT_BEFORE(dummy_array_ptr, array_size, i);
            algorithm_function_ptr[i](dummy_array_ptr, array_size);
            PRINT_AFTER(dummy_array_ptr, array_size, i);
        }

        FREE(dummy_array_ptr);
    }
}
