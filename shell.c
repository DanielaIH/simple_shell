#include "main.h"

/**
 * main - interactive command line interpreter
 * @argc - number of arguments
 * @argv - arguments
 */

int main(int argc, char *argv[], char *envp[])
{
        char *string, **tokens, *token;
        size_t n = 0;
        ssize_t gl;
        pid_t fork_id, w_pid; /*w_pid, pid, ppid*/

        /*char *exe_envp[] = { "PATH=$PATH", NULL };*/

        printf("argc %d", argc);
        printf("argv %s", argv[0]);
        printf("envp %s", envp[0]);

        do{
                string = NULL, token = NULL, tokens= NULL;
                n = 0;

                if (write (STDOUT_FILENO, "($) ", 4) == -1) /* prints the prompt*/
                {
                        dprintf(STDERR_FILENO, "Can't write the stdout");
                }

                gl = getline(&string, &n, stdin);/* read the line */
                if (gl == -1)
                {
                        free_memory(NULL, NULL, string);
                        if(feof(stdin))
                                return (EXIT_SUCCESS);
                        else
                                return(EXIT_FAILURE); /* EXIT_SUCCESS or EXIT_FAILURE */
                }
                tokens = _strtok(tokens, string, " \t\n");

                fork_id = fork ();

                if (fork_id == -1)
                {
                        free_memory(tokens, NULL, string);
                        perror("./shell");
                        exit(EXIT_FAILURE);
                }
                if (fork_id == 0)
                {
                        if (execv(tokens[0], tokens) == -1)
                        {
                                free_memory(tokens, token, string);
                                perror("./shell");
                                exit(EXIT_FAILURE);
                        }
                }

                if (fork_id != 0)
                {
                        free_memory(tokens, token, string);
                        w_pid = wait(NULL);
                        if (w_pid == -1)
                                exit(EXIT_FAILURE);
                }
        } while (1);
        free_memory(tokens, token, string);
        return (0);
}
