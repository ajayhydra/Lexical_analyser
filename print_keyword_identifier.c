
//Preprocessor directives
#include<stdio.h>
#include<string.h>
#include"main.h"
#include"lexical_analyser.h"

/*
DESCRIPTION : Function to print keyword or identifier
INPUT  : temperary string , index, file pointer, char, keyword array, keyword flag
OUTPUT : 

int   :  Keyword
num_1 :  Identifier
 */
Status Print_Keyword_or_Identifier(char * temp_str,int *index,FILE * fptr,char char_i,int *keyword_flag,char keyword[][KEYWORD_LENGTH])
{
    temp_str[(*index)++] = char_i;
    char_i = fgetc(fptr);
    // Run loop to store characters as token for keyword and identifier
    while( (char_i >= 'a' && char_i <= 'z') || (char_i >= 'A' && char_i <= 'Z') || ( char_i >= '0' && char_i <= '9' ) || ( char_i == '_' ) )
    {
	temp_str[(*index)++] = char_i;
	char_i = fgetc(fptr);
    }
    temp_str[*index] = '\0';

    *keyword_flag = 0; 

    // run loop to check if the token stored is a keyword
    for(int i=0 ;i<32;i++)
    {
	if( strcmp(temp_str,keyword[i]) == 0 )
	{
	    printf("%s \t: keyword\n",temp_str);
	    *keyword_flag = 1;
	    *index = 0;
	    break;
	}
    }
    // condition to check token is an identifier
    if( *keyword_flag == 0 )
    {
	printf("%s \t: Identifier\n",temp_str);
	*index = 0;
    }

    return e_success;
}
