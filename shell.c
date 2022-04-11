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
    char *exe_args[] = { NULL };
    char *exe_envp[] = { "PATH=$PATH" };

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
        
        fork_id = fork ();

        if (fork_id == -1)
        {
               perror("fork");
               exit(EXIT_FAILURE);
        }
        if (fork_id == 0)
        {
            exe_args[0] = string;
            exe_args[1] = NULL;
		    if (execve(exe_args[0], exe_args, exe_envp) == -1)
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
    return (0);
}
