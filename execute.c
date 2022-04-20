#include "main.h"

/**
 * check_execution - checks how to execute the command.
 * @tokens: array that contains tokens
 * @string: string captured in the stdin.
 * Return: Nothing.
 */

void check_execution(char **tokens, char *string)
{
	char *ruta;

	if (tokens[0][0] == '/')
		execute(tokens, string);
	else if (tokens[0][0] == '.')
		execute(tokens, string);
	else
	{
		ruta = find_path(tokens[0]);
		tokens[0] = ruta;
		if (tokens[0] == NULL)
		{
			perror("./shell1");
			free(tokens);
		}
		else
			execute(tokens, string);
		free(ruta);
	}
}

/**
 * execute - executes the command.
 * @tokens: array that contains tokens
 * @string: string captured in the stdin.
 * Return: Nothing.
 */

void execute(char **tokens, char *string)
{
	pid_t fork_id, w_pid; /*w_pid, pid, ppid*/

/*printf("in execute tokens [0] = %s\n", tokens[0]);*/
	fork_id = fork();

	if (fork_id == -1)
	{
		free(tokens);
		perror("./shell2");
	}

	if (fork_id == 0)
	{
		if (execv(tokens[0], tokens) == -1)
		{
			free(tokens);
			free(string);
			perror("./shell3");
			exit(127);
		}
		free(tokens);
		free(string);
	}

	if (fork_id != 0)
	{
		w_pid = wait(NULL);
		if (w_pid == -1)
			perror("./shell4");
		free(tokens);
	}
}
