
#include <stdio.h>

#include "./../common_include.h"

/*
    Author              : Jay Desai
    Algorithm           : Merge Sort
    Worst Complexity    : n log(n)
    Average Complexity  : n log(n)
    Best Complexity     : n log(n)
    Space Complexity    : n
    Stable              : Yes
    Method              : Merge
*/

void Merge(int * array_ptr, int left, int middle, int right)
{
    int i,j,k;
    int left_array_size = middle - left + 1;
    int right_array_size = right - middle;

    int * left_array_ptr = calloc(left_array_size, sizeof(int));
    if(!left_array_ptr)
    {
        ERROR("Memory allocation failed");
        return;
    }

    int * right_array_ptr = calloc(right_array_size, sizeof(int));
    if(!right_array_ptr)
    {
        ERROR("Memory allocation failed");
        return;
    }

    // Copy left array from main array
    for(i=0; i<left_array_size; i++)
        left_array_ptr[i] = array_ptr[left+i];

    // Copy right array from main array
    for(j=0; j<right_array_size; j++)
        right_array_ptr[j] = array_ptr[middle+1+j];

    // Merge two different array in main array
    i=0; j=0; k=left;
    while(i<left_array_size && j<right_array_size)
    {
        if(left_array_ptr[i] <= right_array_ptr[j])
            array_ptr[k] = left_array_ptr[i++];
        else
            array_ptr[k] = right_array_ptr[j++];
        k++;
    }

    // Remaining left array copied to main array
    while(i<left_array_size)
        array_ptr[k++] = left_array_ptr[i++];

    // Remaining right array copied to main array
    while(j<right_array_size)
        array_ptr[k++] = right_array_ptr[j++];

}

void MergeSort(int * array_ptr, int left, int right)
{
    if(left < right)
    {
        int middle = (left + (right-1)) / 2;
        
        MergeSort(array_ptr, left, middle);
        MergeSort(array_ptr, middle+1, right);

        Merge(array_ptr, left, middle, right);
    }
}

void Merge_Sort(int * array_ptr, unsigned int array_size)
{
    if(array_ptr)
    {
        MergeSort(array_ptr, 0, array_size-1);
    }
    else
    {
        ERROR("Null pointer found");
    }
}