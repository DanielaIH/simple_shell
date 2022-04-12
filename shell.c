#include "main.h"

/**
 * main - interactive command line interpreter
 * @argc - number of arguments
 * @argv - arguments
 */

int main(void)
{       /*  int argc, char **argv[], extern char **environ; */
	char *string;
	size_t n = 0;
	ssize_t gl;
	pid_t fork_id, w_pid; /*w_pid, pid, ppid*/
	int i = 0;
	/*char *exe_envp[] = { "PATH=$PATH", NULL };*/
	char **tokens;
	char *token;

	do{
		string = NULL;
		n = 0, i = 0;

		if (write (STDOUT_FILENO, "($) ", 4) == -1) /* prints the prompt*/
		{
			dprintf(STDERR_FILENO, "Can't write the stdout");
		}
		
		/* ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream); */
		gl = getline(&string, &n, stdin);/* read the line */
		if (gl == -1)
		{
			if(feof(stdin))
				return (EXIT_SUCCESS);
			else
				return(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
			free(string);
		}
		if ((token = malloc(sizeof(char) * strlen(string))) == NULL)
		{
			free(token);
			return(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
		}
		if ((tokens = malloc(strlen(string) * sizeof(char *))) == NULL)
		{
			free(tokens);
			return(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
		}
		token = strtok(string, " \t\n");
		while (token != NULL)
		{
			tokens[i] = token;
			/*printf("%s\n", tokens[i]);*/
			i++;
			token = strtok(NULL, " ");
			fflush(stdout);
		}
		tokens[i] = NULL;

		fork_id = fork ();

		if (fork_id == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		if (fork_id == 0)
		{
			if (execv(tokens[0], tokens) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		if (fork_id != 0)
		{
			w_pid = wait(NULL);
			if (w_pid == -1)
				exit(EXIT_FAILURE);
		}
	} while (1);

	for (i = 0; tokens != NULL; i++)
		free(tokens[i]);
	free(tokens);
	free(token);
	free(string);
	return (0);
}
