#include "main.h"
/**
 * _read_line - of input from stdin.
 * Return: return The line from stdin.
 */
char *_read_line(void)
{
#define bash_RL_BUFSIZE 1024
int bufsize = bash_RL_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;
if (!buffer)
{
fprintf(stderr, "bash: allocation error\n");
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();
if (c == EOF)
{
exit(EXIT_SUCCESS);
}
else if (c == '\n')
{
buffer[position] = '\0';
return (buffer);
}
else
{
buffer[position] = c;
}
position++;
if (position >= bufsize)
{
bufsize += bash_RL_BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
fprintf(stderr, "bash: allocation error\n");
exit(EXIT_FAILURE);
}
}
}
}

[A[3~[3~