// Preprocessor directive
#include<stdio.h>
#include<string.h>
#include"main.h"

/*
DESCRIPTION : Function to open file and check file is not empty
INPUT  : File pointer and file name passed through the commandline 
OUTPUT : Status success/ failure
 */
Status open_file( FILE **fptr, char *file_name )
{
    // Opening File in read mode
    *fptr = fopen(file_name , "r");

    // Error Handling
    if(*fptr == NULL )
    {
	fprintf(stderr,"ERROR : Unable to open file %s\n",file_name);
	return e_failure;
    }

    
    fseek(*fptr, 0 , SEEK_END);

    // condition to check for file empty
    if( ftell(*fptr) == 0 )
    {
	puts("ERROR : Empty file");
	return e_failure;
    }
    fseek(*fptr, 0, SEEK_SET);

    return e_success;
}
