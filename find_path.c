#include "main.h"

int find_path(char *command)
{
	char *path = getenv("PATH");
    char **directories, **directories2;
	char *directory;
    int i = 0;
    struct stat st;
    char *slash = "/";

    printf("path: %s\n", path);
    printf("command: %s\n", command);
	/* char *string_path = malloc(strlen(path) + strlen(command) + 2);*/
    directories = malloc(50 * sizeof(char *));
    directory = strtok(path, ":");
		while (directory != NULL)
		{
			directories[i] = directory;
			printf("%s\n", directories[i]);
			i++;
			directory = strtok(NULL, ":");
			fflush(stdout);
		}
		directories[i] = NULL;
    directories2 = malloc(i * sizeof(char *));
    i = 0;
    while (directories[i])
    {
        directories2[i] = strcat(directories[i], slash);
        i++;
    }
    i = 0;
    while (directories2[i])
    {
        printf("%s:", directories2[i]);
        if (stat(command, &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    return (0);
}

int main(void)
{
	find_path("ls");
    return(0);
}