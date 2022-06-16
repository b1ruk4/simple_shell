#include "main.h"
/**
 *_cd - change directory builtin
 * @av: argument to work with
 * Return: int
 */
int _cd(char *av[])
{
char *oldpwd = NULL, *newpath, *pathbit, *newptr;
char *homestr = "HOME", *oldpwdstr = "OLDPWD";
int ret, printpath = 0;

newpath = malloc(sizeof(char) * (_strlen(oldpwd) + _strlen(av[1]) + 2));
if (newpath == NULL)
return (-1);
newptr = newpath;
pathbit = oldpwd;
if (av[1][0] != '/' && pathbit[1] != 0)
while (*pathbit)
*newptr++ = *pathbit++;
*newptr++ = '/';
pathbit = strtok(av[1], "/");
#ifdef DEBUGCD
printf("starting newpath:%s:Pathbit got:%s\n", newpath, pathbit);
printf("newpath/ptr diff:%p\n", newptr - newpath);
#endif
while (pathbit != NULL)
{
if (pathbit[0] == '.' && pathbit[1] == '.' && pathbit[2] == 0)
{
#ifdef DEBUGCD
printf("going back a directory%s:%s\n", newpath, newpath);
#endif
newptr--;
if (newptr != newpath)
newptr--;
while (*newptr != '/')
newptr--;
*newptr++ = '/';
}
else if (!(pathbit[0] == '.' && pathbit[1] == 0))
{
while (*pathbit)
*newptr++ = *pathbit++;
*newptr++ = '/';
}
pathbit = strtok(NULL, "/");
}
}
