#include "main.h"
/**
 * _getline - gets a line from fd or std input
 * @lineptr: buffer to fill line with
 * @fd: fd
 * Return: num of characters
 */
int _getline(char **lineptr, int fd)
{
int size = 1025;
int old_size = 0;
static char buffer[1025];
static int begin;
int c = 0;
for (; buffer[begin]; begin++)
{
if (begin == 1024)
{
break;
}
if (buffer[begin] == '\n')
{
(*lineptr)[c] = '\n';
begin++;
c++;
(*lineptr)[c] = '\0';
return (c);
}
else
{
(*lineptr)[c] = buffer[begin];
}
c++;
}
if (c + begin >= 1024)
{
old_size = size;
size = size + 1024;
*lineptr = _realloc(*lineptr, old_size, size);
if (*lineptr == NULL)
{
return (-1);
}
}
else
{
(*lineptr)[old_size + begin] = 0;
return (c);
}
}
