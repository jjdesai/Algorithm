#ifndef _COMMON_INCLUDE_H_
#define _COMMON_INCLUDE_H_

#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO  0

#define TRUE    1
#define FALSE   0

#define MIN_ARRAY_SIZE      2
#define	MAX_ARRAY_SIZE      100

#define ARRAY_INPUT_CHOICE_TERMINAL   1
#define ARRAY_INPUT_CHOICE_FILE       2

//#define DEBUG_LOG   1
//#define ERROR_LOG   2

#define RESET_COLOR     printf("\033[0m");
#define BLACK_COLOR     printf("\033[0;30m");
#define RED_COLOR       printf("\033[0;31m");
#define GREEN_COLOR     printf("\033[0;32m");
#define YELLOW_COLOR    printf("\033[0;33m");
#define BLUE_COLOR      printf("\033[0;34m");
#define PURPLE_COLOR    printf("\033[0;35m");
#define CYAN_COLOR      printf("\033[0;36m");
#define WHILE_COLOR     printf("\033[0;37m");

#define USER_INPUT(x, y)    GREEN_COLOR \
                            scanf(x, y);\
                            RESET_COLOR

#define LOG_MESSAGE(prio, msg, ...)                                                     \
        {                                                                               \
            char * str;                                                                 \
            if(DEBUG_LOG == prio )      {   str = "DEBUG";    GREEN_COLOR;      }       \
            else if(ERROR_LOG == prio)  {   str = "ERROR";    RED_COLOR;        }       \
            printf("[%s] : %s:%d : "msg" \n", str,  __FILE__, __LINE__, ##__VA_ARGS__); \
            RESET_COLOR;                                                                \
        }

#define ERROR(msg, ...)                                                                     \
        {                                                                                   \
            char * str = "ERROR";                                                           \
            RED_COLOR;                                                                      \
            printf("[%s] : %s:%d : "msg" \n", str,  __FILE__, __LINE__, ##__VA_ARGS__);     \
            RESET_COLOR;                                                                    \
        }
        
#define DEBUG(msg, ...)                                                                     \
        {                                                                                   \
            char * str = "DEBUG";                                                           \
            YELLOW_COLOR;                                                                   \
            printf("[%s] : %s:%d : "msg" \n", str,  __FILE__, __LINE__, ##__VA_ARGS__);     \
            RESET_COLOR;                                                                    \
        }

#define FREE(pointer)   if(pointer) { free(pointer); pointer=NULL;  }

#define GENERATE_ENUM(enum, string, function_ptr)               enum,
#define GENERATE_STRING(enum, string, function_ptr)             string,
#define GENERATE_FUNCTION_POINTER(enum, string, function_ptr)   function_ptr,

#define ALGORITHM(X)                                                                    \
    X(APPLY_ALL_SORTING,        "All Sorting",              All_Sort)                   \
    X(BUBBLE_SORT,              "Bubble Sort",              Bubble_Sort)                \
    X(SELECTION_SORT,           "Selection Sort",           Selection_Sort)             \
    X(INSERTION_SORT,           "Insertion Sort",           Insertion_Sort)             \
    X(RECURSIVE_INSERTION_SORT, "Recursive Insertion Sort", Recursive_Insertion_Sort)   \
    X(PANCAKE_SORT,             "Pancake Sort",             Pancake_Sort)               \
    X(BOGO_PERMUTATION_SORT,    "Bogo/Permutation Sort",    Bogo_Sort)                  \
    X(MAX_SORTING,              "Max Algorithm",            NULL)                       \

typedef enum { ALGORITHM(GENERATE_ENUM) }ALGORITHM_enum;

#define PRINT_AFTER(x,y,z)  PrintArray("After", x,y,z)
#define PRINT_BEFORE(x,y,z) PrintArray("Before", x,y,z)

void LogPrint(int prio, char * msg);
void Swap(int * arrayPtr, int index_1, int index_2);
void PrintArray(const char * str, int * array_ptr, unsigned int array_size, ALGORITHM_enum algo_choice);
int IsArraySizeValid(int array_size);

void Inroduction(void);
char * ChoiceOfInputMenu(int * input_choice_ptr);
ALGORITHM_enum ChoiceOfAlgorithm(void);

int * InputFromFile(unsigned int * array_size_ptr, char * file_name_ptr);
int * InputFromTerminal(unsigned int * array_size_ptr);

// Algorithm Function to be added below
void All_Sort(int * array_ptr, unsigned int array_size);
void Bubble_Sort(int * array_ptr, unsigned int array_size);
void Selection_Sort(int * array_ptr, unsigned int array_size);
void Insertion_Sort(int * array_ptr, unsigned int array_size);
void Recursive_Insertion_Sort(int * array_ptr, unsigned int array_size);
void Bogo_Sort(int * array_ptr, unsigned int array_size);
void Pancake_Sort(int * array_ptr, unsigned int array_size);

#endif