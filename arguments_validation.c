// Preprocessor directive
#include<stdio.h>
#include<string.h>
#include"main.h"


/*
DESCRIPTION : Function to validate whether the file passed through the arguments is a .c file
INPUT  : Argument [.c file] passed through the command line
OUTPUT : Status success/ failure
 */
Status read_and_validate_arguments( char *argv[] )
{
    // Condition to check whether the first argument is a .c file or not
    if( strstr(argv[1],".c") != NULL )
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }
}
