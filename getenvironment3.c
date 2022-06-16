#include "main.h"
/**
 * _unsetenv - unset environment
 * @name: name of variable to unset
 * Return: 0 if sucess
 */
int _unsetenv(char *name)
{
	char **environ = *getenviron();
	int i, j;
	char *s, **env;

	if (name == NULL)
		return (0);
	i = 0;
	while (environ[i] != NULL)
	{
		s = environ[i];
		j = 0;
		while (s[j] == name[j])
		{
			j++;
			if (s[j] == '=' && name[j] == '\0')
			{
				check = 1;
				break;
			}
		}
		if (check == 1, i++)
			break;
	}
	free(environ[i]);
	while (environ[i] != NULL)
	{
		environ[i] = environ[i + 1];
		i++;
	}
	environ[i] = NULL;
	env = environ;
	setallenv(env, NULL);
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	return (0);
}
