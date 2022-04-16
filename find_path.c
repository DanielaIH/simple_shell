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
	int count = 0, i = 0;

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
		ruta = malloc(strlen(directory) + strlen(command) + 2);
		strcat(ruta, directory);
		strcat(ruta, "/");
		strcat(ruta, command);
/*printf("%s\n", directories[i]);*/
		if (stat(ruta, &st) == 0)
		{
			directories[i] = malloc(strlen(ruta) + 1);
			directories[i] = strcpy(directories[i], ruta);
			free(ruta);
			free(copy);
/*printf("in findpath tokens[0] = %s\n",directories[i]);*/
			return (directories[i]);
		}
		i++;
		directory = strtok(NULL, ":");
		free(ruta);
	}
	free(copy);
	free(directories);
	return (NULL);
}
