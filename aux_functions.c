#include "main.h"
/**
 * _strtok - Split the string in tokens.
 * @tokens: Array contains the tokens.
 * @string: Entered line.
 * @delim: chars to separate the string
 * @return: Array with tokens.
 */

char **_strtok(char **tokens, char *string, char *delim)
{
        char *token = NULL;
        int i = 0;

        if ((tokens = malloc(10 * sizeof(char *))) == NULL)
        {
                free(tokens);
                free(string);
                perror("./shell5");
                return(NULL);
        }

        token = strtok(string, delim);
        while (token != NULL)
        {
                tokens[i] = token;
                /*printf("%s\n", tokens[i]);*/
                i++;
                token = strtok(NULL, delim);
        }
        tokens[i + 1] = NULL;
        /*printf("in func tokenize tokens[0]=%s\n", tokens[0]);*/
        free(token);
        /*free(string);*/
        return (tokens);
}
