
//Preprocessor directives
#include<stdio.h>
#include<string.h>
#include"main.h"
#include"lexical_analyser.h"


/*
DESCRIPTION : Function to print operators and special characters
INPUT  : file pointer, char, special character array
OUTPUT : 

==    :  Relational Operator
<<    :  Bitwise operator
 */
Status Print_operators( FILE *fptr, char char_i, char * special_characters )
{

	// Condition to check for operators
	if( char_i == '=' )
	{
	    char_i = fgetc(fptr);
	    if( char_i == '=' ) // condition to check for relational or assignment operators
	    {
		printf("== \t: Relational Operator\n");
	    }
	    else
	    {
		printf("= \t: Assignment Operator\n");
		fseek(fptr,-1,SEEK_CUR);
	    }
	}
	else if( char_i == '<' )
	{
	    char_i = fgetc(fptr);
	    if( char_i == '=' ) // condtion to check for relational operator
	    {
		printf("<= \t: Relational Operator\n");
	    }
	    else if( char_i == '<' )
	    {
		char_i = fgetc(fptr);
		if( char_i == '=' ) // condition to check for assignment and bitwise operator
		{
		    printf("<<= \t: Assignment Operator\n");
		}
		else
		{
		    puts("<< \t: Bitwise Operator");
		    fseek(fptr, -1, SEEK_CUR);
		}
	    }
	    else
	    {
		puts("< \t: Relational Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }

	}
	else if( char_i == '>' ) 
	{
	    char_i = fgetc(fptr);
	    if( char_i == '=' ) // condition to check for relational operator
	    {
		printf(">= \t: Relational Operator\n");
	    }
	    else if( char_i == '>' )
	    {
		char_i = fgetc(fptr);
		if( char_i == '=' ) // condition to check for assignment and bitwise operator
		{
		    printf(">>= \t: Assignment Operator\n");
		}
		else
		{
		    puts(">> \t: Bitwise Operator");
		    fseek(fptr, -1, SEEK_CUR);
		}
	    }
	    else
	    {
		puts("> \t: Relational Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '-' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '-' ) // conditions to check for unary arrow and arithmetic operator
	    {
		puts("-- \t: Decrement operator");
	    }
	    else if( char_i == '>' )
	    {
		puts("-> \t: Arrow Operator");
	    }
	    else if( char_i == '=' ) 
	    {
		puts("-= \t: Assignment Operator");
	    }
	    else
	    {
		puts("- \t: Arithmetic Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '+' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '+' ) // conditions to check for unary, assignemnt and arithmetic operator
	    {
		puts("++ \t: Increment operator");
	    }
	    else if( char_i == '=' ) 
	    {
		puts("+= \t: Assignment Operator");
	    }
	    else
	    {
		puts("+ \t: Arithmetic Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '&' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '&' ) // conditionns to check for logical assignment and bitwise operator
	    {
		puts("&& \t: Logical operator");
	    }
	    else if( char_i == '=' ) 
	    {
		puts("&= \t: Assignment Operator");
	    }
	    else
	    {
		puts("& \t: Bitwise Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '|' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '|' ) // conditions to check for logical assignemnt and bitwise operator
	    {
		puts("|| \t: Logical operator");
	    }
	    else if( char_i == '=' ) 
	    {
		puts("|= \t: Assignment Operator");
	    }
	    else
	    {
		puts("| \t: Bitwise Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '*' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '=' )  // condition to check for assignment and arithmetic operator
	    {
		puts("*= \t: Assignment Operator");
	    }
	    else
	    {
		puts("* \t: Arithmetic Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '/' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '=' ) // conditions to check for assignment and arithmetic operator
	    {
		puts("/= \t: Assignment Operator");
	    }
	    else
	    {
		puts("/ \t: Arithmetic Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '%' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '=' ) // conditions to check for assignment and arithmetic operator
	    {
		puts("%= \t: Assignment Operator");
	    }
	    else
	    {
		puts("% \t: Arithmetic Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '^' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '=' ) // conditions to check for assignment and bitwise operator
	    {
		puts("^= \t: Assignment Operator");
	    }
	    else
	    {
		puts("^ \t: Bitwise Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '!' )
	{
	    char_i = fgetc(fptr);

	    if( char_i == '=' ) // conditions to check for assignment and unary operator
	    {
		puts("!= \t: Assignment Operator");
	    }
	    else
	    {
		puts("! \t: Unary Not Operator");
		fseek(fptr, -1, SEEK_CUR);
	    }
	}
	else if( char_i == '.' ) // check for dot operator
	{
	    puts(". \t: Dot Operator");
	}
	else if( char_i == '~' ) // check for compliment operator
	{
	    puts("~ \t: Compliment Operator");
	}
	else if( char_i == ',' ) // check for comma operator
	{
	    puts(", \t: Comma Operator");
	}
	else
	{
	    // Loop to check for special characters
	    for(int i=0;i<SPECIAL_CHAR_COUNT;i++)
	    {
		if(char_i == special_characters[i])
		{
		    printf("%c \t: Special Character\n",char_i);
		}
	    }
	}
    return e_success;
}
