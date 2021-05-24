#include <stdio.h>
#include "common_include.h"

extern char algorithm_str[MAX_SORTING][100];
extern void (*algorithm_function_ptr[MAX_SORTING+1])(int *, unsigned int);

int main(int argc, char ** argv)
{
    char * file_name_ptr = NULL;
    int input_choice = 0;
    int * array_ptr = NULL;
    unsigned int array_size = 0;
    ALGORITHM_enum algorithm_choice = 0;
    char wanna_exit = 'c';

    Inroduction();

    do
    {
        file_name_ptr = ChoiceOfInputMenu(&input_choice);

        switch(input_choice)
        {
            case ARRAY_INPUT_CHOICE_TERMINAL:
                array_ptr = InputFromTerminal(&array_size);
                break;

            case ARRAY_INPUT_CHOICE_FILE:
                array_ptr = InputFromFile(&array_size, file_name_ptr);
                break;

            case ARRAY_INPUT_FROM_INPUT_TXT:
                array_ptr = InputFromFile(&array_size, "Input.txt");
                break;

            default:
                ERROR("Invalid choice of input selected by User");
                return -1;
        }

        if(NULL == array_ptr)  return -1;

        algorithm_choice = ChoiceOfAlgorithm();
        if(MAX_SORTING > algorithm_choice)
        {
            if(algorithm_choice)   PRINT_BEFORE(array_ptr, array_size, algorithm_choice);
            SetTimer();
            algorithm_function_ptr[algorithm_choice](array_ptr, array_size);
            CheckDifference(algorithm_str[algorithm_choice]);
            if(algorithm_choice)   PRINT_AFTER(array_ptr, array_size, algorithm_choice);
        }
        else
        {
            ERROR("Invalid choice of algorithm entered by User");
        }

        FREE(array_ptr);

        printf("\n Enter q/Q to exit and c/C to continue : ");
        USER_INPUT(" %c", &wanna_exit);

    }while((wanna_exit == 'c') || (wanna_exit == 'C'));

    return 0;
}