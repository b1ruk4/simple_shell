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

#ifdef DEBUGCD
printf("Got pathbit:%s\n", pathbit);
#endi
if (newptr != newpath && newptr != newpath + 1)
newptr--;
*newptr = 0;
#ifdef DEBUGCD
printf("New path:%s\n", newpath);
#endif
ret = chdir(newpath);

if (ret == 0)
{
_setenv("OLDPWD", oldpwd);
free(oldpwd);
_setenv("PWD", newpath);
if (printpath)
fprintstrs(1, newpath, "\n", NULL);
free(newpath);
return (0);
}
printerr(": cd: can't cd to ");
fprintstrs(STDERR_FILENO, av[1], "\n", NULL);
free(oldpwd);
free(newpath);
return (ret);
}
