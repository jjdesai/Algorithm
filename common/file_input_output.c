
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "./../common_include.h"

int GetSizeofArray(FILE * file_ptr)
{
	int array_size = 0;
	if(file_ptr)
	{
		int current_char = EOF;
		while((current_char = fgetc(file_ptr)) != EOF)
			if(current_char == ',')
				++array_size;

		if(array_size >= 1)
		{
			// Valid array size, Add one because last element do not have ','
			array_size++;
		}
		else
		{
			ERROR("Invalid array size found in file");
		}
	}
	else
	{
		ERROR("NULL pointer found");
	}
	return array_size;
}

int IsFilePresent(char * file_name_ptr)
{
    int ret = NO;
    if(file_name_ptr)
    {
        FILE * file_ptr = fopen(file_name_ptr, "r");
        if(file_ptr)    fclose(file_ptr), ret = YES;
    }
    return ret;
}

int * GetArray(FILE * file_ptr, unsigned int array_size)
{
	int * array_ptr = (int *) calloc(array_size, sizeof(int));
	if(array_ptr)
	{
		int i = 0;
		char word[100] = {0};
		char * token;

		// To jump pointer into begining of the file
		fseek(file_ptr, 0, SEEK_SET);
		// To skip Unsorted array word
		fscanf(file_ptr, "%s : ", word);

		while(fscanf(file_ptr, "%s", word) != EOF)
		{
			const char s[2] = ",";
			
			token = strtok(word, s);
			while( token != NULL ) 
			{
				array_ptr[i++] = atoi(token);
				token = strtok(NULL, s);
			}
		}
	}
	else
	{
		ERROR("Mmeory allocation failed");
	}
	return array_ptr;
}

int * ReadArrayFromFile(unsigned int * array_size_ptr, char * file_name_ptr)
{
    int * array_ptr = NULL;
    if(array_size_ptr && file_name_ptr)
    {
        FILE * file_ptr = NULL;
        file_ptr = fopen(file_name_ptr, "r");
        if(file_ptr)
        {
            (*array_size_ptr) = GetSizeofArray(file_ptr);

            if(YES == IsArraySizeValid((*array_size_ptr)))
            {
                array_ptr = GetArray(file_ptr, (*array_size_ptr));
                if(array_ptr)
                {
                    
                }
                else
                {
                    ERROR("Did not get valid array input from file");
                }
            }
            fclose(file_ptr);
        }
        else
        {
            ERROR("File is not present");
        }
    }
    else
    {
        ERROR("Null pointer found");
    }
    return array_ptr;
}

int * InputFromFile(unsigned int * array_size_ptr, char * file_name_ptr)
{
    int * array_ptr = NULL;

    if(array_size_ptr && file_name_ptr)
    {
        (*array_size_ptr) = 0;
        if(YES == IsFilePresent(file_name_ptr))
        {
			array_ptr = ReadArrayFromFile(array_size_ptr, file_name_ptr);
        }
        else
        {
            ERROR("File is not present. Write valid file path");
        }
    }
    else
    {
        ERROR("Null pointer found");
    }

    return array_ptr;
}