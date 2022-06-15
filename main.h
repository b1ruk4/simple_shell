#ifndef _MAIN_H_
#define _MAIN_H_
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int _putchar (char c);
int cd(char **args);
int _launch(char **args);
int _execute(char **args);
char *_read_line(void);
char **_split_line(char *line);
void _loop(void);
int builtins(void);
int print_s(char *s);


#define bash_TOK_BUFSIZE 64
#define bash_TOK_DELIM " \t\r\n\a"
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


#endif
