#include "main.h"

/**
 * main - interactive command line interpreter
 * @argc - number of arguments
 * @argv - arguments
 * @envp - environment
 */

/*int main(int argc, char *argv[], char *envp[])*/
int main(void)
{
	char *string, *ruta, **tokens;
	size_t n = 0;
	ssize_t gl;
	int i = 0;
	command built_ins[] = { {"exit", exit_shell}, /*{"env", ambiente},*/
				{NULL, NULL} };
/* printf("argc %d", argc);
printf("argv %s", argv[0]);
printf("envp %s\n", envp[0]); */
	do {
		string = NULL, tokens = NULL;
		n = 0;

		if (write(STDOUT_FILENO, "($) ", 4) == -1) /* prints the prompt*/
			dprintf(STDERR_FILENO, "Can't write the stdout");

		gl = getline(&string, &n, stdin);/* read the line */
		if (gl == -1)
		{
			free(string);
			if (feof(stdin))
				return (EXIT_SUCCESS);
			else
				return (EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
		}
		tokens = _strtok(tokens, string, " \t\n");
/*printf("after tokenfn tokens[0] =%s\n", tokens[0]);*/
		for (i = 0; built_ins[i].name; i++)
		{
			if (strcmp(built_ins[i].name, tokens[0]) == 0)
			{
				free(string);
				built_ins[i].func(tokens);
				return (EXIT_SUCCESS);
			}
		}
		if (tokens[0][0] == '/')
			execute(tokens);
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
				execute(tokens);
			free(ruta);
		}
		free(string);
	} while (1);
	free(tokens);
	return (0);
}
