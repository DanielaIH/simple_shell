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
	ssize_t gl, fd;
	int i = 0, status = 0, tty = 1;
	command built_ins[] = { {"exit", exit_shell}, {"env", print_env},
				{"spaces", _null}, {NULL, NULL} };
	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;

	do {
		string = NULL, tokens = NULL, n = 0, status = 0;

		tty == 1 ? fd = write(STDOUT_FILENO, "($) ", 4) : tty;
		if (fd == -1)
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
		tokens = _strtok(tokens, string, " \t\n\"\'");
		if(tokens[0] == NULL)
			tokens[0] = "spaces";		
		for (i = 0; built_ins[i].name; i++)
		{
			if (_strcmp(built_ins[i].name, tokens[0]) == 0)
			{
				if (built_ins[i].func(tokens) == 0)
				{
					free(string);
					return (EXIT_SUCCESS);
				}
				else
				{
					status = 1;
					break;
				}
			}
		}
		if (status == 0)
		{
			if (tokens[0][0] == '/')
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
		else
			free(tokens);
		free(string);
	} while (1);
	free(tokens);
	return (0);
}
