#include "main.h"

/**
 * exit_shell - exits of the shell.
 * @tokens: Array contains the tokens.
 * Return: Zero if successful.
 */

int exit_shell(char **tokens)
{
	free(tokens);
	return (0);
}

/**
 * print_env - prints the current environment.
 * @tokens: double pointer to tokens.
 * Return: 1 if successful.
 */

int print_env(char **tokens __attribute__((unused)))
{
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
 * @tokens: double pointer to tokens.
 * Return: 1 if successful.
 */

int _null(char **tokens __attribute__((unused)))
{
	return (1);
}
