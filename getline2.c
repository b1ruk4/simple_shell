#include "shell.h"
/**
 * _getline - gets a line from fd or std input
 * @lineptr: buffer to fill line with
 * @fd: file descriptor
 * Return: num of characters
 */
int _getline(char **lineptr, int fd)
{
	int size = 1025;
	int old_size = 0;
	int r = 1;
	int sum = 0;
	static char buffer[1025];
	static int begin;
	static int end;
	int c = 0;
	int d;		
        for (; buffer[begin]; begin++)
		{
			if (begin == 1024)
			{
				/*free(buffer);*/
				/*(*lineptr)[c] = EOF;*/
				/*return (c);*/
				break;
			}
			/*printf("beginning for\n");//debug check*/
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
		/*printf("j: %d, i:%d, r:%d\n", j, i ,r);*/
}

