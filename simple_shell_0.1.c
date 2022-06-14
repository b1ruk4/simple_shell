#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * cd - change dir.
 * **args - permater.
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
