#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "morse_decode.h"

int main(int argc, char** argv)
{
    if (argc != 2) 
    {
        printf("Usage: morse_decode \"morse_to_decode\"");
        return 1;
    }

    char* message = argv[1];

    // Make sure enough space is allocated for the output (grossly overestimated)
    // Calloc ensures memory is zeroed so string will be null terminated
    char* output = calloc(strlen(message), sizeof(char));
    char* output_p = output;

    // Split message into tokens
    char *token = strtok(message, " ");
    while(token) {
        sprintf(output_p++, "%c", decode_morse_token(token));
        token = strtok(NULL, " ");
    }

    // Check if error token '$' is found in the string
    if (strstr(output, "$")){
        puts("Incorrectly formatted input entered.");
        return 2;
    }

    printf("Decoded message: %s\n", output);

    return 0;
}