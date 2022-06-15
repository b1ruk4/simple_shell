#include "main.h"
/**
 * cd - input read from stdin
 * cd: change directory.
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: return Always returns 1, to continue executing.
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
 * cd - input read from stdin
 * cd: change directory.
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: return Always returns 1, to continue executing.
 */
int cd(char **args);
char *builtin_str[] = {"cd",
};
int (*builtin_func[]) (char **) = {&cd
};
/**
 * _builtins - calles build in function
 * Return: return int
 */
int _builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * _execute - shell builtin or launch program.
 * @args: Null terminated list of arguments.
 * Return: return 1 if the shell should continue running,
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
