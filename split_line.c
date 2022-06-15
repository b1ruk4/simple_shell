#include "main.h"

/**
  * _split_line - into tokens (very naively).
  * @line:The line.
  * Return: return Null-terminated array of tokens.
 */
char **_split_line(char *line)
{
int bufsize = bash_TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token, **tokens_backup;
if (!tokens)
{
fprintf(stderr, "bash: allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(line, bash_TOK_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += bash_TOK_BUFSIZE;
tokens_backup = tokens;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
free(tokens_backup);
fprintf(stderr, "bash: allocation error\n");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, bash_TOK_DELIM);
}
tokens[position] = NULL;
return (tokens);
}
