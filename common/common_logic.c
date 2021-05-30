
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

void Swap(int * arrayPtr1, int * arrayPtr2)
{
    if(arrayPtr1 && arrayPtr2)
    {
        int temp = *arrayPtr1;
        *arrayPtr1 = *arrayPtr2;
        *arrayPtr2 = temp;
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
    if(array_ptr)
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
                SetTimer();
                algorithm_function_ptr[i](dummy_array_ptr, array_size);
                PRINT_AFTER(dummy_array_ptr, array_size, i);
                CheckDifference(algorithm_str[i]);
            }

            FREE(dummy_array_ptr);
        }
        else
        {
            ERROR("Memory allocation failed");
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
}

void OutOfRange(int * array_ptr, unsigned int array_size)
{
    ERROR("User choose invalid algorithm");
}

int FindMaxValue(int * array_ptr, unsigned int array_size)
{
    int max=array_ptr[0];
    for(int i=1; i<array_size; i++)
        if(array_ptr[i] > max)
            max = array_ptr[i];
    return max;
}