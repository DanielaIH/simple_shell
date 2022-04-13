#include "main.h"

/**
 * main - interactive command line interpreter
 * @argc - number of arguments
 * @argv - arguments
 */

int main(int argc, char *argv[], char *envp[])
{
	char *string;
	size_t n = 0;
	ssize_t gl;
	pid_t fork_id, w_pid; /*w_pid, pid, ppid*/
	int i;
	/*char *exe_envp[] = { "PATH=$PATH", NULL };*/
	char **tokens;
	char *token;

	printf("%d", argc);
	printf("%s", argv[0]);
	printf("%s", envp[0]);

	do{
		string = NULL;
		n = 0, i = 0;

		if (write (STDOUT_FILENO, "($) ", 4) == -1) /* prints the prompt*/
		{
			dprintf(STDERR_FILENO, "Can't write the stdout");
		}
		
		gl = getline(&string, &n, stdin);/* read the line */
		if (gl == -1)
		{
			free_memory(NULL, NULL, string);
			if(feof(stdin))
				return (EXIT_SUCCESS);
			else
				return(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
		}
		
		if ((tokens = malloc(10 * sizeof(char *))) == NULL)
		{
			free_memory(tokens, NULL, NULL);
			return(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
		}

		token = strtok(string, " \t\n");
		while (token != NULL)
		{
			tokens[i] = token;
			printf("%s\n", tokens[i]);
			i++;
			token = strtok(NULL, " \t\n");
			fflush(stdout);
		}
		tokens[i] = NULL;

		fork_id = fork ();

		if (fork_id == -1)
		{
			free_memory(tokens, token, string);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		if (fork_id == 0)
		{
			if (execv(tokens[0], tokens) == -1)
			{
				free_memory(tokens, token, string);
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}

		if (fork_id != 0)
		{
			free_memory(tokens, token, string);
			w_pid = wait(NULL);
			if (w_pid == -1)
				exit(EXIT_FAILURE);
		}
	} while (1);
	free_memory(tokens, token, string);
	return (0);
}
