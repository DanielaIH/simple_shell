#include "main.h"

/**
 * check_execution - checks how to execute the command.
 * @tokens: array that contains tokens
 * @string: string captured in the stdin.
 * @error: error.
 * Return: Nothing.
 */

void check_execution(char **tokens, char *string, int *error)
{
	char *ruta;
	struct stat st;

	if (tokens[0][0] == '/' || tokens[0][0] == '.')
	{
		if (stat(tokens[0], &st) == 0)
			execute(tokens, string, error);
		else
		{
			*error = 127;
			print_error(tokens, error);
			free(tokens);
		}
	}
	else
	{
		ruta = find_path(tokens[0]);
		tokens[0] = ruta;
		if (tokens[0] == NULL)
		{
			perror("");
			free(tokens);
			*error = 2;
		}
		else
			execute(tokens, string, error);
		free(ruta);
	}
}

/**
 * execute - executes the command.
 * @tokens: array that contains tokens
 * @string: string captured in the stdin.
 * Return: Nothing.
 */

void execute(char **tokens, char *string, int *error)
{
	pid_t fork_id, w_pid; /*w_pid, pid, ppid*/

/*printf("in execute tokens [0] = %s\n", tokens[0]);*/
	fork_id = fork();

	if (fork_id == -1)
	{
		free(tokens);
		perror("./DS_SHELL2");
	}

	if (fork_id == 0)
	{
		if (execv(tokens[0], tokens) == -1)
		{
			*error = 127;
			print_error(tokens, error);
			free(tokens);
			free(string);
		}
		free(tokens);
		free(string);
	}

	if (fork_id != 0)
	{
		w_pid = wait(NULL);
		if (w_pid == -1)
			perror("./DS_SHELL4");
		free(tokens);
	}
}


void print_error(char **tokens, int *error)
{
	int len_error;
	int print_error = *error;

	if (*error >= 0 && *error <= 9)
		len_error = 1;
	if (*error >= 10 && *error <= 99)
		len_error = 2;
	if (*error >= 100 && *error <= 999)
		len_error = 3;

	write(STDOUT_FILENO, "./hsh: ", 8);
	write(STDOUT_FILENO, atoi(print_error), len_error);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDOUT_FILENO, ": ", 2);
	perror("");
	write(STDOUT_FILENO, "\n", 1);
}