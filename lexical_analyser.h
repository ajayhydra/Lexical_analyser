#ifndef LEXICAL_H
#define LEXICAL_H

// define total keyword count in c language
#define KEYWORD_COUNT 32

// define length of keyword 
#define KEYWORD_LENGTH 10

// define special character count
#define SPECIAL_CHAR_COUNT 7

// define temporary string length
#define TEMP_STRING_LENGTH 100



// Function to print pre processor directive
Status Print_Preprocessor_Directive( char *temp_str, int *index, FILE * fptr, char char_i  );

// Function to print keyword or identifier
Status Print_Keyword_or_Identifier(char * temp_str,int *index,FILE * fptr,char char_i,int *keyword_flag, char keyword [][KEYWORD_LENGTH] );

// Function to print integer or floating point constant
Status Print_integer_floating_constant( char *temp_str, int *index,FILE *fptr,char char_i, int *int_flag_1, int *int_flag_2, int *float_flag );

// Function to print character literals
Status Print_character_literal( char *temp_str, int *index, FILE *fptr, char char_i );

// Function to print string literal
Status Print_string_literal( char *temp_str, int *index, FILE *fptr, char char_i );

// Function to print operators and special characters
Status Print_operators( FILE *fptr, char char_i, char * special_characters );
#endif
