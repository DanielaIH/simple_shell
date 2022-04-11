#include "main.h"

/**
 * main - 
 * 
 */

int main(int argc, char **argv[])
{
    extern char **environ;
    char *string = NULL;
    size_t n = 0;
    ssize_t gl;
    pid_t fork_id, w_pid, pid, ppid;
    char *argv[] = { NULL };
    char *envp[] = { NULL };

    do{
        printf("($) ");    /* prints the prompt*/
        /* ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream); */
        gl = getline(&string, &n,stdin);/* read the line */
        if (gl == -1)
        {
            free(string);
            return(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
        }
        fork_id = fork ();
        if (fork_id == -1) 
        {
               perror("fork");
               exit(EXIT_FAILURE);
        }
        if (fork_id == 0)
            execve(string, argv, envp);
        if (fork_id != 0)
            w_pid = wait(NULL);

    } while (1);
    return (0);
}