#include "main.h"

/**
* exit_cmd - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(EXIT_SUCCESS);
}
