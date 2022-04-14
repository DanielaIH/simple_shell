#include "main.h"

char *find_path(char *command)
{
    extern char **environ;
    char *copy = NULL, **env = environ;
    char **directories = malloc(1024), *directory = NULL;
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
                directories[i] = strdup(directory);
                strcat(directories[i], "/");
                strcat(directories[i], command);
                /*printf("%s\n", directories[i]);*/
                if (stat(directories[i], &st) == 0)
                {
                        free(copy);
                        return (directories[i]);
                        break;
                }
                i++;
                directory = strtok(NULL, ":");
        }
        free(copy);
        free(directories);
        return (NULL);
}
