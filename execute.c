#include "main.h"

/**
 * execute - executes the command.
 * @tokens: array that contains tokens
 * Return: Nothing.
 */

void execute(char **tokens)
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
			perror("./shell3");
		}
	}

	if (fork_id != 0)
	{
		w_pid = wait(NULL);
		if (w_pid == -1)
			perror("./shell4");
		free(tokens);
	}
}
