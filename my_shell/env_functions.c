#include "my_shell.h"

/**
 * _getenv - get an environmental variable
 * @name: name of environmental variable
 *
 * Return: pointer to the value in the environment, or NULL if no match
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *str;
	size_t i, comp;

	i  = 0;
	while (environ[i])
	{
		str = _strdup(environ[i]);
		str = strtok(str, "=");
		comp = _strcmp(str, name);
		if (comp == 0)
		{
			str = _strdup(strtok(NULL, "\0"));
			return (str);
		}
		i++;
	}
	return (NULL);
}

/**
 * _fork - fork a command while maintaining main process
 * @c: pointer to a pointer to a new command
 * @env: pointer to an array of environmental variables
 *
 * Return: void
 */
void _fork(char **c, char **env)
{
	int i, f;

	f = fork();
	if (f == -1)
		write(2, "Fail", 4);
	/* check for write command failure */
	else if (f == 0)
		execve(c[0], c, env);
	/* check for execve command failure */
	else
		wait(&i);
	return;
}
