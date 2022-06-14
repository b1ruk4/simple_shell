#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * cd: Is a builtin function.
 * @args: arguments **args.
 * Return: int return value.
 *
 *
 *
 */
int cd(char **args);


/**
 * List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {"cd",
};

int (*builtin_func[]) (char **) = {&cd
};

int _builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}
/**
 * Bultin command: change directory.
 * param args List of args.  args[0] is "cd".  args[1] is the directory.
 * return Always returns 1, to continue executing.
 */
int cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "bash: expected argument to \"cd\"\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("bash");
}
}
return (1);
}
/**
  * Launch a program and wait for it to terminate.
  * param args Null terminated list of arguments (including program).
  * return Always returns 1, to continue execution.
*/
int _launch(char **args)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("bash");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("bash");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
/**
 * Execute shell built-in or launch program.
 * param args Null terminated list of arguments.
 * return 1 if the shell should continue running,
 * 0 if it should terminate
 */
int _execute(char **args)
{
int i;
if (args[0] == NULL)
{
return (1);
}
for (i = 0; i < _builtins(); i++)
{
if (strcmp(args[0], builtin_str[i]) == 0)
{
return ((*builtin_func[i])(args));
}
}
return (_launch(args));
}
/**
 * Read a line of input from stdin.
 * return The line from stdin.
 */
char *_read_line(void)
{
#ifdef bash_USE_STD_GETLINE
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
}
return (line);
#else
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
#endif
}

#define bash_TOK_BUFSIZE 64
#define bash_TOK_DELIM " \t\r\n\a"
/**
  * Split a line into tokens (very naively).
  * param line The line.
  * return Null-terminated array of tokens.
 */
char **_split_line(char *line)
{
int bufsize = bash_TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize *sizeof(char *));
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
/**
  * Loop getting input and executing it.
 */
void _loop(void)
{
char *line;
char **args;
int status;
do {
printf(":) ");
line = _read_line();
args = _split_line(line);
status = _execute(args);
free(line);
free(args);
} while (status);
}
/**
 * Main entry point.
 * argc Argument count.
 * param argv Argument vector.
 * return status code
 */
int main(void)
{
_loop();
return (EXIT_SUCCESS);
}
