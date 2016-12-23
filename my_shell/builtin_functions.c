#include "my_shell.h"

/**
 * _bstrcomp - helper function for _builtin; compare two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 *
 * Return: 0 if success, 1 otherwise
 */
int _bstrcomp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] >  s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (1);
}

/**
 * _exit - exit out of t_shell
 * @command: pointer to pointer to command
 * @env: pointer to array of environmental variables
 *
 * Return: void
 */
void t_exit(char **command, char ***env)
{
	int argv;
	char **temp;

	temp = *env;
	_free(temp);
	if (_cstrlen(command) <= 1)
	{
		_free(command);
		write(1, "exiting\n", 8);
		exit(0);
	}
	argv = _atoi(command[1]);
	_free(command);
	exit(argv);
}
