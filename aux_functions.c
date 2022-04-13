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


char **_strtok(char **tokens, char *string, char *delim)
{
        char *token = NULL;
        int i = 0;

        if ((tokens = malloc(10 * sizeof(char *))) == NULL)
                {
                        free_memory(tokens, NULL, NULL);
                        exit(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
                }

                token = strtok(string, delim);
                while (token != NULL)
                {
                        tokens[i] = token;
                        /*printf("%s\n", tokens[i]);*/
                        i++;
                        token = strtok(NULL, delim);
                }
                tokens[i] = NULL;
                return (tokens);
}
