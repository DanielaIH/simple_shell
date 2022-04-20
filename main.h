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

/**
 * struct built_in - Struct than contains the built in commands.
 * @name: name of the built in function.
 * @func: call to execute the built in function.
 */

typedef struct built_in
{
	char *name;
	int (*func)(char **);
} command;

extern char **environ;

char **_strtok(char **tokens, char *string, char *delim);
char *find_path(char *command);
int exit_shell(char **tokens);
void execute(char **tokens, char *string);
int print_env(char **tokens);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
int _null(char **tokens);
int check_builtins(char **tokens, char *string);
void check_execution(char **tokens, char *string);

#endif
