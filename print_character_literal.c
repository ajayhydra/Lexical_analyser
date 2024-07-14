
//Preprocessor directives
#include<stdio.h>
#include<string.h>
#include"main.h"
#include"lexical_analyser.h"


/*
DESCRIPTION : Function to print character literal and do error check for character literal
INPUT  : temperary string , index, file pointer, char
OUTPUT : 

'a'  :  Character literal 
'\n' :  Character literal
 */
Status Print_character_literal( char *temp_str, int *index, FILE *fptr, char char_i )
{
    int count = 0;
    temp_str[(*index)++] = char_i;
    char_i = fgetc(fptr);

    while( char_i != '\'')
    {
	if( count > 2 )
	{
	    return e_failure;
	}
	temp_str[(*index)++] = char_i;
	char_i = fgetc(fptr);
	count++;
	// error handling for escape sequences
	if(count == 2)
	{
	    if( temp_str[1] != '\\' )
	    {
		return e_failure;
	    }
	}
    }
    temp_str[(*index)++] ='\'';
    temp_str[*index] = '\0';
    printf("%s \t: Character Literal \n",temp_str);
    *index = 0;

    return e_success;
}



