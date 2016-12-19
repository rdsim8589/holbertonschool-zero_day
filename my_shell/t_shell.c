#include "my_shell.h"

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
