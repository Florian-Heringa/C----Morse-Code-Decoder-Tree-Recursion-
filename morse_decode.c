#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#include "morse_decode.h"

char decode_morse_token(char* token)
{
    return walk_tree(token, 1);
}

char *strsep(char **stringp, const char *delim) {
  if (*stringp == NULL) { return NULL; }
  char *token_start = *stringp;
  *stringp = strpbrk(token_start, delim);
  if (*stringp) {
    **stringp = '\0';
    (*stringp)++;
  }
  return token_start;
}

char walk_tree(char* message, int depth)
{
    if (message[0] == '\0')
    {
        return morse_tree[depth - 1];
    }
    if (depth > 63)
    {
        return '$';
    }

    if(message[0] == '.')
    {
        return walk_tree(++message, depth * 2);
    }
    else if (message[0] == '-')
    {
        return walk_tree(++message, depth * 2 + 1);
    }
    else 
    {
        return '$';
    }
}