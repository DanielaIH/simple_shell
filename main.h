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

typedef struct commands
{
    char *name;
    int (*func)(va_list);
} command;

#endif