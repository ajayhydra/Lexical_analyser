

//Preprocessor directives
#include<stdio.h>
#include<string.h>
#include"main.h"
#include"lexical_analyser.h"



/*
DESCRIPTION : Function to print string literals
INPUT  : temporary string, index, file pointer, char
OUTPUT : 

"%d\n"    :  String Literal
 */
Status Print_string_literal( char *temp_str, int *index, FILE *fptr, char char_i )
{
    temp_str[(*index)++] = char_i;
    char_i = fgetc(fptr);
    while( char_i != '"')
    {
	// error handling for string literal
	if(char_i == '\n')
	{
	    return e_failure;
	}
	temp_str[(*index)++] = char_i;
	char_i = fgetc(fptr);
    }
    temp_str[(*index)++] ='"';
    temp_str[*index] = '\0';
    printf("%s \t: String Literal\n",temp_str);
    *index = 0;
    return e_success;
}
