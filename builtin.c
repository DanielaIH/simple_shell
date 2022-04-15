#include "main.h"

/**
 * exit_shell - exits of the shell.
 * @tokens: Array contains the tokens.
 * @return: Int
 */

int exit_shell(char **tokens)
{
	free(tokens);
	return (1);
}

/**
 * env - prints the current environment.
 * @brief
 *
 */
