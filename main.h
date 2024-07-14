#ifndef MAIN_H
#define MAIN_H

// Declaring enum variable for returning status
typedef enum
{
    e_failure,
    e_success
}Status;


// Function to read and validate arguments that passed through the command line
Status read_and_validate_arguments( char *argv[] );

// Function to open and do error handling of the file that passed through the command line
Status open_file( FILE **fptr, char *file_name );

// Function will convert sequence of characters in to the sequence of tokens.
Status lexical_analyser(FILE *fptr);

#endif
