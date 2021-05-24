#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./../common_include.h"

extern char algorithm_str[MAX_SORTING][100];

void Inroduction(void)
{
    system("clear");
    printf(" \n");
    printf(" *******************************************\n");
    printf(" **** Welcome to the world of Algorithm ****\n");
    printf(" *******************************************\n");
}

char * ChoiceOfInputMenu(int * input_choice_ptr)
{
    char * file_path_ptr = NULL;
    
    printf("\n Select choice of Input :\n");
    YELLOW_COLOR;
    printf(" \t1. Terminal\n");
    printf(" \t2. File\n");
    printf(" \t3. Use Input.txt file(Option for Developer)\n");
    RESET_COLOR;

    printf(" Enter your choice : ");
    USER_INPUT(" %d", input_choice_ptr);

    if((*input_choice_ptr) == ARRAY_INPUT_CHOICE_FILE)
    {
        file_path_ptr = (char *) calloc(100, sizeof(char));
        if(file_path_ptr)
        {
            printf(" Enter the filepath here : ");
            USER_INPUT(" %s", file_path_ptr);
        }
        else
        {
            ERROR("Memory allocation failed");
        }
    }
    else if((*input_choice_ptr) == ARRAY_INPUT_CHOICE_TERMINAL)
    {
        
    }
    else
    {
        
    }

    return file_path_ptr;
}

ALGORITHM_enum ChoiceOfAlgorithm(void)
{
    printf(" \n");
    printf(" Enter your choice of algorithm from the below list : \n");
    
    ALGORITHM_enum algo_choice;

    YELLOW_COLOR;
    for(int i=0; i<MAX_SORTING; i++)
        printf(" \t%d. %s\n", i, algorithm_str[i]);
    RESET_COLOR;

    printf(" Enter your choice : ");
    USER_INPUT(" %u", &algo_choice);
    printf("\n");

    return algo_choice;   // As Enum index start with 0
}