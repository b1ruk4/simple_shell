#include "main.h"

/**
 * handle_builtin - is a function that handles execution of builtin functions
 * @command: tokenized commands from strtok
 * @line: Input read from stdin
 * Return: 1 if executed, 0 if otherwise.
 */

int handle_builtin(char **command)
{
	struct builtin builtin = {"env"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}

	return (0);
}
