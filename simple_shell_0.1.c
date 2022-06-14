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
