#include "my_shell.h"

/**
 * main - my shell
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
		/* write own strtok function to split string */
		command = _strtok(line, ' ');
		_fork(command, env);
		_free(command);
		free(line);
	}
}
