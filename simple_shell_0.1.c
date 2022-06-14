#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * args - arguments **args.
 * return int return value.
 *
 *  cd - Is a builtin function.
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
