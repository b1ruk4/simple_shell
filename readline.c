#include "main.h"
/**
 * _read_line - of input from stdin.
 * Return: return The line from stdin.
 */
#ifdef bash_USE_STD_GETLINE
char *_read_line(void);
char *line = NULL;
ssize_t bufsize = 0;

if (getline(&line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
exit(EXIT_SUCCESS);
}
else
{
perror("bash: getline\n");
exit(EXIT_FAILURE);
}
return (line);
}
#else
#endif

