#include "main.h"

/**
 * main - interactive command line interpreter
 * @argc - number of arguments
 * @argv - arguments
 */

int main(void)
{
/*  int argc, char **argv[], extern char **environ; */
    char *string = NULL;
    size_t n = 0;
    ssize_t gl;
    pid_t fork_id, w_pid; /*w_pid, pid, ppid*/
    int i = 0, buffer = 1024;
    /*char *exe_envp[] = { "PATH=$PATH", NULL };*/
    char **tokens = malloc(buffer * sizeof(char *));
    char *token;
    

    do{
        printf("($) ");    /* prints the prompt*/
        /* ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream); */
        gl = getline(&string, &n, stdin);/* read the line */
        if (gl == -1)
        {
            if(feof(stdin))
            {
                free(string);
                return (EXIT_SUCCESS);
            }
            else
            {
                free(string);
                return(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
            }
        }
        
        token = strtok(string, " ");
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
    free(string);
    return (0);
}
