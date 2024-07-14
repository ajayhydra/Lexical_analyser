//Preprocessor directives
#include<stdio.h>
#include<string.h>
#include"main.h"
#include"lexical_analyser.h"

// Declare keyword array
char keyword[ KEYWORD_COUNT ][ KEYWORD_LENGTH ]={"char","int","float","double","short","long","signed","unsigned","const","volatile","if","else","switch","case","default","for","while","do","break","continue","goto","auto","register","static","extern","struct","union","enum","typedef","void","return","sizeof"};

// Declare special character array
char special_characters[ SPECIAL_CHAR_COUNT ] = {'(',')','{','}','[',']',';'};


/*
DESCRIPTION : This function will convert sequence of characters in to the sequence of tokens.
INPUT  : File pointer that traverse through the .c file
OUTPUT : Display tokens

#include<stdio.h>    : Preprocessor directive
int	    	     : keyword
main 		     : Identifier
 */
Status lexical_analyser(FILE *fptr)
{
    // Declaring index variable to traverse through the tokens
    int index = 0;
    // Declaring character variable to read one by one character from the file
    int char_i;
    // Declaring character array
    char temp_str[ TEMP_STRING_LENGTH ];
    // Declaring keyword flag to make difference between keyword and identifier
    int keyword_flag = 0;
    // Declaring interger flags ang float flags to check errors in integer and floating point constant
    int int_flag_1 = 0, int_flag_2 = 0, float_flag = 0 ;


    // Loop to read character by character in the .c file upto end of the file
    while( ( char_i = fgetc(fptr) ) != EOF )
    {
	// Condition to check pre processor directive
	if( char_i == '#' )
	{
	    // Function call to print preprocessor directive
	    if( Print_Preprocessor_Directive(temp_str, &index, fptr, char_i) != e_success )
	    {
		return e_failure;
	    }

	}
	// Condition to check for keyword and identifier
	if( (char_i >= 'a' && char_i <= 'z') || (char_i >= 'A' && char_i <= 'Z') || ( char_i == '_' ) )
	{
	    // Function call to print keyword or identifier
	    if( Print_Keyword_or_Identifier(temp_str, &index, fptr, char_i, &keyword_flag, keyword) != e_success  )
	    {
		return e_failure;
	    }
	}

	// Condition to check for integer and floating point constant
	if( char_i >= '0' && char_i <= '9'  )
	{
	    // Function call to print integer or floating point constant
	    if ( Print_integer_floating_constant( temp_str, &index, fptr, char_i, &int_flag_1, &int_flag_2, &float_flag ) != e_success )
	    {
		return e_failure;
	    }
	}

	// Condition to check for character literal
	if( char_i == '\'' )
	{
	    // Function call to print character literal
	    if( Print_character_literal(temp_str, &index, fptr, char_i) != e_success )
	    {
		return e_failure;
	    }

	}

	// Condition to check for string literal
	if( char_i == '"' )
	{
	    // Function call to print string literal
	    if( Print_string_literal(temp_str, &index, fptr, char_i) != e_success )
	    {
		return e_failure;
	    }
	}

	// Function call to print operators and special characters
	if( Print_operators(fptr, char_i, special_characters) != e_success )
	{
	    return e_failure;
	}

    }

    return e_success;
}
