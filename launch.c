#include "main.h"

/**
  * _launch - a program and wait for it to terminate.
  * @args: Null terminated list of arguments (including program).
  * Return: Always returns 1, to continue execution.
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
perror("./shell");
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
