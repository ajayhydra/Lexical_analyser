/*
NAME : G.AJAY REDDY
DESCRIPTION : Purpose of the project is to do lexical analysing, converting the sequence of characters into sequence of tokens
 */

#include<stdio.h>
#include"main.h"


/*
DESCRIPTION : Main function to the program execution
INPUT :  command line argument count , commandline arguments
OUTPUT : NONE
 */
int main(int argc, char *argv[])
{
    // Declare File pointer
    FILE *fptr;
    if(argc > 1)
    {
	// Read and validate input arguments 
	// In case of failure through error 
	if( read_and_validate_arguments( argv ) == e_success )
	{
	    // Open the input source file 
	    if(open_file( &fptr, argv[1] ) == e_success)
	    {
		// Function call to lexical analyser
		if(lexical_analyser(fptr) == e_success )
		{
		    puts("INFO : Tokens Generated");
		}
		else
		{
		    puts("ERROR : Token cannot be generated");
		}
	    }
	}
	else
	{
	    puts("ERROR : Pass Valid arguments");
	}
    }
    else
    {
	puts("ERROR : Pass .c file in the argument");
    }

    return 0;
}
