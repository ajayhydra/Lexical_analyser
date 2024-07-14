
//Preprocessor directives
#include<stdio.h>
#include<string.h>
#include"main.h"
#include"lexical_analyser.h"

/*
DESCRIPTION : Function to print operators and special characters
INPUT  : temporary string , index, file pointer, char
OUTPUT : 

Preprocessor Directive : #include<stdio.h>
 */
Status Print_Preprocessor_Directive( char *temp_str, int *index, FILE * fptr, char char_i  )
{
    temp_str[(*index)++] = char_i;
    // Run loop to store characters  as token until next line
    do
    {
	char_i = fgetc(fptr); 
	temp_str[(*index)++] = char_i;
    }while(char_i != '\n');

    temp_str[*index] = '\0';
    printf("Preprocessor Directive \t:%s",temp_str);
    *index = 0;

    return e_success;
}
