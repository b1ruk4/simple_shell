#include "main.h"

/**
* print_env - prints the environment string to stdout
*
* Return: 0
*/
void print_env(void)
{
	int p = 0;
	char **env = environ;

	while (env[p] != NULL)
	{
		write(STDOUT_FILENO, (const void *)env[p], _strlen(env[p]));
		write(STDOUT_FILENO, "\n", 1);
		p++;
	}
}

