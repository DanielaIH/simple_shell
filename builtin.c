#include "main.h"

/**
 * exit_shell - exits of the shell.
 * @tokens: Array contains the tokens.
 * Return: Int
 */

int exit_shell(char **tokens)
{
	free(tokens);
	return (0);
}

/**
 * env - prints the current environment.
 * @brief
 *
 */

int print_env(char **tokens __attribute__((unused)))
{
	extern char **environ;
	char **env = environ;
	unsigned int i, size = 0;

    i = 0;
    while (env[i] != NULL)
    {
        size = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], size);
		write(STDOUT_FILENO, "\n", 1);
        i++;
    }

	return (1);
}

/**
 * _null - return 1.
 * @brief
 *
 */

int _null(char **tokens __attribute__((unused)))
{
	return (1);
}
