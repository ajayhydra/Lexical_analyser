
//Preprocessor directives
#include<stdio.h>
#include<string.h>
#include"main.h"
#include"lexical_analyser.h"


/*
DESCRIPTION : Function to print integer and floating point constant and do error check for both
INPUT  : temperary string , index, file pointer, char
OUTPUT : 

123  :  Integer constant
12L  :  Integer constant
1.2F :  Floating point constant
 */
Status Print_integer_floating_constant( char *temp_str, int *index,FILE *fptr,char char_i, int *int_flag_1, int *int_flag_2, int *float_flag )
{

    temp_str[(*index)++] = char_i;
    char_i = fgetc(fptr);
    // Run loop to store characters as token for interger constants 
    while( char_i >= '0' && char_i <= '9' || char_i >= 'a' && char_i <='z' || char_i >='A' && char_i <= 'Z' )
    {
	// error handling for unsigned and long integer
	if(*int_flag_1 == 1 )
	{
	    return e_failure;
	}
	// error handling for hexa decimal
	if( *int_flag_2 == 1 && temp_str[0] != '0' )
	{
	    return e_failure;
	}
	if( (char_i >= 'a' && char_i <= 'z') || (char_i >= 'A' && char_i <= 'Z') )
	{
	    if( *int_flag_2 == 0 )
	    {
		// condition to check for unsigned and long integer
		if( char_i == 'u' || char_i == 'l' || char_i == 'U' || char_i == 'L' )
		{
		    (*int_flag_1)++;
		}
		else if( char_i == 'x' || char_i == 'X' ) // condition to check for hexa decimal
		{
		    (*int_flag_2)++;
		}
		else 
		{
		    return e_failure;
		}
	    }
	    else if( temp_str[0] == '0' )
	    {
		// error handling for hexa decimal
		if( !( char_i == 'a' || char_i == 'A' || char_i == 'b' || char_i == 'B' || char_i == 'c' || char_i == 'C' || char_i == 'd' || char_i == 'D' || char_i == 'e' || char_i == 'E' || char_i == 'f' || char_i == 'F' ) )
		{
		    return e_failure;
		}
	    }
	}

	if( *int_flag_1 > 1 || *int_flag_2 > 1 )
	{
	    return e_failure;
	}
	temp_str[(*index)++] = char_i;
	char_i = fgetc(fptr);
    }
    // condition to check for floating point constant
    if(char_i == '.')
    {
	temp_str[(*index)++] = char_i;
	char_i = fgetc(fptr);
	while( (char_i >= '0' && char_i <='9') || (char_i >= 'a' && char_i <= 'z' ) || ( char_i >= 'A' && char_i <= 'Z' ) )
	{
	    // error handling for floating point constant
	    if( *float_flag == 1 )
	    {
		return e_failure;
	    }
	    if( (char_i >= 'a' && char_i <= 'z') || (char_i >= 'A' && char_i <= 'Z') )
	    {
		if( char_i == 'f' || char_i == 'F' )
		{
		    (*float_flag)++;
		}
		else
		{
		    return e_failure;
		}
	    }
	    temp_str[(*index)++] = char_i;
	    char_i = fgetc(fptr);
	}
	temp_str[(*index)] = '\0';
	printf("%s \t: Floating point constant\n",temp_str);
	*index = 0;
	*float_flag = 0;
    }
    else
    {
	temp_str[*index] = '\0';
	printf("%s \t: Integer Constant\n",temp_str);
	*index = 0;
	*int_flag_1 = 0;
	*int_flag_2 = 0;
    }

    return e_success;
}
