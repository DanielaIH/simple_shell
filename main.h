#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> /* definitions */
#include <sys/stat.h> /* structure of the data */
#include <sys/wait.h>
#include <fcntl.h> /* open() */
#include <unistd.h> /* constants */

typedef struct built_in
{
    char *name;
    int (*func)(char**);
} command;

char **_strtok(char **tokens, char *string, char *delim);
char *find_path(char *command);
int exit_shell(char **tokens);
void execute(char **tokens);

#endif
