#include "my_shell.h"

/**
 * _builtin_strcomp - helper function for _builtin; compare two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 *
 * Return: 0 if success, 1 otherwise
 */
int _builtin_strcomp(char *s1, char *s2)
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
 * _builtin - check for builtin commands
 * @command: command being checked
 * @env: pointer to array of environmental variables
 *
 * Return: 1 if builtin, 0 otherwise
 */
int _builtin(char **command, char **env)
{
	if (_bstrcomp(command[0], "exit") == 0)
	{
		_exit(command, env);
		return (1);
	}
	/* add cases for "pwd", "cd", "env" */
	return (0);
}

/**
 * main - my shell
 * @argc: number of arguments
 * @argv: pointer to array of arguments
 * @env: pointer to array of elemental variables
 *
 * Return: 0
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char *argv[],
	 char *env[])
{
	char **command;
	char *line;

	/* read input from stdin */
	while (1)
	{
		write(1, "[MY_SHELL]$ ", 12);
		line = readline(0);
		command = _strtok(line, '#');
		if (*command == NULL)
		{
			_free(command);
			free(line);
			continue;
		}
		command[0] = _strdup(line);
		_free(command);
		command = _strtok(line, ' ');
		if (command[0] == NULL)
		{
			_free(command);
			continue;
		}
		free(line);
		_fork(command, env);
		_free(command);
	}
}
