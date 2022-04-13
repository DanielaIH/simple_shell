#include "main.h"

/**
 * free_memory - free the memory allocation.
 * @tokens: - structure of tokens.
 * @token: - pointer to the token.
 * @string: pointer to string.
 */

void free_memory(char **tokens, char *token, char *string)
{
        free(tokens);
        free(token);
        free(string);
}