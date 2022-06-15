#include "main.h"

/**
 * _loop - loops through the function
 * Return: returns 0.
 */
void _loop(void)
{
char *line;
char **args;
int status;
do {
printf("#cisfun$ ");
line = _read_line();
args = _split_line(line);
status = _execute(args);
free(line);
free(args);
} while (status);
}
