
#ifndef MORSE_TREE_H
#define MORSE_TREE_H

static char morse_tree[] = {'@',
                            'e', 't', 
                            'i', 'a', 'n', 'm', 
                            's', 'u', 'r', 'w', 'd', 'k', 'g', 'o', 
                            'h', 'v', 'f', '_', 'l', '_', 'p', 'j', 'b', 'x', 'c', 'y', 'z', 'q', '_', '_',
                            '5', '4', '_', '3', '_', '_', '_', '2', '_', '_', '+', '_', '_', '_', '_', '1', '6', '=', '/', '_', '_', '_', '_', '_', '7', '_', '_', '_', '8', '_', '9', '0'};

// Recursively walk through the tree above
char walk_tree(char* message, int depth);
// wrapper function for first recursive step
char decode_morse_token(char* token);

#ifdef WIN32
// windows does not have strsep
char *strsep(char **stringp, const char *delim);
#endif // WIN32

#endif // MORSE_TREE_H