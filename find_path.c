#include "main.h"

/**
 * find_path - searches in PATH the executable command file.
 * @command: Command.
 * Return: Nothing.
 */

char *find_path(char *command)
{
	extern char **environ;
	char *copy = NULL, *ruta = NULL, **env = environ;
	char **directories = malloc(100), *directory = NULL;
	struct stat st;
	int count = 0, i = 0, j = 0;

	for (count = 0; env[count] != NULL; count++)
	{
		if ((strncmp("PATH", env[count], 4)) == 0)
			break;
	}
	copy = malloc(strlen(env[count]) + 1);
	strcpy(copy, env[count]);
	directory = strtok(copy, ":=");
	while (directory != NULL)
	{
		directories[i] = malloc(strlen(directory) + strlen(command) + 2);
		strcpy(directories[i], directory);
		strcat(directories[i], "/");
		strcat(directories[i], command);
/*printf("%s\n", directories[i]);*/
		if (stat(directories[i], &st) == 0)
		{
			ruta = malloc(strlen(directories[i]) + 1);
			strcpy(ruta, directories[i]);
			for (j = 0; j <= i; j++)
				free(directories[j]);
			free(directories);
			free(copy);
/*printf("in findpath tokens[0] = %s\n",directories[i]);*/
			return (ruta);
		}
		i++;
		directory = strtok(NULL, ":");
	}
	for (j = 0; j < i; j++)
		free(directories[j]);
	free(directories);
	free(directory);
	free(copy);
	return (NULL);
}
